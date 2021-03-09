#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    unordered_set<string> setOfWords;

    auto hash = setOfWords.hash_function();

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
            cout << (p.second ? "YES" : "NO") << "\n";
        }
        else if (cmd == "?")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hash(word) << "\n";
            cout << "bucket's index: " << hash(word) % setOfWords.bucket_count() << "\n";
            auto it = setOfWords.find(word);
            cout << (it != setOfWords.end() ? "YES" : "NO") << "\n";
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
            for (size_t i = 0; i < setOfWords.bucket_count(); ++i)
            {
                cout << setw(4) << i << ":";
                for (auto p = setOfWords.begin(i); p != setOfWords.end(i); ++p)
                {
                    cout << " " << *p;
                }
                cout << "\n";
            }
        }
    }
}