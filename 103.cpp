#include <bits/stdc++.h>
using namespace std;

bool smaller(const vector<int> &a, const vector<int> &b, const int d)
{
    for (int i = 1; i <= d; i++)
        if (a[i] >= b[i])
            return false;
    return true;
}

void dfs(
    const vector<vector<int>> &boxes,
    const int n_box,
    const int d,
    vector<int> &stk,
    vector<int> &max_stk,
    const int i
) {
    if (i >= n_box)
    {
        if (stk.size() > max_stk.size())
            max_stk = stk;
        return;
    }
    if (max_stk.size() > stk.size() + n_box - i)
        return;
    if (stk.empty() || smaller(boxes[stk.back()], boxes[i], d))
    {
        stk.push_back(i);
        dfs(boxes, n_box, d, stk, max_stk, i + 1);
        stk.pop_back();
    }
    dfs(boxes, n_box, d, stk, max_stk, i + 1);
}

int main()
{
    int n_box, d; // n_box <= 30, 1 <= d <= 10
    vector<vector<int>> boxes(30, vector<int>(11));
    vector<int> stk, max_stk;
    stk.reserve(30);
    while (cin >> n_box >> d)
    {
        for (int i = 0; i < n_box; i++)
        {
            boxes[i][0] = i + 1;
            for (int j = 1; j <= d; j++)
                cin >> boxes[i][j];
            sort(boxes[i].begin() + 1, boxes[i].begin() + 1 + d);
        }
        sort(boxes.begin(), boxes.begin() + n_box,
             [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        stk.clear();
        max_stk.clear();

        dfs(boxes, n_box, d, stk, max_stk, 0);

        cout << max_stk.size() << '\n';
        for (size_t i = 0; i < max_stk.size(); i++)
        {
            cout << boxes[max_stk[i]][0];
            if (i != max_stk.size() - 1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
