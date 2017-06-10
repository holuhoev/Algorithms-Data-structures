#include "dictionary.h"

#include <iostream>
#include <fstream>

using namespace std;

Dictionary::Dictionary(const string &file)
{
    ifstream in;

    // Open wordlist file
    in.open (file.c_str());

    if (!in)
        throw invalid_argument("Couldn't open file");

    // Load wordlist into hashset
    while (1) {
        string word;

        in >> word;

        insert(word);

        if (in.eof())
            break;
    }
}
