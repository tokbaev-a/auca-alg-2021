#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;

    Point(int ax, int ay)
        : x(ax), y(ay)
    {
    }
};

struct CmpPoints
{
    bool operator()(const Point &a, const Point &b) const
    {
        if (a.x == b.x)
        {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
};

void eraseCache(map<Point, vector<string>, CmpPoints> &d, int x, int y)
{
}

int main()
{
    map<Point, vector<string>, CmpPoints> d;

    for (string line; getline(cin, line);)
    {
        istringstream sinp(line);
        string cmd;
        sinp >> cmd;
        int x;
        int y;

        if (cmd == "insert")
        {
            sinp >> x >> y;

            string s;
            while (sinp >> s)
            {
                d[{x, y}].push_back(s);
            }
        }
        else if (cmd == "erase")
        {
            sinp >> x >> y;
            cout << (d.erase({x, y}) ? "removed\n" : "not found\n");
        }
        else if (cmd == "check")
        {
            sinp >> x >> y;
            auto it = d.find({x, y});
            if (it != d.end())
            {
                cout << x << ", " << y << " :";
                for (const auto &e : d[{x, y}])
                {
                    cout << " " << e;
                }
                cout << "\n";
            }
            else
            {
                cout << "not found\n";
            }
        }
        else if (cmd == "print")
        {
            for (const auto &k : d)
            {
                cout << k.first.x << ", " << k.first.y << " :";
                for (const auto &e : k.second)
                {
                    cout << " " << e;
                }
                cout << "\n";
            }
        }
    }
}
