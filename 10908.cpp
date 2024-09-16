#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int M, N, Q;
        cin >> M >> N >> Q;
        printf("%d %d %d\n", M, N, Q);
        vector<vector<char>> grid(M, vector<char>(N));
        for (int m = 0; m < M; m++)
            for (int n = 0; n < N; n++)
                cin >> grid[m][n];
        for (int q = 0; q < Q; q++)
        {
            int r, c;
            cin >> r >> c;
            int size = 1;
            while (true)
            {
                for (int i = r - size; i <= r + size; i++)
                {
                    for (int j = c - size; j <= c + size; j++)
                    {
                        if (i < 0 || j < 0 || i >= M || j >= N)
                            goto end;
                        if (grid[i][j] != grid[r][c])
                            goto end;
                    }
                }
                size++;
            }
        end:
            printf("%d\n", 2 * size - 1);
        }
    }

    return 0;
}
