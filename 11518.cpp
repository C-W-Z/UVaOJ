#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &falls, vector<vector<int>> &next, int knock)
{
    falls[knock] = true;
    for (int d : next[knock])
        if (!falls[d])
            dfs(falls, next, d);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n, m, l;
        cin >> n >> m >> l;
        vector<bool> falls(n + 1, false);
        vector<vector<int>> next(n + 1, vector<int>());
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            next[x].push_back(y);
        }
        for (int i = 0; i < l; i++)
        {
            int knock;
            cin >> knock;
            dfs(falls, next, knock);
        }
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (falls[i])
                count++;
        }
        printf("%d\n", count);
    }

    return 0;
}
