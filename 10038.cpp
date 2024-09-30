#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> appear(n, 0);
        bool jolly = true;
        int a, b;
        cin >> a;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b;
            int diff = abs(a - b);
            a = b;
            if (diff <= 0 || diff >= n)
                jolly = false;
            else if (jolly)
                appear[diff]++;
        }
        if (!jolly)
        {
            printf("Not jolly\n");
            continue;
        }
        for (int i = 1; i < n; i++)
        {
            if (appear[i] != 1)
            {
                jolly = false;
                break;
            }
        }
        if (jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;
}
