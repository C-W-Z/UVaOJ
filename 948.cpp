#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> fib = {1, 2};
    for (int i = 2; fib.back() <= 100000000; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int decimal;
        cin >> decimal;
        int idx = fib.size() - 1;
        int dec = decimal;
        while (dec < fib[idx])
            idx--;
        string fib_base;
        while (dec > 0 || idx >= 0)
        {
            if (dec >= fib[idx] && (fib_base.empty() || fib_base.back() != '1'))
            {
                fib_base += '1';
                dec -= fib[idx];
            }
            else // if (dec < fib[idx])
            {
                fib_base += '0';
            }
            idx--;
        }
        printf("%d = %s (fib)\n", decimal, fib_base.data());
    }

    return 0;
}
