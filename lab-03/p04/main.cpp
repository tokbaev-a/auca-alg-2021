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

    d.printInOrder();

    return 0;
}
