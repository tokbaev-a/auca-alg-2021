#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPunctuation(char c, vector<char> &punctuation)
{
    for (const auto &e : punctuation)
    {
        if (c == e)
        {
            return true;
        }
    }
    return false;
}

double entropy(int nWords, unordered_map<string, int> &m)
{
    double res = 0;
    double lambda = log10(nWords);
    for (const auto &e : m)
    {
        res += (lambda - log10(e.second)) * e.second;
    }

    return res / nWords;
}

int main()
{
    vector<char> punctuation = {',', '.', ':', ';', '!', '?', '\"', '(', ')'};
    string line;
    while (getline(cin, line) && line != "****END_OF_INPUT****")
    {
        unordered_map<string, int> m;
        int nWords = 0;

        while (line != "****END_OF_TEXT****")
        {
            istringstream inp(line);
            string word;
            while (inp >> word)
            {
                string t = "";
                for (int i = 0; i < word.length(); ++i)
                {
                    if (!isPunctuation(word[i], punctuation))
                    {
                        t += tolower(word[i]);
                    }
                    else if (t != "")
                    {
                        ++nWords;
                        ++m[t];
                        t = "";
                    }
                }
                if (t.length() != 0)
                {
                    ++nWords;
                    ++m[t];
                }
            }

            getline(cin, line);
        }
        double textEntropy = entropy(nWords, m);
        double relEntropy = textEntropy / log10(nWords) * 100;

        printf("%d %.1f %.0f\n", nWords, textEntropy, relEntropy);
    }
}