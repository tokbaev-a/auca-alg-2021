#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "HashSetStr.hpp"

using namespace std;

int main()
{
    HashSetStr setOfWords;

    auto hash = defaultHashFunc;

    for (string line; getline(cin, line);)
    {
        istringstream sinp(line);

        cout << "Bucket count: " << setOfWords.bucket_count() << "\n";
        string cmd;
        sinp >> cmd;
        if (cmd == "+")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hash(word) << "\n";
            cout << "bucket's index: " << hash(word) % setOfWords.bucket_count() << "\n";
            auto p = setOfWords.insert(word);
            cout << (p ? "YES" : "NO") << "\n";
        }
        else if (cmd == "?")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hash(word) << "\n";
            cout << "bucket's index: " << hash(word) % setOfWords.bucket_count() << "\n";
            auto isFound = setOfWords.find(word);
            cout << (isFound ? "YES" : "NO") << "\n";
        }
        else if (cmd == "-")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hash(word) << "\n";
            cout << "bucket's index: " << hash(word) % setOfWords.bucket_count() << "\n";
            cout << (setOfWords.erase(word) ? "YES" : "NO") << "\n";
        }
        else if (cmd == "#")
        {
            setOfWords.debugPrint();
        }
    }
}