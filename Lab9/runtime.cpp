#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;

/**
 * @brief returns the first index of elem if it exists, otherwise returns -1
 * iterativeSearch starts at the first indez and iterates sequentially to the next until it either
 * finds the element or until it reaches the end (i.e. elem does not exist)
 * 
 * @param v : vector of elems
 * @param elem : integer to look for
 * @return int
 * 
*/

int iterativeSearch(vector<int>v, int elem){
    for (int i = 0; i < v.size(); i++){
        if (v[i] == elem){
            return i;
        }
    }

    return -1;

}

/**
 * @brief returns the index fo elem, if it exists in v. Otherwise it returns -1.
 * binarySearch is recursive (i.e. function calls itself).
 * It utilizes the fact that v is increasing order (e.g. values go up and
 * duplicates are not allowed).
 * 
 * It calculates the mid from the start and end index. It compares v[mid] (i.e. value
 * at mid) with elem and decides whether to search the left half (lower values)
 * or right half (upper values).
 * 
 * 
 * @param v : vector of elems
 * @param start : leftmost index (starting value is 0)
 * @param end : rightmost index (starting value is v.size())
 * @param elem : integer to look for
 * @return int
*/

int binarySearch(vector<int> & v, int start, int end, int elem){
    // write an if statement that checks the terminating case
    if(start > end){
        return -1;
    }

    // instantiate the midpoint
    int mid = (start + end) / 2;

    // use if/else statements to do the following:
    // 1) update end (search left half)
    // 2) update start (search right half)
    // 3) return mid (found the elem)
    if (v[mid] > elem){
        end = mid - 1;
    } else if (v[mid] < elem){
        start = mid +1;
    } else{
        return mid;
    }

    // return a recursive call to binarySearch(...)
    return binarySearch(v, start, end, elem);

}

/**
 * @brief updates v to contain the valules from filename (leave as is)
 * 
 * it is expected that the files contain values ranging from one to
 * one hundred million in ascending order (no duplicates).
 * 
 * @param filename : string
 * @param v : vector
*/

void vecGen(string filename, vector<int> & v){
    ifstream file(filename);
    int num;
    v.clear();
    while(file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

void writeTimes(string filename, const vector<double> times, const vector<int> n){
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec) " << endl;
    for (int i = 0; i < times.size(); i++){

        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

double average(vector <double> a){
    double average = 0.0;
    double sum = 0.0;
    
    for (int i = 0; i < a.size(); i++){
        sum = sum + a[i];
    }

    average = sum / a.size();
    return average;
}

int main(){
    // test elements to search for
    vector <int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    //n list of numbers
    vector<int> file_sizes;
    vecGen("sizes.csv", file_sizes);

    //n list of numbers
    vector<int>v;

    //results of times
    vector<double> times;

    //results of times
    vector<double> avg;

        for(int i = 0; i < file_sizes.size(); i++){
            
            string filename = to_string(file_sizes[i]) + "_numbers.csv";
            vecGen(filename, v);

            cout << filename << endl;

            times.clear();

            for(int j = 0; j < elem_to_find.size(); j++){
                int elem = elem_to_find[j];

                auto start = chrono::high_resolution_clock::now();
                int index_if_found = iterativeSearch(v, elem);
                auto end = chrono::high_resolution_clock::now(); 

                auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
                double duration_double = std::chrono::duration<double>(duration).count();

                cout << index_if_found << ":" << duration_double << endl;

                times.push_back(duration_double);
            }

            double average_times = average(times);

            times.push_back(average_times);   
        }

        writeTimes("iterativeSearch_Times.csv", times, file_sizes);
        
        avg.clear();

        for(int i = 0; i < file_sizes.size(); i++){
            string filename = to_string(file_sizes[i]) + "_numbers.csv";
            vecGen(filename, v);

            cout << filename << endl;

            times.clear();

            for(int j = 0; j < elem_to_find.size(); j++){
                int elem = elem_to_find[j];

                auto start = chrono::high_resolution_clock::now();
                int index_if_found = binarySearch(v, 0, v.size()-1, elem);
                auto end = chrono::high_resolution_clock::now(); 

                auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
                double duration_double = std::chrono::duration<double>(duration).count();

                cout << index_if_found << ":" << duration_double << endl;

                times.push_back(duration_double);
            }
        }
        
        writeTimes("binarySearch_times.csv", times, file_sizes);
}