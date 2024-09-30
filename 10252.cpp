#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        vector<int> a(26, 0), b(26, 0);
        for (auto &&c : str)
            a[c - 'a']++;
        getline(cin, str);
        for (auto &&c : str)
            b[c - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < min(a[i], b[i]); j++)
                printf("%c", 'a' + i);
        }
        printf("\n");
    }

    return 0;
}
