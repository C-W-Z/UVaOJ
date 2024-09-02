#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<string> ignore;
    string word;
    while (cin >> word)
    {
        if (word == "::")
            break;
        ignore.insert(word);
    }
    cin.ignore(); // read the '\n' after "::"
    multimap<string, string> KWIC;
    string title;
    while (getline(cin, title))
    {
        transform(title.begin(), title.end(), title.begin(), [](char c)
                  { return tolower(c); });
        int start = 0, i = 0;
        for (; i <= title.size(); i++)
        {
            if (title[i] == ' ' || title[i] == '\0')
            {
                word = title.substr(start, i - start);
                if (ignore.find(word) == ignore.end())
                {
                    transform(title.begin() + start, title.begin() + i, title.begin() + start, [](char c)
                              { return toupper(c); });
                    KWIC.insert({word, title});
                    transform(title.begin() + start, title.begin() + i, title.begin() + start, [](char c)
                              { return tolower(c); });
                }
                start = i + 1;
            }
        }
    }
    for (auto &&s : KWIC)
        printf("%s\n", s.second.data());

    return 0;
}
