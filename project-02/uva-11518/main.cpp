#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(int v, const vector<unordered_set<int>> &dominos, vector<int> &states, int &comps)
{
    states[v] = 1;
    ++comps;
    for (auto e : dominos[v])
    {
        if (states[e] == 0)
        {
            dfs(e, dominos, states, comps);
        }
    }
}

int main()
{
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n;
        int m;
        int l;
        cin >> n >> m >> l;

        vector<unordered_set<int>> dominos(n);
        for (int i = 0; i < m; i++)
        {
            int x;
            int y;
            cin >> x >> y;
            --x;
            --y;
            dominos[x].emplace(y);
        }

        vector<int> states(n, 0);
        int comps = 0;
        for (int i = 0; i < l; i++)
        {
            int x;
            cin >> x;
            if (states[x - 1] == 0)
            {
                dfs(x - 1, dominos, states, comps);
            }
        }

        cout << comps << "\n";
    }
}
