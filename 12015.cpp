#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        printf("Case #%d:\n", t);
        vector<pair<int, string>> website;
        int max_r = INT_MIN;
        for (int i = 0; i < 10; i++)
        {
            string web;
            int r;
            cin >> web >> r;
            max_r = max(max_r, r);
            website.push_back({r, web});
        }
        for (auto &&p : website)
            if (p.first == max_r)
                printf("%s\n", p.second.data());
    }

    return 0;
}
