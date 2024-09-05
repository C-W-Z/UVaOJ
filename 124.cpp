#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &vars, vector<vector<int>> &before, string &str, int n)
{
    if (str.size() == n)
    {
        printf("%s\n", str.data());
        return;
    }
    for (int c = 0; c < 26; c++)
    {
        if (vars[c] != 1)
            continue;
        // check if all smaller vars are used
        bool all = true;
        for (auto &&v : before[c])
            if (vars[v] != 2)
            {
                all = false;
                break;
            }
        if (!all)
            continue;
        str += c + 'a';
        vars[c] = 2; // label as used
        dfs(vars, before, str, n);
        str.pop_back();
        vars[c] = 1; // label as not used
    }
}

int main()
{
    string variables;
    string rules;
    bool first = true;
    while (getline(cin, variables))
    {
        if (!first)
            printf("\n");
        else
            first = false;

        vector<int> vars(26, 0);
        vector<vector<int>> before(26);
        int n = 0;
        for (auto &&c : variables)
            if (c != ' ' && c != '\0')
            {
                vars[c - 'a'] = 1;
                n++;
            }
        getline(cin, rules);
        for (size_t i = 0; i < rules.size(); i += 4)
            before[rules[i + 2] - 'a'].push_back(rules[i] - 'a');
        string str;
        dfs(vars, before, str, n);
    }

    return 0;
}
