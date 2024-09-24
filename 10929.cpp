#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string number;
    while (cin >> number)
    {
        if (number == "0")
            break;
        int odd = 0, even = 0;
        for (size_t i = 0; i < number.size(); i++)
        {
            if (i & 1)
                odd += number[i] - '0';
            else
                even += number[i] - '0';
        }
        if (abs(odd - even) % 11 == 0)
            printf("%s is a multiple of 11.\n", number.data());
        else
            printf("%s is not a multiple of 11.\n", number.data());
    }

    return 0;
}
