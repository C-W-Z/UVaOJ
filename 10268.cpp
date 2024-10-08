#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x;
    while (scanf("%lld", &x) != EOF)
    {
        vector<long long> p;
        while (true)
        {
            long long c;
            scanf("%lld", &c);
            p.push_back(c);
            char tmp = getchar();
            if (tmp == '\n' || tmp == EOF)
                break;
        }
        long long ans = 0;
        long long n = p.size() - 1;
        for (long long i = 0; i < n; i++)
            ans = ans * x + p[i] * (n - i);
        printf("%lld\n", ans);
    }

    return 0;
}
