#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string num;
    while (cin >> num)
    {
        if (num == "0")
            break;
        int sum = 0;
        for (char digit : num)
            sum += digit - '0';
        if (sum % 9 != 0)
        {
            printf("%s is not a multiple of 9.\n", num.c_str());
            continue;
        }
        printf("%s", num.c_str());
        int degree = 1;
        while (sum != 0 && sum != 9)
        {
            degree++;
            num = to_string(sum);
            sum = 0;
            for (char digit : num)
                sum += digit - '0';
        }
        printf(" is a multiple of 9 and has 9-degree %d.\n", degree);
    }

    return 0;
}
