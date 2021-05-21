#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, int> map;

    int n;
    while (cin >> n && n != 0)
    {
     map.clear();
        string inp[5];

        for (int i = 0; i < n; i++)
        {
            cin >> inp[0] >> inp[1] >> inp[2] >> inp[3] >> inp[4];
            sort(inp, inp + 5);

            string com;
            for (auto e : inp)
            {
                com += e;
            }
         map[com]++;
        }

        int m = 0;

        for (auto e : map)
        {
            if (e.second > m)
            {
                m = e.second;
            }
        }

        int res = 0;

        for (auto e : map)
        {
            if (e.second == m)
            {
                res += e.second;
            }
        }

        cout << res << endl;
    }
}