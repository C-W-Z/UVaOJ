#include <bits/stdc++.h>
using namespace std;

// __builtin_popcount(n)
int count1(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return count;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        printf("%d ", count1(M));
        int hex = 0;
        while (M > 0)
        {
            hex = hex * 16 + M % 10;
            M /= 10;
        }
        printf("%d\n", count1(hex));
    }

    return 0;
}
