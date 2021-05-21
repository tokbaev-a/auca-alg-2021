#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while (t-- > 0)
    {
        int n;
        scanf("%d", &n);

        int m = 0;
        int rep_p = 0;
        int l;
        unordered_map<int, int> map;

        for (int i = 1; i <= n; i++)
        {
            int s;
            scanf("%d", &s);

            int rep = map[s];

            if (s)
            {
             rep_p = max(rep_p, rep);
             l = i - rep_p - 1;
            }

            l++;
            map[s] = i;
            m = max(m, l);
        }

        cout << m << endl;
    }
}