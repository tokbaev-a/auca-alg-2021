#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, g;
    scanf("%d %d", &p, &g);

    unordered_map<string, int> map;
    
    cin.ignore();
    string s;
    for (int i = 1; i <= g; i++)
    {
        getline(cin, s);
        stringstream ss(s);

        int sum = 0;
        string name, sign;
        do
        {
            ss >> name >> sign;
            sum += map[name];
        } while (sign == "+");

        int vrag;
        ss >> vrag;
        vrag *= 10;
        if (sum == vrag)
        {
            if (sign.find("=") != string::npos)
            {
                printf("Guess #%d was correct.\n", i);
            }
            else
            {
                printf("Guess #%d was incorrect.\n", i);
            }
        }
        else if (sum > vrag)
        {
            if (sign.find(">") != string::npos)
            {
                printf("Guess #%d was correct.\n", i);
            }
            else
            {
                printf("Guess #%d was incorrect.\n", i);
            }
        }
        else if (sum < vrag)
        {
            if (sign.find("<") != string::npos)
            {
                printf("Guess #%d was correct.\n", i);
            }
            else
            {
                printf("Guess #%d was incorrect.\n", i);
            }
        }
    }
}