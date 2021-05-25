#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int r, int c, vector<string> &graph)
{
    static const vector<int> dr = {0, 1, 0, -1};
    static const vector<int> dc = {1, 0, -1, 0};
    graph[r][c] = '#';

    for (int i = 0; i < (int)dr.size(); i++)
    {
        int tr = r + dr[i];
        int tc = c + dc[i];
        if (graph[tr][tc] == ' ')
        {
            dfs(tr, tc, graph);
        }
    }
}

void print(const vector<string> &graph)
{
    for (const auto &e : graph)
    {
        cout << e << "\n";
    }
}

int main()
{
    string line;
    getline(cin, line);

    int tests = stoi(line);

    while (tests--)
    {
        vector<string> graph;
        int startr;
        int startc;
        while (getline(cin, line) && line[0] != '_')
        {
            graph.push_back(line);
            int t = line.find('*');
            if (t != (int)string::npos)
            {
                startr = graph.size() - 1;
                startc = t;
            }
        }
        graph.push_back(line);

        dfs(startr, startc, graph);

        print(graph);
    }
}
