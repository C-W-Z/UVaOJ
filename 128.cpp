#include <bits/stdc++.h>
using namespace std;

#define MOD 34943

int main()
{
    string str;
    while (getline(cin, str))
    {
        if (str == "#")
            break;
        if (str.empty())
        {
            printf("00 00\n");
            continue;
        }
        uint64_t r = 0;
        for (auto &&c : str)
            r = ((r << 8) + c) % MOD;
        // (num + r) % MOD == 0 => r = -(num % MOD)
        r = MOD - ((r << 16) % MOD);
        printf("%02X %02X\n", r >> 8, r & 255);
    }
    return 0;
}
