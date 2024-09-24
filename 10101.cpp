#include <bits/stdc++.h>
using namespace std;

void print_n(uint64_t number, bool before)
{
    if (number >= 100000)
    {
        int tmp = number / 100000;
        if (tmp != 0)
        {
            if (before)
                printf(" ");
            printf("%d lakh", tmp);
            before = true;
        }
        number %= 100000;
    }
    if (number >= 1000)
    {
        int tmp = number / 1000;
        if (tmp != 0)
        {
            if (before)
                printf(" ");
            printf("%d hajar", tmp);
            before = true;
        }
        number %= 1000;
    }
    if (number >= 100)
    {
        int tmp = number / 100;
        if (tmp != 0)
        {
            if (before)
                printf(" ");
            printf("%d shata", tmp);
            before = true;
        }
        number %= 100;
    }
    if (number != 0)
    {
        if (before)
            printf(" ");
        printf("%lld", number);
        before = true;
    }
}

int main()
{
    int t = 0;
    uint64_t number;
    while (cin >> number)
    {
        t++;
        printf("%4d. ", t);
        if (number == 0)
        {
            printf("0\n");
            continue;
        }
        bool before = false;
        if (number >= 100000000000000ULL)
        {
            printf("%lld kuti", number / 100000000000000ULL);
            before = true;
            number %= 100000000000000ULL;
        }
        if (number >= 10000000)
        {
            print_n(number / 10000000, before);
            before = true;
            number %= 10000000;
        }
        if (before)
            printf(" kuti");
        print_n(number, before);
        printf("\n");
    }

    return 0;
}
