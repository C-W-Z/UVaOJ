#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    vector<string> sentences;
    size_t maxlen = 0;
    while (getline(cin, input))
    {
        maxlen = max(maxlen, input.size());
        sentences.push_back(input);
    }
    for (size_t l = 0; l < maxlen; l++)
    {
        for (int i = sentences.size() - 1; i >= 0; i--)
        {
            if (l < sentences[i].size())
                printf("%c", sentences[i][l]);
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
