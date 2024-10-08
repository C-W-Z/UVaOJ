#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, id;
        double prob;
        cin >> N >> prob >> id;
        if (prob == 0)
        {
            printf("0.0000\n");
            continue;
        }
        double fail = 1 - prob;
        double winrate = prob * pow(fail, id - 1) / (1 - pow(fail, N));
        printf("%.4lf\n", winrate);
    }

    return 0;
}
