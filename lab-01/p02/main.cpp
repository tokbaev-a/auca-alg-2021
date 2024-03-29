#include <iostream>
#include <list>

using namespace std;

void printInDirectOrder(const list<int> &v)
{
    // for(auto e : v)
    // {
    //     cout << " " << e;
    // }
    // cout << endl;

    for(auto i = v.begin(); i != v.end(); ++i)
    {
        cout << " " << *i;
    }
    cout << endl;
}

void printInReverseOrder(const list<int> &v)
{
    for(auto i = v.rbegin(); i != v.rend(); ++i)
    {
        cout << " " << *i;
    }
    cout << endl;
}

int main()
{
    list<int> v;

    for(int x; cin >> x;)
    {
        v.push_back(x);
    }

    printInDirectOrder(v);
    printInReverseOrder(v);

    for(auto i = v.begin(); i != v.end(); ++i)
    {
        if(*i % 2 == 0)
        {
            v.insert(i, 0);
        }
    }

    printInDirectOrder(v);
    printInReverseOrder(v);

    for(auto i = v.begin(); i != v.end();)
    {
        if(*i % 2 == 0)
        {
            i = v.erase(i);
        }
        else 
        {
            ++i;
        }
    }

    printInDirectOrder(v);
    printInReverseOrder(v);

    v.clear();

    printInDirectOrder(v);
    printInReverseOrder(v);
}