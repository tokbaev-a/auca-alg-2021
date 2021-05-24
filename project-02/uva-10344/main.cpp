#include <iostream>
#include <vector>

using namespace std;

void calc(const vector<int> &v, int i, int res, bool &possibility)
{
    if (i == 4)
    {
        if (res == 23)
        {
            possibility = true;
        }
        return;
    }

    calc(v, i + 1, res + v[i + 1], possibility);
    calc(v, i + 1, res - v[i + 1], possibility);
    calc(v, i + 1, res * v[i + 1], possibility);
}

void shuffle(int i, vector<int> &v, vector<int> &c, vector<bool> &taken, bool &possibility)
{
    if (i == v.size())
    {
        if (possibility)
        {
            return;
        }
        calc(c, 0, c[0], possibility);
        return;
    }
    for (int j = 0; j < v.size(); j++)
    {
        if (!taken[j])
        {
            taken[j] = true;
            c[i] = v[j];
            shuffle(i + 1, v, c, taken, possibility);
            taken[j] = false;
        }
    }
}

int main()
{
    vector<int> nums(5);
    while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4] && (nums[0] + nums[1] + nums[2] + nums[3] + nums[4]) != 0)
    {
        bool possibility = false;
        vector<int> combinations(5);
        vector<bool> taken(5);
        shuffle(0, nums, combinations, taken, possibility);

        if (possibility)
        {
            cout << "Possible\n";
        }
        else
        {
            cout << "Impossible\n";
        }
    }
}
