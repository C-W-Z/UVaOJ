#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        // know A, B, C => D = A + C - B
        if (x1 == x3 && y1 == y3)
            printf("%.3lf %.3lf\n", x2 + x4 - x1, y2 + y4 - y1);
        else if (x1 == x4 && y1 == y4)
            printf("%.3lf %.3lf\n", x2 + x3 - x1, y2 + y3 - y1);
        else if (x2 == x3 && y2 == y3)
            printf("%.3lf %.3lf\n", x1 + x4 - x2, y1 + y4 - y2);
        else // if (x2 == x4 && y2 == y4)
            printf("%.3lf %.3lf\n", x1 + x3 - x2, y1 + y3 - y2);
    }
    return 0;
}
