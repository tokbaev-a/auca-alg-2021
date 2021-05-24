#include <iostream>
#include <vector>

using namespace std;

class Solver
{
    vector<int> mRows;
    vector<int> mDiag1;
    vector<int> mDiag2;
    vector<int> mSolution;
    int constCol;
    int nSolutions;

    bool canPutQueen(int r, int c)
    {
        return !mRows[r] && !mDiag1[r + c] && !mDiag2[c - r + 8];
    }

    void putQueen(int r, int c)
    {
        mRows[r] = 1;
        mDiag1[r + c] = 1;
        mDiag2[c - r + 8] = 1;
        mSolution[c] = r + 1;
    }

    void removeQueen(int r, int c)
    {
        mRows[r] = 0;
        mDiag1[r + c] = 0;
        mDiag2[c - r + 8] = 0;
    }

    void print()
    {
        printf("%2d", ++nSolutions);
        cout << "     ";
        for (auto e : mSolution)
        {
            cout << " " << e;
        }
        cout << "\n";
    }

public:
    Solver(int r, int c)
        : constCol(c - 1), nSolutions(0)
    {
        mRows.resize(8);
        mDiag1.resize(15);
        mDiag2.resize(15);
        mSolution.resize(8);
        putQueen(r - 1, c - 1);
    }

    void solve(int col)
    {
        if (col == (int)mSolution.size())
        {
            print();
            return;
        }
        if (col == constCol)
        {
            solve(col + 1);
            return;
        }

        for (int i = 0; i < (int)mSolution.size(); i++)
        {
            if (canPutQueen(i, col))
            {
                putQueen(i, col);
                solve(col + 1);
                removeQueen(i, col);
            }
        }
    }
};

int main()
{
    int tests;
    cin >> tests;

    for (int test = 0; test < tests; ++test)
    {
        if (test)
        {
            cout << "\n";
        }

        int inpRow;
        int inpCol;
        cin >> inpRow >> inpCol;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        Solver x(inpRow, inpCol);
        x.solve(0);
    }
}