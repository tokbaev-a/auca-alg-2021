#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class State
{
    White,
    Black
};

bool isValid(int r, int c, int n)
{
    return r >= 0 && r < n && c >= 0 && c < n;
}

void dfs(int r, int c, const vector<string> &graph, vector<State> &states, bool &white_wins)
{
    if (c == (int)graph.size() - 1 || white_wins)
    {
        white_wins = true;
        return;
    }

    static const vector<int> dr = {-1, -1, 0, 0, 1, 1};
    static const vector<int> dc = {-1, 0, -1, 1, 0, 1};

    states[r * graph.size() + c] = State::Black;

    for (int i = 0; i < (int)dr.size(); i++)
    {
        int tr = r + dr[i];
        int tc = c + dc[i];
        if (isValid(tr, tc, graph.size()) && graph[tr][tc] == 'w' && states[tr * graph.size() + tc] == State::White)
        {
            dfs(tr, tc, graph, states, white_wins);
        }
    }
}

int main()
{
    int test = 1;
    int n;
    while (cin >> n && n != 0)
    {
        vector<string> graph(n);
        for (int i = 0; i < n; i++)
        {
            cin >> graph[i];
        }

        vector<State> states(n * n);
        bool white_wins = false;

        cout << test++ << " " << (white_wins ? "W" : "B") << "\n";
    }
}
