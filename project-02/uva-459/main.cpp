#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class State
{
    White,
    Black
};

void dfs(int v, const vector<vector<int>> &graph, vector<State> &status)
{
    status[v] = State::Black;
    for (auto e : graph[v])
    {
        if (status[e] == State::White)
        {
            dfs(e, graph, status);
        }
    }
}

int main()
{
    int tests;
    cin >> tests;

    string line;
    getchar();
    getline(cin, line);

    for (int test = 0; test < tests; test++)
    {
        getline(cin, line);
        int nVertices = line[0] - 'A' + 1;
        vector<vector<int>> graph(nVertices);

        while (getline(cin, line) && line != "")
        {
            int a = line[0] - 'A';
            int b = line[1] - 'A';
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<State> status(nVertices, State::White);
        int nComponents = 0;
        for (int i = 0; i < nVertices; ++i)
        {
            if (status[i] == State::White)
            {
                ++nComponents;
                dfs(i, graph, status);
            }
        }

        if (test)
        {
            cout << "\n";
        }
        cout << nComponents << "\n";
    }
}
