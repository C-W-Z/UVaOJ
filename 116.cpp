#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    while (cin >> m >> n)
    {
        vector<vector<int>> dp(m, vector<int>(n));
        vector<vector<int>> next(m, vector<int>(n));

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                cin >> dp[r][c];

        for (int c = n - 1; c >= 1; c--)
        {
            for (int r = 0; r < m; r++)
            {
                int min_w = min(dp[r][c], min(dp[(r + 1) % m][c], dp[(r - 1 + m) % m][c]));

                if (r + 1 == m && dp[0][c] == min_w)
                    next[r][c - 1] = 0;
                else if (r >= 1 && dp[r - 1][c] == min_w)
                    next[r][c - 1] = r - 1;
                else if (dp[r][c] == min_w)
                    next[r][c - 1] = r;
                else if (dp[(r + 1) % m][c] == min_w)
                    next[r][c - 1] = (r + 1) % m;
                else
                    next[r][c - 1] = (r - 1 + m) % m;

                dp[r][c - 1] += min_w;
            }
        }

        int min_weight = INT_MAX, min_r = 0;
        for (int r = 0; r < m; r++)
        {
            if (dp[r][0] < min_weight)
            {
                min_weight = dp[r][0];
                min_r = r;
            }
        }

        for (int c = 0; c < n - 1; c++)
        {
            printf("%d ", min_r + 1);
            min_r = next[min_r][c];
        }
        printf("%d\n", min_r + 1);
        printf("%d\n", min_weight);
    }

    return 0;
}
