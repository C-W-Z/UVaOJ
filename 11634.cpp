#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a0[16];
    while (scanf("%s", a0) != EOF && !(a0[0] == '0' && a0[1] == '\0'))
    {
        unordered_set<int> rn;
        int a = atoi(a0);
        while (rn.find(a) == rn.end())
        {
            rn.insert(a);
            int n = strlen(a0);
            // itoa(a * a, a0, 10);
            sprintf(a0, "%d", a * a);
            int len = strlen(a0);
            if (2 * n > len)
            {
                for (int i = len; i >= 0; i--)
                    a0[i + 2 * n - len] = a0[i];
                for (int i = 0; i < 2 * n - len; i++)
                    a0[i] = '0';
            }
            for (int i = 0; i < n; i++)
                a0[i] = a0[i + n / 2];
            a0[n] = '\0';
            a = atoi(a0);
        }
        printf("%lld\n", rn.size());
    }

    return 0;
}