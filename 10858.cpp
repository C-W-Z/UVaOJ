#include <bits/stdc++.h>
using namespace std;

void dfs(int N, vector<int> &fac, vector<vector<int>> &total)
{
    int pre = fac.empty() ? 2 : (*fac.rbegin());
    if (N == 1)
    {
        if (fac.size() > 1)
            total.push_back(fac);
        return;
    }
    for (int i = pre; i <= N; i++)
    {
        if (N % i != 0)
            continue;
        fac.push_back(i);
        dfs(N / i, fac, total);
        fac.pop_back();
    }
}

int main()
{
    int N;
    while (scanf("%d", &N) != EOF)
    {
        if (N == 0)
            break;
        vector<vector<int>> total;
        vector<int> fac;
        dfs(N, fac, total);
        printf("%d\n", total.size());
        for (auto &&f : total)
        {
            for (int i = 0; i < f.size(); i++)
            {
                if (i == f.size() - 1)
                    printf("%d\n", f[i]);
                else
                    printf("%d ", f[i]);
            }
        }
    }
    return 0;
}
