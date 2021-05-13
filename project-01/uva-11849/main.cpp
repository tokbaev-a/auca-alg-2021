#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    for (int n, m; cin >> n >> m && n + m != 0;)
    {
        unordered_set<int> v;
        int x;

        for (int i = 0; i < n + m; ++i)
        {
            cin >> x;
            v.insert(x);
        }

        cout << (m + n - (int)v.size()) << "\n";
    }
    
}