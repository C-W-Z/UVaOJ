#include <bits/stdc++.h>
using namespace std;

int convert(vector<int> &costs, int base, int number)
{
    int cost = 0;
    while (number != 0)
    {
        cost += costs[number % base];
        number /= base;
    }
    return cost;
}

int main()
{
    // string base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        vector<int> costs(37);
        for (int i = 0; i < 36; i++)
            cin >> costs[i];
        int q;
        cin >> q;
        if (t > 0)
            printf("\n");
        printf("Case %d:\n", t + 1);
        for (int i = 0; i < q; i++)
        {
            int decimal;
            cin >> decimal;
            vector<int> min_bases;
            int min_cost = INT_MAX;
            for (int b = 2; b <= 36; b++)
            {
                int cost = convert(costs, b, decimal);
                if (cost < min_cost)
                {
                    min_cost = cost;
                    min_bases.clear();
                    min_bases.push_back(b);
                }
                else if (cost == min_cost)
                {
                    min_bases.push_back(b);
                }
            }
            printf("Cheapest base(s) for number %d: ", decimal);
            for (size_t i = 0; i < min_bases.size(); i++)
            {
                if (i == min_bases.size() - 1)
                    printf("%d\n", min_bases[i]);
                else
                    printf("%d ", min_bases[i]);
            }
        }
    }

    return 0;
}