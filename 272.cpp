#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool first = true;
    string line;
    while (getline(cin, line))
    {
        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] == '"')
            {
                if (first)
                    printf("``");
                else
                    printf("''");
                first = !first;
            }
            else
                printf("%c", line[i]);
        }
        printf("\n");
    }

    return 0;
}
