#include <iostream>
#include <string>

#include "MapStrInt.hpp"

using namespace std;

int main()
{
    MapStrInt d;

    string s;
    while (cin >> s)
    {
        ++d[s];
    }

    d.printInOrder(cout);
    cout << "size: " << d.size() << endl;

    d.clear();
    cout << "the size of empty map: " << d.size() << endl;

    return 0;
}