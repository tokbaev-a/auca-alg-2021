#include <iostream>
#include "List.hpp"

using namespace std;

void printInDirectOrder(List<int> &v)
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
}

void printInReverseOrder(List<int> &v)
{
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
}

int main()
{
    List<int> v;

    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    printInDirectOrder(v);
    printInReverseOrder(v);

    for (auto i = v.begin(); i != v.end(); i++)
    {
        if (*i % 2 == 0)
        {
            v.insert(i, 0);
        }
    }

    printInDirectOrder(v);
    printInReverseOrder(v);

    for (auto i = v.begin(); i != v.end();)
    {
        if (*i % 2 == 0)
        {
            i = v.erase(i);
        }
        else
        {
            i++;
        }
    }

    printInDirectOrder(v);
    printInReverseOrder(v);
}