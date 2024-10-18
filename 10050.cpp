#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, P, h;
        cin >> N >> P;
        unordered_set<int> hartals;
        for (int p = 0; p < P; p++)
        {
            cin >> h;
            int tmp = -1;
            while (tmp < N)
            {
                tmp += h;
                if (tmp >= N)
                    break;
                if (tmp % 7 < 5)
                    hartals.insert(tmp);
            }
        }
        printf("%lld\n", hartals.size());
    }

    return 0;
}
