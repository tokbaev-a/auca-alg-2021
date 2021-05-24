#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &v)
{
    for (auto e : v)
    {
        cout << e;
    }
    cout << "\n";
}

void ham(int i, int h, int ones, vector<int> &v)
{
    if (i == (int)v.size())
    {
        if (ones == h)
        {
            print(v);
        }
        return;
    }
    v[i] = 0;
    ham(i + 1, h, ones, v);
    v[i] = 1;
    ham(i + 1, h, ones + 1, v);
}

int main()
{
    int tests;
    cin >> tests;

    for (int test = 0; test < tests; ++test)
    {
        if (test)
        {
            cout << "\n";
        }

        int n;
        int h;
        cin >> n >> h;

        vector<int> v(n);
        ham(0, h, 0, v);
    }
}
