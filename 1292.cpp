#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g, vector<vector<int>> &dp, int cur)
{
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for (auto &&v : g[cur])
    {
        if (dp[v][0] != -1) // visited
            continue;
        dfs(g, dp, v);
        dp[cur][0] += dp[v][1]; // if cur no soldier, v must put soldier
        dp[cur][1] += min(dp[v][0], dp[v][1]); // otherwise v can put or not
    }
}

int main()
{
    int N; // 0 < N <= 1500
    while (scanf("%d", &N) != EOF)
    {
        vector<vector<int>> g(N);
        for (int n = 0; n < N; n++)
        {
            int id, n_road;
            scanf("%d:(%d)", &id, &n_road);
            for (int i = 0; i < n_road; i++)
            {
                int child_id;
                scanf("%d", &child_id);
                g[id].push_back(child_id);
                g[child_id].push_back(id);
            }
        }
        // dp[u][0] for put soldier at u, dp[u][1] for no soldier at u
        vector<vector<int>> dp(N, vector<int>(2, -1));
        dfs(g, dp, 0);
        printf("%d\n", min(dp[0][0], dp[0][1]));
    }

    return 0;
}
