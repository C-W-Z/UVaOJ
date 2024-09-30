#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int number;
    while (cin >> number)
    {
        if (number == 0)
            break;
        while (number >= 10)
        {
            int newnum = 0;
            while (number > 0)
            {
                newnum += number % 10;
                number /= 10;
            }
            number = newnum;
        }
        printf("%d\n", number);
    }

    return 0;
}
