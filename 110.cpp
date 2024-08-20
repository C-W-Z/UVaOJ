#include <bits/stdc++.h>
using namespace std;

void pascal_if_else(vector<char> &vars, int idx)
{
    int n = vars.size();
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
            printf("  ");
        printf("writeln(");
        for (int i = 0; i < n - 1; i++)
            printf("%c,", vars[i]);
        printf("%c)\n", vars[n - 1]);
        return;
    }
    vector<char> cpy = vars;
    for (int i = idx; i >= 0; i--)
    {
        for (int j = 0; j < idx; j++)
            printf("  ");

        if (i == idx)
        {
            // if this statement is true
            // no swap needed
            printf("if %c < %c then\n", cpy[i - 1], idx + 'a');
        }
        else if (i == 0)
        {
            printf("else\n");

            // the prev statement is false
            // so cpy[i] > cpy[i + 1]
            swap(cpy[i], cpy[i + 1]);
        }
        else
        {
            // the prev statement is false
            // so cpy[i] > cpy[i + 1]
            swap(cpy[i], cpy[i + 1]);

            // if this statement is true
            // no swap needed
            printf("else if %c < %c then\n", cpy[i - 1], idx + 'a');
        }

        pascal_if_else(cpy, idx + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        vector<char> vars(n);
        printf("program sort(input,output);\nvar\n");
        string varstr = "";
        for (char c = 0; c < n; c++)
        {
            varstr += c + 'a';
            if (c != n - 1)
                varstr += ',';
            vars[c] = c + 'a';
        }
        printf("%s : integer;\nbegin\n  readln(%s);\n", varstr.data(), varstr.data());
        pascal_if_else(vars, 1);
        printf("end.\n");
        if (i != N - 1)
            printf("\n");
    }

    return 0;
}
