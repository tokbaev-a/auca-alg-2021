#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    unordered_map<string, int> map;

    while (m--)
    {
        string s;
        int num;
        cin >> s >> num;
        map[s] = num;
    }

    while (n-- > 0)
    {
        int res = 0;

        for (string w; cin >> w && w != ".";)
        {
            if (map.find(w) != map.end())
            {
                res += map[w];
            }
        }

        cout << res << endl;
    }
}