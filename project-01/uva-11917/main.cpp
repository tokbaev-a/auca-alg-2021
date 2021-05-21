#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int sub;
        scanf("%d", &sub);
        unordered_map<string, int> map;

        for (int j = 0; j < sub; j++)
        {
            string s;
            int d;
            cin >> s >> d;

            map[s] = d;
        }

        int d1;
        scanf("%d", &d1);

        string s;
        cin >> s;

        if (map.find(s) != map.end() && map[s] <= d1)
        {
            printf("Case %d: Yesss\n", i);
        }
        else if (map.find(s) != map.end() && map[s] > d1 && map[s] <= d1 + 5)
        {
            printf("Case %d: Late\n", i);
        }
        else
        {
            printf("Case %d: Do your own map!\n", i);
        }
    }
}