#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include "HashSetStr.hpp"

TEST_CASE("Default constructor")
{
    HashSetStr s;

    REQUIRE(s.size() == 0);
}

std::size_t worstHashFunction(const std::string &s)
{
    return 42;
}

TEST_CASE("Constructor with a custom hash function")
{
    HashSetStr s(worstHashFunction);

    REQUIRE(s.size() == 0);

    s.insert("C++");
    s.insert("C");
    s.insert("Java");
    s.insert("Kotlin");
    s.insert("Pascal");
    s.insert("Python");

    std::cout << "--- Constructor with a custom hash function ---\n";
    s.debugPrint();
}

TEST_CASE("insert()")
{
    HashSetStr s;

    REQUIRE(s.insert("C++"));
    REQUIRE(s.size() == 1);
    REQUIRE_FALSE(s.insert("C++"));

    REQUIRE(s.insert("C"));
    REQUIRE(s.size() == 2);
    REQUIRE_FALSE(s.insert("C"));

    REQUIRE(s.insert("Java"));
    REQUIRE(s.size() == 3);
    REQUIRE_FALSE(s.insert("Java"));

    REQUIRE(s.insert("Python"));
    REQUIRE(s.size() == 4);
    REQUIRE_FALSE(s.insert("Python"));
}

TEST_CASE("erase()")
{
    HashSetStr s;

    s.insert("ABC");
    s.insert("CBA");

    REQUIRE(s.erase("ABC"));
    REQUIRE(s.size() == 1);
    REQUIRE_FALSE(s.insert("CBA"));

    REQUIRE(s.insert("ABC"));
    REQUIRE(s.erase("CBA"));
    REQUIRE(s.size() == 1);

    REQUIRE(s.erase("ABC"));
    REQUIRE(s.size() == 0);
    REQUIRE_FALSE(s.erase("ABC"));
    REQUIRE(s.size() == 0);
}

TEST_CASE("find()")
{
    HashSetStr s;

    s.insert("ABC");
    s.insert("CBA");
    s.insert("XYZ");
    REQUIRE(s.find("ABC"));
    REQUIRE(s.find("CBA"));
    REQUIRE(s.find("XYZ"));
    REQUIRE_FALSE(s.find("ZYX"));
}

TEST_CASE("clear()")
{
    HashSetStr s;

    s.insert("C++");
    s.insert("C");
    s.insert("Java");
    s.insert("Kotlin");
    s.insert("Pascal");
    s.insert("Python");

    s.clear();

    REQUIRE(s.size() == 0);
}