#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000000

bool coprime(int a, int b)
{
    while (b > 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a <= 1;
}

int main()
{
    ios::sync_with_stdio();
    cin.tie(NULL);

    bool found[MAX_N + 1];

    int N;
    while (cin >> N)
    {
        int sqrt_N = sqrt(N);
        int prime_tuple = 0;
        memset(found, false, N + 1);
        // Pythagorean triple
        // m > n && m, n are coprime && exactly one of them is even
        for (int n = 1; n <= sqrt_N; n++)
        {
            for (int m = n + 1; m <= N; m += 2)
            {
                if (!coprime(m, n))
                    continue;
                int x = m * m - n * n;
                int y = 2 * m * n;
                int z = m * m + n * n;
                if (x > N || y > N || z > N)
                    break;
                prime_tuple++;
                int X = x, Y = y, Z = z;
                // printf("[%d %d] %d %d %d\n", m, n, x, y, z);
                while (X <= N && Y <= N && Z <= N)
                {
                    found[X] = found[Y] = found[Z] = true;
                    X += x;
                    Y += y;
                    Z += z;
                }
            }
        }
        int no_tuple = 0;
        for (int i = 1; i <= N; i++)
            if (!found[i])
                no_tuple++;
        printf("%d %d\n", prime_tuple, no_tuple);
    }
    return 0;
}
