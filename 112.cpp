#include <bits/stdc++.h>
using namespace std;

bool ans;

pair<bool, bool> input_tree(const int I, const int cur_sum)
{
    char c;
    string s;
    while (cin >> c)
    {
        if (c == '(')
            break;
        if (c == ')')
        {
            // printf("1[%d]%c\n", cur_sum, c);
            return {true, cur_sum == I};
        }
        s += c;
    }
    // printf("2[%d]%s\n", cur_sum, s.data());
    int n = stoi(s);
    auto left = input_tree(I, cur_sum + n);
    cin >> c;
    // assert(c == '(');
    auto right = input_tree(I, cur_sum + n);
    cin >> c;
    // assert(c == ')');
    // printf("3[%d]%c\n", cur_sum, c);
    if (left.first && right.first && (left.second || right.second))
        ans = true;
    return {false, false};
}

int main()
{
    int I;
    while (cin >> I)
    {
        ans = false;
        char c;
        cin >> c;
        // assert(c == '(');
        input_tree(I, 0);
        if (ans)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
