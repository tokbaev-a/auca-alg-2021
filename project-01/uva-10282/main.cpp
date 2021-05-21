#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    unordered_map<string, string> map; 
    stringstream string_s;
    while (getline(cin, line) && line != "")
    {
        stringstream string_s(line);
        string word, foreign_word;

        string_s >> word >> foreign_word;

     map[foreign_word] = word;
    }
    while (cin >> line)
    {
        auto it = map.find(line);
        if (it != map.end())
        {
            printf("%s\n", map[line].c_str());
        }
        else
        {
            cout << "eh" << endl;
        }
    }
}