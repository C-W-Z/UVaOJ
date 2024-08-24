#include <bits/stdc++.h>
using namespace std;
#define MAX_GRID 52

int main()
{
    int m, n; // 2 <= m, n <= 51
    cin >> m >> n;
    int wall_cost, n_bumper;
    cin >> wall_cost >> n_bumper;

    // n x m
    bool is_bumper[MAX_GRID][MAX_GRID] = {{false}};
    int bumper_value[MAX_GRID][MAX_GRID] = {{0}};
    int bumper_cost[MAX_GRID][MAX_GRID] = {{0}};

    for (int i = 0; i < n_bumper; i++)
    {
        int x, y, value, cost;
        cin >> x >> y >> value >> cost;
        x--, y--; // 1 base to 0 base
        bumper_value[y][x] = value;
        bumper_cost[y][x] = cost;
        is_bumper[y][x] = true;
    }

    const int DIRX[4] = {1, 0, -1, 0};
    const int DIRY[4] = {0, 1, 0, -1};

    int x, y, dir, life;
    int total_score = 0;
    while (cin >> x >> y >> dir >> life)
    {
        x--, y--; // 1 base to 0 base
        int score = 0;
        while (true)
        {
            int newX = x + DIRX[dir];
            int newY = y + DIRY[dir];
            life--;
            if (life <= 0)
                break;
            // printf("[%d][%d] %d\n", newX + 1, newY + 1, life);
            if (newX == 0 || newY == 0 || newX == m - 1 || newY == n - 1)
            {
                life -= wall_cost;
                dir = (dir - 1 + 4) % 4; // turn 90 degree
            }
            else if (is_bumper[newY][newX])
            {
                score += bumper_value[newY][newX]; // value
                life -= bumper_cost[newY][newX]; // cost
                dir = (dir - 1 + 4) % 4; // turn 90 degree
            }
            else
            {
                x = newX;
                y = newY;
            }
        }
        total_score += score;
        printf("%d\n", score);
    }
    printf("%d\n", total_score);

    return 0;
}
