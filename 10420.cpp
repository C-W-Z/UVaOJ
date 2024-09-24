#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string country;
    map<string, int> count;
    for (int i = 0; i < n; i++)
    {
        cin >> country;
        count[country]++;
        getline(cin, country);
    }
    for (auto &&p : count)
        printf("%s %d\n", p.first.data(), p.second);

    return 0;
}
