#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void han(int ball, vector<int> &pegs, int &balls)
{
    if (ball > 2000000)
    {
        return;
    }
    for (int j = 0; j < (int)pegs.size(); j++)
    {
        double x = sqrt(pegs[j] + ball);
        if (pegs[j] == 0 || x - int(x) < 0.0000001)
        {
            if (ball > balls)
            {
                balls = ball;
            }
            pegs[j] = ball;
            han(ball + 1, pegs, balls);
            break;
        }
    }
}

int main()
{
    int tests;
    cin >> tests;
    while (tests--)
    {
        int nPegs;
        cin >> nPegs;

        int balls = 0;
        vector<int> pegs(nPegs);
        han(1, pegs, balls);
        cout << balls << "\n";
    }
}
