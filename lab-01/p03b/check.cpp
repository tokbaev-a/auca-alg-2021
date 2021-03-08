#include <utility>
#include <vector>
#include <iostream>
#include "List.hpp"

using namespace std;

int main()
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    List<int> j;
    j = std::move(v);

    cout << j.size() << " " << j.toStr() << endl;
}