#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int n;
        scanf("%d", &n);
        unordered_map<int, set<int>> map;

        for (int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);

            while (m-- > 0)
            {
                int stamp;
                scanf("%d", &stamp);

                auto res = map.insert(make_pair(stamp, set<int>()));
                res.first->second.insert(i);
            }
        }

        int counter = 0;
        vector<int> uniq(n, 0);

        for (auto i = map.begin(); i != map.end(); i++)
        {
            if (i->second.size() == 1)
            {
                counter++;
                uniq[*i->second.begin()]++;
            }
        }

        printf("Case %d:", i);

        if (counter)
        {
            for (int i = 0; i < n; i++)
            {
                printf(" %.6f%%", (double)uniq[i] * 100.0 / (double)counter);
            }
            printf("\n");
        }
    }
}