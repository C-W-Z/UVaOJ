#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int xy1 = x1 + y1;
        int xy2 = x2 + y2;
        int step = (xy2 * (xy2 + 1) / 2) - (xy1 * (xy1 + 1) / 2) - x1 + x2;
        printf("Case %d: %d\n", t + 1, step);
    }

    return 0;
}
