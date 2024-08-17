#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    while (cin >> H >> W)
    {
        if (H == 0 && W == 0)
            break;
        if (H == 1)
        {
            printf("0 1\n");
            continue;
        }
        // H = (N+1)^k
        // W = N^k
        int k = 1;
        double n;
        while (true)
        {
            n = pow(W, 1.0 / k);
            int h = pow(n + 1, k) + 1e-6;
            if (H == h)
                break;
            k++;
        }
        int N = round(n);

        int nowork = 0;
        int cats = 1;
        int height = 0;
        for (int i = 0; i < k; i++)
        {
            nowork += cats;
            height += H * cats;
            cats *= N;
            H /= N + 1;
        }
        height += H * cats;

        printf("%d %d\n", nowork, height);
    }

    return 0;
}
