#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    bool first = true;
    int n;
    while (cin >> n)
    {
        vector<string> order(n);
        unordered_map<string, int> money;
        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            order[i] = name;
            money[name] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            int spend, num;
            cin >> spend >> num;
            if (num == 0)
                continue;
            money[name] -= (spend / num) * num;
            for (int j = 0; j < num; j++)
            {
                cin >> name;
                money[name] += spend / num;
            }
        }
        if (!first)
            printf("\n");
        first = false;
        for (int i = 0; i < n; i++)
            printf("%s %d\n", order[i].data(), money[order[i]]);
    }

    return 0;
}
