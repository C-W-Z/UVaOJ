#include <bits/stdc++.h>
using namespace std;

bool valid(string &str)
{
    int n = str.size();
    int len, i;
    for (len = 1; len <= n /  2; len++)
    {
        for (i = 0; i < len; i++)
            if (str[n - 1 - i] != str[n - 1 - i - len])
                break;
        if (i == len)
            return false;
    }
    return true;
}

void dfs(string &str, int n, int L, int &rank, bool &complete)
{
    if (!valid(str))
        return;
    rank++;
    if (n == rank)
    {
        complete = true;
        return;
    }
    if (complete)
        return;
    for (int i = 0; i < L; i++)
    {
        str += 'A' + i;
        dfs(str, n, L, rank, complete);
        if (complete)
            return;
        str.pop_back();
    }
}

int main()
{
    int n, L;
    while (cin >> n >> L)
    {
        if (n == 0 && L == 0)
            break;
        string str;
        bool complete = false;
        int rank = -1;
        dfs(str, n, L, rank, complete);
        for (size_t i = 0; i < str.size(); i++)
        {
            if (i == 4 * 16)
                printf("\n");
            else if (i != 0 && i % 4 == 0)
                printf(" ");
            printf("%c", str[i]);
        }
        printf("\n%lld\n", str.size());
    }

    return 0;
}
