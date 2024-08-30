#include <bits/stdc++.h>
using namespace std;

int main()
{
    char line[100];
    while (cin.getline(line, 100))
    {
        char *data = line;
        vector<int> pancakes;
        int pancake;
        int offset = 0;
        while (sscanf(data, "%d%n", &pancake, &offset) != EOF)
        {
            pancakes.push_back(pancake);
            data += offset;
        }
        for (int i = 0; i < pancakes.size() - 1; i++)
            printf("%d ", pancakes[i]);
        printf("%d\n", pancakes[pancakes.size() - 1]);

        for (int i = pancakes.size() - 1; i >= 0; i--)
        {
            int maxpos = 0;
            for (int j = 0; j <= i; j++)
                if (pancakes[j] > pancakes[maxpos])
                    maxpos = j;

            if (maxpos == i)
                continue;
            if (maxpos != 0)
            {
                reverse(pancakes.begin(), pancakes.begin() + maxpos + 1);
                printf("%d ", pancakes.size() - maxpos);
            }
            reverse(pancakes.begin(), pancakes.begin() + i + 1);
            printf("%d ", pancakes.size() - i);
        }
        printf("0\n");
    }
    return 0;
}
