#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(const vector<string> &dictionary, const string &rule, const vector<int> &combinations)
{
    for (int i = 0; i < (int)rule.length(); i++)
    {
        if (rule[i] == '0')
        {
            cout << combinations[i];
        }
        else
        {
            cout << dictionary[combinations[i]];
        }
    }
    cout << "\n";
}

void lessgo(int col, const vector<string> &dictionary, const string &rule, vector<int> &combinations)
{
    if (col == (int)rule.length())
    {
        print(dictionary, rule, combinations);
        return;
    }

    if (rule[col] == '0')
    {
        for (int i = 0; i < 10; i++)
        {
            combinations[col] = i;
            lessgo(col + 1, dictionary, rule, combinations);
        }
    }
    else
    {
        for (int i = 0; i < (int)dictionary.size(); i++)
        {
            combinations[col] = i;
            lessgo(col + 1, dictionary, rule, combinations);
        }
    }
}

int main()
{
    int nWords;
    while (cin >> nWords)
    {
        vector<string> dictionary(nWords);
        for (int i = 0; i < nWords; ++i)
        {
            cin >> dictionary[i];
        }

        int nRules;
        cin >> nRules;
        vector<string> rules(nRules);
        for (int i = 0; i < nRules; ++i)
        {
            cin >> rules[i];
        }
        cout << "--\n";

        for (auto &e : rules)
        {
            vector<int> combinations(e.length());
            lessgo(0, dictionary, e, combinations);
        }
    }
}
