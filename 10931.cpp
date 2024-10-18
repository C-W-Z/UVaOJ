#include <bits/stdc++.h>
using namespace std;

// __builtin_popcount(n)
int count1(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return count;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        string binary;
        int count = 0;
        while (n != 0)
        {
            if (n & 1)
            {
                count++;
                binary += '1';
            }
            else
            {
                binary += '0';
            }
            n >>= 1;
        }
        reverse(binary.begin(), binary.end());
        printf("The parity of %s is %d (mod 2).\n", binary.data(), count);
    }


    return 0;
}
