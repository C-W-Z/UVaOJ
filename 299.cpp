#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        vector<int> train(n);
        for (int i = 0; i < n; i++)
            cin >> train[i];
        int swaptime = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (train[j - 1] > train[j])
                {
                    swap(train[j], train[j - 1]);
                    swaptime++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", swaptime);
    }

    return 0;
}
