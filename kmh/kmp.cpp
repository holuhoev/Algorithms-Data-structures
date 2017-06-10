#include "kmp.h"
#include <iostream>

using namespace std;

/**
 * Function for create array for substring in KMP algoritm
 * @param substring
 * @return array of prefix indexes
 */
int* buildArray(string substring){
    int* arr = new int[substring.length()];

    int j = 0;
    arr[j] = 0;

    for(int i = 1; i < substring.length();i++){
        if(substring[i] == substring[j]) {
            int value = j + 1;
            arr[i] = value;
            j++;
        }
        else {
            j = (j == 0? 0 :arr[j - 1]);
            arr[i] = j;
        }
    }

    return arr;
}

std::vector<int> *find_substrings(string &source, string &substring) {
    int* arr = buildArray(substring) ; // array for prefix
    vector<int>* startIndexes = new vector<int>;

    int j = 0; // index point to substring char

    for(int i = 0; i < source.length();i++){
        if(source[i] == substring[j]){
            j++;
            if(j == substring.length()) {
                j = arr[j - 1];
                startIndexes->push_back(i - (int)substring.length()+1);
            }
        }
        else{
            if(substring[j-1] == source[i-1])
                i--;
            j = (j == 0? 0 :arr[j - 1]);;
        }
    }

    delete[] arr;

    return startIndexes;
}


