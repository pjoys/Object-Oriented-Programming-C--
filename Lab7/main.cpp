#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief writes sample_size number of integers
 * example output: if n = 3 and arr = [1,2,3]
 * 1
 * 2
 * 3
 * 
 * @param filename
 * @param arr
 * @param sample_size
*/

void writeToFile(string filename, int * arr, int sample_size){
    ofstream file(filename);
    int val;

    for(int i = 0; i< sample_size; i++) {
        file << arr[i];
        file << "\n";
    }

    file.close();
    printf("Wrote to %s\n", filename.c_str());
};


/**
 * @brief writes sample_size number of strings
 * example output: if n = 2 and arr = ["cat","dog"]
 * cat
 * dog
 * 
 * @param filename
 * @param arr
 * @param sample_size
*/

void writeToFile(string filename, string * arr, int sample_size){
    ofstream file(filename);
    int val;

    for(int i = 0; i< sample_size; i++) {
        file << arr[i];
        file << "\n";
    }

    file.close();
    printf("Wrote to %s\n", filename.c_str());};


/**
 * @brief writes sample_size number of char
 * example output: if n = 2 and arr = ["c","d"]
 * c
 * d
 * 
 * @param filename
 * @param arr
 * @param sample_size
*/

void writeToFile(string filename, char * arr, int sample_size){
    ofstream file(filename);
    int val;

    for(int i = 0; i< sample_size; i++) {
        file << arr[i];
        file << "\n";
    }

    file.close();
    printf("Wrote to %s\n", filename.c_str());
};


/**
 * @brief reads the content of any file
 * 
 * @param filename
*/

void readFile(string filename){
    fstream file(filename);

    if(file.is_open()) {
        string line;
        while(getline(file, line)){
            cout << line << endl;
        }
    } else {
        file.close();
    }
};

int main(){
    const int SAMPLE_SIZE = 10;
    int array_int[SAMPLE_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    string array_str[SAMPLE_SIZE] = {"This", "is", "a", "sentence. ",
                                "This", "is", "another", "sentence.", 
                                "The", "end."};

    char array_char[SAMPLE_SIZE] = {'a', 'b', 'c', 'd', 'e', '0', '1', '2', '3', '4'};

    string int_file = "array_int.csv";

    writeToFile(int_file, array_int, SAMPLE_SIZE); // arr is pointer

    // do the same for the other arrays

    // create a string var as the filename and assign "array_str.csv", call writeToFile
    string str_file = "array_str.csv";
    writeToFile(str_file, array_str, SAMPLE_SIZE);

    // create string var as the filename and assign "array_char.csv", call writeToFile
    string char_file = "array_char.csv";
    writeToFile(char_file, array_char, SAMPLE_SIZE);

    // call readFile() on all 3 generated files
    readFile(int_file);
    readFile(str_file);
    readFile(char_file);

    return 0;

}