#include <bits/stdc++.h>
using namespace std;

// find min euler path
int main(int argc, char const *argv[])
{
    int route[26][26];
    int degree[26] = {0};
    int sum = 0;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            route[i][j] = INT_MAX >> 8;

    string str;
    while (cin >> str)
    {
        if (str != "deadend")
        {
            int len = str.size();
            int first = str[0] - 'a';
            int last = str[len - 1] - 'a';
            route[first][last] = len;
            route[last][first] = len;
            degree[first]++;
            degree[last]++;
            sum += len;
            continue;
        }

        vector<int> odd_degree;
        for (int i = 0; i < 26; i++)
            if (degree[i] & 1)
                odd_degree.push_back(i);

        if (!odd_degree.empty())
        {
            // odd degree == 2
            for (int k = 0; k < 26; k++)
                for (int i = 0; i < 26; i++)
                    for (int j = 0; j < 26; j++)
                        route[i][j] = min(route[i][j], route[i][k] + route[k][j]);

            sum += route[odd_degree[0]][odd_degree[1]];
        }

        printf("%d\n", sum);

        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                route[i][j] = INT_MAX >> 8;
        memset(degree, 0, sizeof(degree));
        sum = 0;
    }

    return 0;
}
