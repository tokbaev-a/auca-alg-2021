#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solver
{
    int mn;
    vector<int> mcombinations;
    int msum;

public:
    Solver(int m) : mn(m), msum(0)
    {
        mcombinations.resize(m);
    }

    void solve(size_t c, int sum, vector<int> &v, vector<int> &combinations)
    {
        if (c == v.size())
        {
            if (sum <= mn && sum > msum)
            {
                msum = sum;
                mcombinations = combinations;
            }
        }
        else
        {
            combinations[c] = 0;
            solve(c + 1, sum, v, combinations);
            combinations[c] = 1;
            solve(c + 1, sum + v[c], v, combinations);
        }
    }

    void print(vector<int> &v)
    {
        for (int i = 0; i < (int)mcombinations.size(); ++i)
        {
            if (mcombinations[i] == 1)
            {
                cout << v[i] << " ";
            }
        }
        cout << "sum:" << msum << "\n";
    }
};

int main()
{
    for (int d, n; cin >> d >> n;)
    {
        vector<int> v(n);
        for (auto &e : v)
        {
            cin >> e;
        }
        vector<int> combinations(n);
        Solver x(d);
        x.solve(0, 0, v, combinations);
        x.print(v);
    }
}