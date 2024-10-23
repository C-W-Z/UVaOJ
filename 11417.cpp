#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gcds(501, vector<int>(501, 0));

int gcd(int a, int b)
{
    if (!(a & 1) && !(b & 1) && gcds[a >> 1][b >> 1] != 0)
        return gcds[a >> 1][b >> 1] << 1;
    if (!(a & 1) && (b & 1) && gcds[a >> 1][b] != 0)
        return gcds[a >> 1][b];
    if ((a & 1) && !(b & 1) && gcds[a][b >> 1] != 0)
        return gcds[a][b >> 1];

    while (b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
    for (int i = 1; i <= 500; i++)
    {
        gcds[i][i] = i;
        for (int j = i + 1; j <= 500; j++)
        {
            if (gcds[i][j] == 0)
                gcds[i][j] = gcds[j][i] = gcd(i, j);
        }
    }
    int N;
    while (cin >> N)
    {
        if (N == 0)
            break;
        int G = 0;
        for(int i = 1; i < N; i++)
        for(int j = i + 1; j <= N; j++)
            G += gcds[i][j];
        printf("%d\n", G);
    }

    return 0;
}
