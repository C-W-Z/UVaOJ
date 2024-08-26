#include <bits/stdc++.h>
using namespace std;

int k_descendent(unordered_map<string, string> &parent, string &p, string &q)
{
    string tmp = p;
    int k = -1;
    while (parent.find(tmp) != parent.end())
    {
        k++;
        tmp = parent[tmp];
        if (tmp == q)
            return k;
    }
    return -1;
}

pair<int, int> cousin(unordered_map<string, string> &parent, string &p, string &q)
{
    stack<string> ancestors_p, ancestors_q;
    string ancestor_p = p, ancestor_q = q;
    while (parent.find(ancestor_p) != parent.end())
    {
        ancestor_p = parent[ancestor_p];
        ancestors_p.push(ancestor_p);
    }
    while (parent.find(ancestor_q) != parent.end())
    {
        ancestor_q = parent[ancestor_q];
        ancestors_q.push(ancestor_q);
    }
    if (ancestor_p != ancestor_q)
        return {-1, -1};
    while (!ancestors_p.empty() && !ancestors_q.empty() && ancestors_p.top() == ancestors_q.top())
    {
        ancestors_p.pop();
        ancestors_q.pop();
    }
    return {ancestors_p.size(), ancestors_q.size()};
}

int main()
{
    ios::sync_with_stdio();
    cin.tie(NULL);

    unordered_map<string, string> parent;
    // unordered_multimap<string, string> child;
    string p, q;
    while (cin >> p >> q)
    {
        if (p == "no.child")
            break;
        parent[p] = q;
        // child.insert({q, p});
    }

    while (cin >> p >> q)
    {
        // printf("%s %s\n", p.data(), q.data());
        int k = k_descendent(parent, p, q);
        // printf("%d\n", k);
        if (k >= 0)
        {
            while (k > 1)
            {
                printf("great ");
                k--;
            }
            if (k == 1)
                printf("grand child\n");
            else // if (k == 0)
                printf("child\n");
            continue;
        }
        k = k_descendent(parent, q, p);
        // printf("%d\n", k);
        if (k >= 0)
        {
            while (k > 1)
            {
                printf("great ");
                k--;
            }
            if (k == 1)
                printf("grand parent\n");
            else // if (k == 0)
                printf("parent\n");
            continue;
        }

        auto mn = cousin(parent, p, q);
        // printf("m=%d, n=%d\n", mn.first, mn.second);
        if (mn.first >= 0 && mn.second >= 0)
        {
            k = min(mn.first, mn.second);
            int j = abs(mn.first - mn.second);
            if (k == 0 && j == 0)
                printf("sibling\n");
            else if (j == 0)
                printf("%d cousin\n", k);
            else
                printf("%d cousin removed %d\n", k, j);
            continue;
        }

        printf("no relation\n");
    }

    return 0;
}
