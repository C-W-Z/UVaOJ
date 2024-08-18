#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100

int main()
{
    ios::sync_with_stdio();
    cin.tie(NULL);

    int N;
    int rect[MAX_N + 1][MAX_N + 1] = {{0}};

    while (cin >> N)
    {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                cin >> rect[i][j];

        int max_sum = INT_MIN;

        for (int i = 2; i <= N; i++)
            for (int j = 1; j <= N; j++)
                rect[i][j] += rect[i - 1][j];

        for (int i = 1; i <= N; i++)
            for (int j = 2; j <= N; j++)
                rect[i][j] += rect[i][j - 1];

        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
            {
                for (int x = max(i, 1); x <= N; x++)
                    for (int y = max(j, 1); y <= N; y++)
                    {
                        if (x == i && y == j)
                            continue;
                        if (x == i || y == j)
                            max_sum = max(max_sum, rect[x][y] - rect[i][j]);
                        else
                            max_sum = max(max_sum, rect[x][y] - rect[x][j] - rect[i][y] + rect[i][j]);
                    }
            }

        cout << max_sum << endl;
    }

    return 0;
}