#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        double s, d;
        cin >> s >> d;
        // a + b = s
        // a - b = d;
        // a = (s + d) / 2
        double a = (s + d) / 2;
        double b = s - a;
        if (b < 0 || a != floor(a) || b != floor(b))
            printf("impossible\n");
        else if (a > b)
            printf("%d %d\n", (int)a, (int)b);
        else
            printf("%d %d\n", (int)b, (int)a);
    }

    return 0;
}
