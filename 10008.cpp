#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, char>> freq(26);
    for (int i = 0; i < 26; i++)
        freq[i] = {0, i + 'A'};
    char chac;
    while (cin >> chac)
        if (isalpha(chac))
            freq[toupper(chac) - 'A'].first++;
    sort(freq.begin(), freq.end(), [](pair<int, char> &p1, pair<int, char> &p2) {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first > p2.first;
    });
    for (auto &&p : freq)
        if (p.first != 0)
            printf("%c %d\n", p.second, p.first);

    return 0;
}
