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

template<typename T>
int iterativeSearch(vector<T>v, T elem){
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

template<typename T>
int binarySearch(vector<T> &v, int startIndex, int endIndex, T elem){
    if (startIndex > endIndex){
        return -1;
    }

    int mid = (startIndex + endIndex) / 2;

    if (v[mid] > elem) {
        endIndex = mid - 1;
    }

    else if (v[mid] < elem) {
        startIndex = mid + 1;
    }

    else {
        return mid;
    }

    return binarySearch(v, startIndex, endIndex, elem);
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

template<typename T>
void vecGen(string filename, vector<T> & v){
    ifstream file(filename);
    T num;
    v.clear();
    while (file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

int main(){
    // populate v with 10,000 sorted numbers (leave as is)
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    // test elements to search for (leave as is)
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    // reads through all 10 of the test_elem values and calls iterative search
    // and records how long each search took (leave as is)
    for(int i = 0; i < elem_to_find.size(); i++){

        // gets the elem to search for
        int elem = elem_to_find[i];

       auto start = chrono::high_resolution_clock::now();
       int index_if_found = iterativeSearch(v, elem);
       auto end = chrono::high_resolution_clock::now();

       auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

        // prints the index and how long it took to find it
        cout << index_if_found << ": " << duration.count() << "microseconds" << endl;
    }

    cout << "\nBinary Search\n" << endl;


    vector<double> d;
    vecGen("1000_double.csv", d);
    vector<double> double_to_find;
    vecGen("double_to_find.csv", double_to_find);

    for(int i = 0; i < double_to_find.size(); i++){
        double elem = double_to_find[i];

        auto start = chrono::high_resolution_clock::now();
        int index_if_found = binarySearch(d, 0, d.size()-1, elem);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
    }



}