#include <bits/stdc++.h>
using namespace std;

int main()
{
    string number;
    while (cin >> number)
    {
        // (a0 * N^0 + a1 * N^1 + a2 * N^2 + ... ak * N^k) % (N - 1)
        // == (a0 + a1 + a2 + ... + ak) % (N - 1)
        // since N % (N - 1) = 1, N * N % (N - 1) = N * 1 % (N - 1) = 1
        int minBase = 2;
        int sum = 0;
        for (char c : number)
        {
            if (c >= '0' && c <= '9')
            {
                minBase = max(minBase, c - '0' + 1);
                sum += c - '0';
            }
            else if (c >= 'A' && c <= 'Z')
            {
                minBase = max(minBase, c - 'A' + 11);
                sum += c - 'A' + 10;
            }
            else if (c >= 'a' && c <= 'z')
            {
                minBase = max(minBase, c - 'a' + 37);
                sum += c - 'a' + 36;
            }
        }
        bool impossible = true;
        for (int N = minBase; N <= 62; N++)
        {
            if (sum % (N - 1) == 0)
            {
                printf("%d\n", N);
                impossible = false;
                break;
            }
        }
        if (impossible)
            printf("such number is impossible!\n");
    }

    return 0;
}
