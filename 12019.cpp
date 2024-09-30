#include <bits/stdc++.h>
using namespace std;

int main()
{
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int M, D;
        cin >> M >> D;
        int day = 0;
        if (M == 1)
            day = D - 10;
        else if (M == 2)
            day = D - 21;
        else if (M == 3)
            day = D + 28 - 21;
        else if (M == 4)
            day = D - 4;
        else if (M == 5)
            day = D - 9;
        else if (M == 6)
            day = D - 6;
        else if (M == 7)
            day = D - 11;
        else if (M == 8)
            day = D - 8;
        else if (M == 9)
            day = D - 5;
        else if (M == 10)
            day = D - 10;
        else if (M == 11)
            day = D - 7;
        else if (M == 12)
            day = D - 12;
        day = (day + 28) % 7;
        printf("%s\n", days[day].data());
    }

    return 0;
}
