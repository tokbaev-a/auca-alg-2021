#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, string> map;
    string part1, part2;
    cin.ignore();

    while (n-- > 0)
    {
        getline(cin, part1);
        getline(cin, part2);

        map[part1] = part2;
    }

    int n1;
    cin >> n1;
    cin.ignore();

    while (n1-- > 0)
    {
        string sl;
        getline(cin, sl);

        cout << map[sl] << endl;
    }
}