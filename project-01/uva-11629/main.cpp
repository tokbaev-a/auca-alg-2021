#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, g;
    scanf("%d %d", &p, &g);

    unordered_map<string, int> map;
    while (p-- > 0)
    {
        string s;
        int first_num, second_num;
        char tmp_ch;
        cin >> s >> first_num >> tmp_ch >> second_num;

        map[s] = first_num * 10 + second_num;
    }
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