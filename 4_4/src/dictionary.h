#ifndef  _DICTIONARY_H_
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>

#include  "hashset.h"
#include  "hashset.cpp"

//using namespace std;

class hash_function {
public:
    hash_function() {}

    unsigned int operator()(const std::string& s) const
    {
        unsigned int A = 1;
        unsigned int B = 0;

        for(int i = 0; i < s.length(); ++i)
        {
            A += s[i];
            B += A;
        }

        //shift
        B = B << 16;

        unsigned int result = B|A;

        return result;
    }
};

class equality {
public:
    equality() {}
    bool  operator()(const std::string& a, const std::string& b)  const
    {
		return  (a == b);
    }
};


class Dictionary: public HashSet<std::string, hash_function, equality>
{
public:
    Dictionary(const string &filename);
};

#endif
