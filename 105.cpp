#include <bits/stdc++.h>
using namespace std;

#define MAX_WIDTH 10001

int main()
{
    int height[MAX_WIDTH] = {0};
    int right = 0;
    int L, H, R = 0;
    while (cin >> L >> H >> R)
    {
        for (int i = L; i < R; i++)
            if (H > height[i])
                height[i] = H;
        if (R > right)
            right = R;
    }

    bool first = true;
    int h = 0;
    for (int i = 1; i <= right; i++)
    {
        if (height[i] != h)
        {
            h = height[i];
            if (first)
            {
                printf("%d %d", i, h);
                first = false;
            }
            else
                printf(" %d %d", i, h);
        }
    }
    printf("\n");

    return 0;
}