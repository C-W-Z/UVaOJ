#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<char, char> left;
    const string keys[] = {
        "`1234567890-=",
        "QWERTYUIOP[]\\",
        "ASDFGHJKL;'",
        "ZXCVBNM,./"
    };
    for (auto &key: keys)
        for (int i = 1; i < key.size(); i++)
            left[key[i]] = key[i - 1];
    left[' '] = ' ';

    string str;
    while (getline(cin, str))
    {
        for (char &c : str)
            c = left[c];
        cout << str << '\n';
    }

    return 0;
}
