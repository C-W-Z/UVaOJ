#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int X, Y;
    cin >> X >> Y;

    bool scent[51][51] = {{0}};

    int x, y, dir;
    char dir_c;
    while (cin >> x >> y >> dir_c)
    {
        if (dir_c == 'N')
            dir = 0;
        else if (dir_c == 'E')
            dir = 1;
        else if (dir_c == 'S')
            dir = 2;
        else
            dir = 3;

        const int DIRX[] = {0, 1, 0, -1};
        const int DIRY[] = {1, 0, -1, 0};
        const char DIR[] = {'N', 'E', 'S', 'W'};

        string instruct;
        cin >> instruct;
        bool lost = false;
        for (char i : instruct)
        {
            if (i == 'R')
                dir = (dir + 1) % 4;
            else if (i == 'L')
                dir = (dir + 3) % 4;
            else if (i == 'F')
            {
                int newX = x + DIRX[dir];
                int newY = y + DIRY[dir];
                if (newX < 0 || newY < 0 || newX > X || newY > Y)
                {
                    if (scent[x][y])
                        continue;
                    scent[x][y] = true;
                    lost = true;
                    break;
                }
                x = newX;
                y = newY;
            }
        }

        if (lost)
            printf("%d %d %c LOST\n", x, y, DIR[dir]);
        else
            printf("%d %d %c\n", x, y, DIR[dir]);
    }

    return 0;
}
