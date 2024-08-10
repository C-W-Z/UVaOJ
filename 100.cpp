#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
void solve(int n)
{
    while (n != 1)
    {
        printf("%d ", n);
        if (n & 1)
            n = 3 * n + 1;
        else
            n /= 2;
    }
    printf("%d\n", n);
}
*/

int recurse(const int n, unordered_map<int, int> &cycle_len)
{
    if (cycle_len.find(n) != cycle_len.end())
        return cycle_len[n];
    return cycle_len[n] = 1 + recurse((n & 1) ? (3 * n + 1) : (n >> 1), cycle_len);
}

int main()
{
    unordered_map<int, int> cycle_len;
    cycle_len[1] = 1;

    int i, j; // 0 < i,j < 10000
    while (scanf("%d %d", &i, &j) != EOF)
    {
        int max_len = 1;
        int start = min(i, j);
        int end = max(i, j);
        for (int n = start; n <= end; n++)
            max_len = max(max_len, recurse(n, cycle_len));
        printf("%d %d %d\n", i, j, max_len);
    }

    return 0;
}
