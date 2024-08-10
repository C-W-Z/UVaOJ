#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <string>
using namespace std;

int calc(string &color, int bin[3][3])
{
    int n = 0;
    for (int i = 0; i < 3; i++)
    {
        switch (color[i])
        {
        case 'B':
            n += bin[i][1] + bin[i][2];
            break;
        case 'G':
            n += bin[i][0] + bin[i][2];
            break;
        case 'C':
            n += bin[i][0] + bin[i][1];
            break;

        default:
            break;
        }
    }
    return n;
}

int main()
{
    int bin[3][3];
    int ans;
    string color, ans_color;

    while (true)
    {
        for (auto &&b : bin)
            for (auto &&i : b)
                scanf("%d", &i);

        if (feof(stdin))
            break;

        ans = INT_MAX;
        color = "BCG";
        do
        {
            int ret = calc(color, bin);
            if (ret < ans)
            {
                ans = ret;
                ans_color = color;
            }
        } while (next_permutation(color.begin(), color.end()));

        printf("%s %d\n", ans_color.data(), ans);
    }

    return 0;
}
