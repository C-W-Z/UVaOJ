#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, char> dict;
    string keys = "1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    for (size_t i = 2; i < keys.size(); i++)
        dict.insert({keys[i], keys[i-2]});
    string line;
    getline(cin, line);
    for (char &c : line)
        if (!isspace(c))
        c = dict[tolower(c)];
    cout << line << endl;

    return 0;
}
