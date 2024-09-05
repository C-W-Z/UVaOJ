#include <bits/stdc++.h>
using namespace std;

int main()
{
    int city_k = 0;
    int n_pairs;
    while (cin >> n_pairs)
    {
        int paths[32][32] = {{0}};
        int n_nodes = 0;
        for (int i = 0; i < n_pairs; i++)
        {
            int a, b;
            cin >> a >> b;
            paths[a][b] = 1;
            n_nodes = max(n_nodes, max(a, b) + 1);
        }

        for (int k = 0; k < n_nodes; k++)
            for (int i = 0; i < n_nodes; i++)
                for (int j = 0; j < n_nodes; j++)
                    if (paths[i][k] != 0 && paths[k][j] != 0)
                        paths[i][j] += paths[i][k] * paths[k][j];

        for (int k = 0; k < n_nodes; k++)
        {
            if (paths[k][k] == 0)
                continue;
            // paths[k][k] > 0 => cycle => infinite paths for i->k, k->i, i->k->j
            for (int i = 0; i < n_nodes; i++)
            {
                if (paths[i][k] != 0)
                    paths[i][k] = -1;
                if (paths[k][i] != 0)
                    paths[k][i] = -1;
                for (int j = 0; j < n_nodes; j++)
                    if (paths[i][k] != 0 && paths[k][j] != 0)
                        paths[i][j] = -1;
            }
        }

        printf("matrix for city %d\n", city_k);
        for (int i = 0; i < n_nodes; i++)
        {
            for (int j = 0; j < n_nodes; j++)
            {
                if (j == n_nodes - 1)
                    printf("%d", paths[i][j]);
                else
                    printf("%d ", paths[i][j]);
            }
            printf("\n");
        }

        city_k++;
    }

    return 0;
}
