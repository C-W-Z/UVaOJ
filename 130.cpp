#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, k; // n, k > 0
    char survive[128];
    while (scanf("%d %d", &n, &k) != EOF)
    {
        if (n == 0 && k == 0)
            break;
        for (int i = 0; i < n; i++)
            survive[i] = i + 1;
        int pos = n - 1;
        int count = n;
        while (count > 1)
        {
            int i = 0;
            while (i < k)
            {
                pos = (pos + 1) % n;
                if (survive[pos] > 0)
                    i++;
            }

            int kill = pos;
            survive[kill] = 0;

            i = 0;
            while (i < k)
            {
                pos = (pos + 1) % n;
                if (survive[pos] > 0)
                    i++;
            }

            swap(survive[kill], survive[pos]);
            pos = kill;

            count--;

            // for (auto &&i : survive)
            //     printf("%d ", i);
            // printf("\n");
        }
        for (pos = 0; pos < n; pos++)
            if (survive[pos] > 0)
                break;
        if (survive[pos] == 1)
            printf("1\n");
        else
            printf("%d\n", n - survive[pos] + 2);
    }

    return 0;
}
