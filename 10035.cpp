#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long a, b;
    while (scanf("%lld%lld", &a, &b) != EOF)
    {
        if (a == 0 && b == 0)
            break;
        int sum = 0;
        int carry = 0;
        while (a > 0 || b > 0)
        {
            sum += (a % 10) + (b % 10);
            if (sum >= 10)
                carry++;
            sum /= 10;
            a /= 10;
            b /= 10;
        }
        if (carry == 0)
            printf("No carry operation.\n");
        else if (carry == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", carry);
    }

    return 0;
}
