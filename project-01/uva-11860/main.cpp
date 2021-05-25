#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    scanf("%d", &tests);
    getchar();

    for (int test = 1; test <= tests; ++test)
    {
        unordered_map<string, vector<int>> m;
        vector<string> words;

        int counter = 0;
        int uniques = 0;

        string s;

        while (getline(cin, s) && s != "END")
        {
            string t = "";
            for (const auto &e : s)
            {
                if (e >= 'a' && e <= 'z')
                {
                    t += e;
                }
                else if (t.length() != 0)
                {
                    m[t].push_back(++counter);
                    words.push_back(t);
                    if (m[t].size() == 1)
                    {
                        ++uniques;
                    }
                    t = "";
                }
            }
            if (t.length() != 0)
            {
                m[t].push_back(++counter);
                words.push_back(t);
            }
        }
        vector<pair<int, int>> solutions;
    }
}
