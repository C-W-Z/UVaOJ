#include <bits/stdc++.h>
using namespace std;

#define MAX_TABLE 20

void print_path(int middle[MAX_TABLE][MAX_TABLE][MAX_TABLE], int t, int i, int j)
{
    if (t == 0)
    {
        printf("%d %d ", i + 1, j + 1);
        return;
    }

    print_path(middle, t - 1, i, middle[t][i][j]);
    printf("%d ", j + 1);
}

int main()
{
    int n; // 2 <= n <= 20
    double rate[MAX_TABLE][MAX_TABLE];

    // max_profit[t][i][j] = the max profit from i to j using t trades
    double max_profit[MAX_TABLE][MAX_TABLE][MAX_TABLE];
    // middle[t][i][j] = the middle currency from i to k for max profit
    int middle[MAX_TABLE][MAX_TABLE][MAX_TABLE];

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            rate[i][i] = 1;
            for (int j = 0; j < n; j++)
                if (i != j)
                    cin >> rate[i][j];
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //         printf("%.2f ", rate[i][j]);
        //     cout << endl;
        // }

        memcpy(max_profit[0], rate, sizeof(rate));

        bool found = false;
        for (int t = 1; t < n; t++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    max_profit[t][i][j] = 0;
                    for (int k = 0; k < n; k++)
                    {
                        double profit = max_profit[t - 1][i][k] * rate[k][j];
                        if (profit > max_profit[t][i][j])
                        {
                            max_profit[t][i][j] = profit;
                            middle[t][i][j] = k;
                        }
                    }
                }
                if (max_profit[t][i][i] > 1.01)
                {
                    found = true;
                    print_path(middle, t - 1, i, middle[t][i][i]);
                    printf("%d\n", i + 1);
                    goto output;
                }
            }
        }

output:
        if (!found)
            cout << "no arbitrage sequence exists\n";
    }

    return 0;
}
