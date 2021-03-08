#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include <utility>

#include "List.hpp"

TEST_CASE("List constructor")
{
    List<int> v;

    REQUIRE(v.size() == 0);
}

TEST_CASE("List copy constructor")
{
    List<int> v;

    REQUIRE(v.size() == 0);

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");

    List<int> j = v;

    REQUIRE(j.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");

    v.popBack();

    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{1, 2}");
    REQUIRE(j.size() == 3);
    REQUIRE(j.toStr() == "{1, 2, 3}");
}

// TEST_CASE("List move constructor")
// {
//     List<int> v;

//     v.pushBack(1);
//     v.pushBack(2);
//     v.pushBack(3);

//     List<int> j = std::move(v);

//     REQUIRE(j.size() == 3);
//     REQUIRE(j.toStr() == "{1, 2, 3}");
// }

TEST_CASE("Copy assignment operator")
{
    List<int> v;

    REQUIRE(v.size() == 0);

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");

    List<int> j;

    j = v;

    REQUIRE(j.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");

    v.popBack();

    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{1, 2}");
    REQUIRE(j.size() == 3);
    REQUIRE(j.toStr() == "{1, 2, 3}");
}

// TEST_CASE("Move assignment operator")
// {
//     List<int> v;

//     REQUIRE(v.size() == 0);

//     v.pushBack(1);
//     v.pushBack(2);
//     v.pushBack(3);

//     REQUIRE(v.size() == 3);
//     REQUIRE(v.toStr() == "{1, 2, 3}");

//     // List<int> j;
//     // j = std::move(v);

//     // REQUIRE(j.size() == 3);
//     // REQUIRE(j.toStr() == "{1, 2, 3}");

//     // REQUIRE(v.size() == 0);
//     // REQUIRE(v.toStr() == "{}");
//     // REQUIRE(j.size() == 3);
//     // REQUIRE(j.toStr() == "{1, 2, 3}");
// }

TEST_CASE("pushBack")
{
    List<int> v;

    REQUIRE(v.toStr() == "{}");
    REQUIRE(v.toReverseStr() == "{}");

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");
    REQUIRE(v.toReverseStr() == "{3, 2, 1}");
}

TEST_CASE("popBack")
{
    List<int> v;

    REQUIRE(v.toStr() == "{}");

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    int t = v.popBack();

    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{1, 2}");
    REQUIRE(t == 3);

    t = v.popBack();

    REQUIRE(v.size() == 1);
    REQUIRE(v.toStr() == "{1}");
    REQUIRE(t == 2);

    t = v.popBack();

    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
    REQUIRE(t == 1);
}

TEST_CASE("pushFront")
{
    List<int> v;

    REQUIRE(v.toStr() == "{}");

    v.pushFront(1);
    v.pushFront(2);
    v.pushFront(3);

    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{3, 2, 1}");
    REQUIRE(v.toReverseStr() == "{1, 2, 3}");
}

TEST_CASE("popFront")
{
    List<int> v;

    REQUIRE(v.toStr() == "{}");

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    int t = v.popFront();

    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{2, 3}");
    REQUIRE(t == 1);

    t = v.popFront();

    REQUIRE(v.size() == 1);
    REQUIRE(v.toStr() == "{3}");
    REQUIRE(t == 2);

    t = v.popFront();

    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
    REQUIRE(t == 3);
}

TEST_CASE("List<int>::Iter")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.begin();

    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
    ++it;
    REQUIRE(it == v.end());

    --it;
    REQUIRE(*it == 3);
    --it;
    REQUIRE(*it == 2);
    --it;
    REQUIRE(*it == 1);
    REQUIRE(it == v.begin());

    std::ostringstream out;
    for (auto e : v)
    {
        out << " " << e;
    }

    REQUIRE(out.str() == " 1 2 3");

    std::reverse(v.begin(), v.end());
    REQUIRE(v.toStr() == "{3, 2, 1}");
}

TEST_CASE("List<pair<int, int>>::Iter")
{
    List<std::pair<int, int>> v;

    v.pushBack({1, 1});
    v.pushBack({2, 2});
    v.pushBack({3, 3});

    auto it = v.begin();

    REQUIRE(it->first == 1);
    ++it;
    REQUIRE(it->first == 2);
    ++it;
    REQUIRE(it->first == 3);
    ++it;
    REQUIRE(it == v.end());

    --it;
    REQUIRE(it->second == 3);
    --it;
    REQUIRE(it->second == 2);
    --it;
    REQUIRE(it->second == 1);
    REQUIRE(it == v.begin());
}

TEST_CASE("List<pair<int, int>>::RIter")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.rbegin();

    REQUIRE(*it == 3);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(it == v.rend());

    --it;
    REQUIRE(*it == 1);
    --it;
    REQUIRE(*it == 2);
    --it;
    REQUIRE(*it == 3);
    REQUIRE(it == v.rbegin());

    std::reverse(v.rbegin(), v.rend());
    REQUIRE(v.toStr() == "{3, 2, 1}");
}

TEST_CASE("insert()")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto p = v.begin();
    ++p;

    p = v.insert(p, 0);
    REQUIRE(v.size() == 4);
    REQUIRE(v.toStr() == "{1, 0, 2, 3}");
    REQUIRE(*p == 0);
}

TEST_CASE("erase()")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto p = v.begin();
    ++p;

    p = v.erase(p);

    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{1, 3}");
    REQUIRE(*p == 3);

    p = v.erase(p);

    REQUIRE(v.size() == 1);
    REQUIRE(v.toStr() == "{1}");
    REQUIRE(p == v.end());

    --p;
    p = v.erase(p);
    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
    REQUIRE(p == v.end());
}

TEST_CASE("clear()")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    REQUIRE(v.size() == 3);
    v.clear();
    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
}