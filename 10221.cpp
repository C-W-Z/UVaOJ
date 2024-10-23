#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    const double R = 6440.0;
    double dist, angle;
    string unit;
    while (cin >> dist >> angle >> unit)
    {
        if (unit == "min")
            angle /= 60;
        while (angle > 360)
            angle -= 360;
        while (angle < 0)
            angle += 360;
        if (angle > 180)
            angle = 360 - angle;
        double arc = 2 * M_PI * (R + dist) * (angle / 360);
        double line = 2 * (R + dist) * sin(angle / 2 * M_PI / 180.0);
        printf("%lf %lf\n", arc, line);
    }

    return 0;
}
