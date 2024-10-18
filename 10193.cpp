#include <bits/stdc++.h>
using namespace std;

uint64_t b2d(string &b)
{
    uint64_t d = 0;
    for (size_t i = 0; i < b.size(); i++)
        d = (d << 1) + (b[i] - '0');
    return d;
}

uint64_t gcd(uint64_t a, uint64_t b)
{
    while (b != 0)
    {
        uint64_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        string b1, b2;
        cin >> b1 >> b2;
        uint64_t a = b2d(b1);
        uint64_t b = b2d(b2);
        if (gcd(a, b) > 1)
            printf("Pair #%d: All you need is love!\n", t + 1);
        else
            printf("Pair #%d: Love is not all you need!\n", t + 1);
    }

    return 0;
}
