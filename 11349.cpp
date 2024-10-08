#include <bits/stdc++.h>
using namespace std;

bool symmetric(int64_t matrix[128][128], int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix[i][j] < 0 || matrix[i][j] != matrix[N - i - 1][N - j - 1])
                return false;
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    int64_t matrix[128][128];
    for (int t = 0; t < T; t++)
    {
        int N;
        scanf("\nN = %d\n", &N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%lld", &matrix[i][j]);

        if (symmetric(matrix, N))
            printf("Test #%d: Symmetric.\n", t + 1);
        else
            printf("Test #%d: Non-symmetric.\n", t + 1);
    }

    return 0;
}
