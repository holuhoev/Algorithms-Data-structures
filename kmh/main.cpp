#include <iostream>
#include "kmp.h"
#include <vector>

using namespace std;

int main() {
    string str = "cocacolacococoс0сoco";
    string pattern = "co";

    vector<int>* vector1 = find_substrings(str,pattern);

    for(int i = 0; i < vector1->size();i++)
        cout << vector1 -> at(i) << ' ';

    return 0;
}