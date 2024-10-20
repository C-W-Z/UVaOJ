#include <bits/stdc++.h>
using namespace std;

vector<bool> isprime(1000001, true);

int main()
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= 1000; i++)
    {
        if (!isprime[i])
            continue;
        for (int j = i * i; j <= 1000000; j += i)
            isprime[j] = false;
    }

    int N;
    while (cin >> N)
    {
        if (!isprime[N])
            printf("%d is not prime.\n", N);
        else
        {
            int tmp = N;
            int reverse = 0;
            while (tmp > 0)
            {
                reverse = reverse * 10 + tmp % 10;
                tmp /= 10;
            }
            if (N != reverse && isprime[reverse])
                printf("%d is emirp.\n", N);
            else
                printf("%d is prime.\n", N);
        }
    }

    return 0;
}
