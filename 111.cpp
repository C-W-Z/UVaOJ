#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; // 2 <= n <= 20
    char line[64];
    cin.getline(line, 64);
    while (!cin.eof())
    {
        sscanf(line, "%d", &n);

        int tmp;
        vector<int> correct_order(n + 1);
        cin.getline(line, 64);
        char *data = line;
        int offset;
        for (int i = 1; i <= n; i++)
        {
            sscanf(data, "%d%n", &tmp, &offset);
            data += offset;
            correct_order[tmp] = i;
        }

        // for (int i = 1; i <= n; i++)
        //     printf("%d ", correct_order[i]);
        // printf("\n");

        vector<int> order(n + 1);
        while (cin.getline(line, 64))
        {
            if (strlen(line) <= 2)
                break;
            data = line;
            for (int i = 1; i <= n; i++)
            {
                sscanf(data, "%d%n", &tmp, &offset);
                data += offset;
                order[tmp] = i;
            }

            // for (int i = 1; i <= n; i++)
            //     printf("%d ", order[i]);
            // printf("\n");

            // LCS (Longest Common Subsequence)
            vector<vector<int>> lcs(n + 1, vector<int>(n + 1, 0));
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (order[i] == correct_order[j])
                        lcs[i][j] = lcs[i - 1][j - 1] + 1;
                    else
                        lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
                }
            }

            printf("%d\n", lcs[n][n]);
        }
    }

    return 0;
}
