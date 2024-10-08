#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;

        int sqrtA = (int)ceil(sqrt(a));
        int sqrtB = (int)floor(sqrt(b) + 1e-6);
        printf("%d\n", sqrtB - sqrtA + 1);
    }

    return 0;
}
