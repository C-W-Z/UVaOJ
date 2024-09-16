#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    long long factorial[22];
    factorial[0] = 1;
    for (int i = 1; i < 22; i++)
        factorial[i] = factorial[i - 1] * i;

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        string str, ans;
        long long order;
        cin >> str >> order;
        sort(str.begin(), str.end());
        while (!str.empty())
        {
            long long f = factorial[str.size() - 1];
            int i = order / f;
            ans += str[i];
            str.erase(i, 1);
            order %= f;
        }
        cout << ans << '\n';
    }

    return 0;
}
