#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <set>

#include "dictionary.h"

using namespace std;

void lower(string &s);

string stripPunct(const string &s);

void checkSpelling(ifstream &in, Dictionary &dict);


void transposingWords(std::set<string> &set, const string &word);

void removalWords(std::set<string> &set, const string &word);

void replacementWords(std::set<string> &set, const string &word);

void insertingWords(std::set<string> &set, const string &word);


int main(int argc, char* argv[])
{
//    string word = "channce";
//    set<string> words;
//    transposingWords(words, word);
//    removalWords(words, word);
//    replacementWords(words, word);
//    insertingWords(words,word);
//
//    for(std::set<string>::iterator iter = words.begin(); iter != words.end();++iter)
//    {
//        cout << (*iter) << "\n";
//    }

    // Output usage message if improper command line args were given.
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " wordlist_filename input_file\n";
        return EXIT_FAILURE;
    }

    ifstream inf(argv[2]);
    if (!inf)
    {
        cerr << "Could not open " << argv[2] << "\n";
        return EXIT_FAILURE;
    }

    // Read dictionary, but let user know what we are working on.
    cout << "Loading dictionary, this may take awhile...\n";


    Dictionary d(argv[1]);

    checkSpelling(inf, d);

    inf.close();

    return EXIT_SUCCESS;
}

void transposingWords(std::set<string> &set, const string &word)
{
    string applet(word);

    for (int i = 0; i < word.length() - 1; ++i)
    {
        applet[i] += applet[i + 1];
        applet[i + 1] = applet[i] - applet[i + 1];
        applet[i] = applet[i] - applet[i + 1];

        set.insert(applet);

        applet = word;
    }
}

void removalWords(std::set<string> &set, const string &word)
{
    string applet(word);

    for (int i = 0; i < word.length(); ++i)
    {
        applet.erase(i, 1);


        set.insert(applet);
        applet = word;
    }
}

void replacementWords(std::set<string> &set, const string &word)
{
    string applet(word);
    string a_z = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < word.length(); ++i)
    {

        char c = applet[i];
        for (int j = 0; j < a_z.length(); ++j)
        {
            //except origin case
            if (c != a_z[j])
            {
                applet[i] = a_z[j];

                set.insert(applet);
            }
        }

        applet = word;
    }
}

void insertingWords(std::set<string> &set, const string &word)
{
    string applet(word);
    string a_z = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < word.length() + 1; ++i)
    {
        for (int j = 0; j < a_z.length(); ++j)
        {

            applet.insert(i, 1, a_z[j]);

            set.insert(applet);

            applet = word;
        }

        applet = word;
    }
}


void checkSpelling(ifstream &in, Dictionary &dict)
{
    int line_number = 0;

    while (in)
    {
        ++line_number;

        string line;
        getline(in, line);

        stringstream ss(stringstream::in | stringstream::out);
        ss << line;

        string word;
        while (ss >> word)
        {

            lower(word);
            word = stripPunct(word);

            if (!dict.search(word))
            {

                std::set<string> words;

                transposingWords(words, word);
                removalWords(words, word);
                replacementWords(words, word);
                insertingWords(words, word);


                cout << "line " << line_number << ": " << "\'" << word << "\'\n";
                cout << "\t\tsuggestions:\n";



                for (std::set<string>::iterator iter = words.begin(); iter != words.end(); ++iter)
                {
                    if (dict.search(*iter))
                        cout << "\t\t\t" << (*iter) << "\n";
                }

                // TODO: Complete the spell check of each word
            }

        }
    }
}

void lower(string &s)
{
    // Ensures that a word is lowercase
    for (int i = 0; i < s.length(); ++i)
    {
        s[i] = tolower(s[i]);
    }
}

string stripPunct(const string &s)
{
    // Remove any single trailing
    // punctuation character from a word.
    if (ispunct(s[s.length() - 1]))
        return s.substr(0, s.length() - 1);

    return s;
}
