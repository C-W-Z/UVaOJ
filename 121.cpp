#include <bits/stdc++.h>
using namespace std;

int grid(double W, double H)
{
    return (int)W * (int)H;
}

int skew(double W, double H)
{
    int w = (int)W;
    int layer = (H - 1) / (sqrt(3) / 2) + 1;
    int n = 0;
    if (W - w >= 0.5)
        return layer * w;
    return layer * w - layer / 2;
}

int main()
{
    double W, H;
    while (cin >> W >> H)
    {
        int g = max(grid(W, H), grid(H, W));
        int s = max(skew(W, H), skew(H, W));
        if (g >= s)
            printf("%d grid\n", g);
        else
            printf("%d skew\n", s);
    }

    return 0;
}
