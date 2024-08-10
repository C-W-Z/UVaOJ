#include <stdio.h>
#include <string.h>
#define MAX_BLOCK 25

void print_world(const int n, const int world[MAX_BLOCK][MAX_BLOCK])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        for (int j = 0; j < n; j++)
        {
            if (world[i][j] == -1)
                break;
            printf(" %d", world[i][j]);
        }
        printf("\n");
    }
}

void clear_above(
    const int n,
    int world[MAX_BLOCK][MAX_BLOCK],
    int row[MAX_BLOCK],
    int col[MAX_BLOCK],
    int block
) {
    int r = row[block];
    for (int c = col[block] + 1; c < n && world[r][c] != -1; c++)
    {
        int v = world[r][c];
        world[v][0] = v;
        world[r][c] = -1;
        row[v] = v;
        col[v] = 0;
    }
}

void manipulate(
    const int n,
    int world[MAX_BLOCK][MAX_BLOCK],
    int row[MAX_BLOCK],
    int col[MAX_BLOCK],
    const bool move,
    const int a,
    const bool onto,
    const int b
) {
    int ra = row[a], rb = row[b], ca = col[a], cb = col[b];
    if (ra == rb)
        return;

    if (move)
        clear_above(n, world, row, col, a);
    if (onto)
        clear_above(n, world, row, col, b);

    while (world[rb][cb] != -1)
        cb++;
    while (world[ra][ca] != -1)
    {
        int v = world[ra][ca];
        row[v] = rb;
        col[v] = cb;
        world[rb][cb] = v;
        world[ra][ca] = -1;
        ca++;
        cb++;
    }
}

int main()
{
    int n; // 0 < n < MAX_BLOCK
    int world[MAX_BLOCK][MAX_BLOCK];
    for (auto &&i : world)
        for (auto &&j : i)
            j = -1;
    int row[MAX_BLOCK], col[MAX_BLOCK];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        world[i][0] = i;
        row[i] = i;
        col[i] = 0;
    }

    char cmd1[5], cmd2[5];
    int block1, block2;
    while (scanf("%s", cmd1) != EOF)
    {
        if (strncmp(cmd1, "q", 1) == 0)
            break;
        scanf("%d %s %d", &block1, cmd2, &block2);
        manipulate(
            n, world, row, col,
            strncmp(cmd1, "m", 1) == 0,
            block1,
            strncmp(cmd2, "on", 2) == 0,
            block2
        );
    }

    print_world(n, world);

    return 0;
}
