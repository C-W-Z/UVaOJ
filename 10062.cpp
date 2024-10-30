#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool first = true;
    string line;
    while (getline(cin, line))
    {
        if (!first)
            printf("\n");
        first = false;
        vector<pair<int, char>> freq(130);
        for (int i = 0; i < 128; i++)
            freq[i] = {0, i};

        for (auto &&c : line)
        {
            if (c == '\r')
                continue;
            freq[c].first++;
        }
        sort(freq.begin(), freq.end(), [](pair<int, char> &a, pair<int, char>&b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        for (int i = 0; i < 130; i++)
        {
            if (freq[i].first == 0)
                continue;
            printf("%d %d\n", freq[i].second, freq[i].first);
        }
    }

    return 0;
}
