#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    while (cin >> N)
    {
        vector<int> num(N);
        for (int i = 0; i < N; i++)
            cin >> num[i];
        sort(num.begin(), num.end());
        int mid1 = num[(N - 1) / 2];
        int mid2 = num[N / 2]; // if N is odd, mid1 == mid2
        int ans_num = 0;
        for (int i = 0; i < N; i++)
            if (num[i] == mid1 || num[i] == mid2)
                ans_num++;
        printf("%d %d %d\n", mid1, ans_num, mid2 - mid1 + 1);
    }

    return 0;
}
