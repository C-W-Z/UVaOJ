#include <bits/stdc++.h>
using namespace std;

int main()
{
    uint64_t S, D;
    while (cin >> S >> D)
    {
        uint64_t d = 0;
        while (true)
        {
            d += S;
            if (d >= D)
                break;
            S++;
        }
        printf("%lld\n", S);
    }

    return 0;
}
