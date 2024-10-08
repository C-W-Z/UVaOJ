#include <bits/stdc++.h>
using namespace std;

bool isB2(vector<int> &numbers, int N)
{
    unordered_set<int> sum;
    for (int i = 0; i < N; i++)
    {
        if (numbers[i] < 1 || (i > 0 && numbers[i] <= numbers[i - 1]))
            return false;
        for (int j = i; j < N; j++)
        {
            int s = numbers[i] + numbers[j];
            if (sum.find(s) != sum.end())
                return false;
            sum.insert(s);
        }
    }
    return true;
}

int main()
{
    int T = 0;
    int N;
    while (cin >> N)
    {
        T++;
        vector<int> numbers(N);
        for (int i = 0; i < N; i++)
            cin >> numbers[i];
        if (isB2(numbers, N))
            printf("Case #%d: It is a B2-Sequence.\n\n", T);
        else
            printf("Case #%d: It is not a B2-Sequence.\n\n", T);
    }

    return 0;
}
