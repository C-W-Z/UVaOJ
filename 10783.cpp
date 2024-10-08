#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;
        if (!(a & 1))
            a += 1;
        int sum = 0;
        while (a <= b)
        {
            sum += a;
            a += 2;
        }
        printf("Case %d: %d\n", i + 1, sum);
    }

    return 0;
}
