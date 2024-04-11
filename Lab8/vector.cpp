#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints the elements in the vector and their memory locations
 * 
 * @param v - vector of integers
*/

void printMemVec(vector<int> v) {
    printf("Vector - Each int is worth %lu bytes\n")
}

/**
 * @brief increments all of the elements in v by 10
 * 
 * @param v - address to a vector of integers
*/

void incVecBy10() {
    const int SIZE = 10;
    vector<int> v(SIZE);

    for(int i = 0; i < SIZE; i++){
        v.push_back(i + 1);
    }
}

int main() {
    // create constant int called SIZE, value 5

    // create vector of int called vec that can hold up to 5 elem

    printf("Before Increment ----------\n");
    // call printMemVec() on vec

    // call incBy10() on vec

    printf("After Increment------------\n");
    // call printMemVec on vec, view changes

    //remove last elem of vec

    printf("After Pop------------\n");
    // call printMemVec() to view changes

    //append 101 and 102 at the end of vec

    printf("After Push------------\n");
    // call printMemVec() on vec again to view changes

    return 0;
}