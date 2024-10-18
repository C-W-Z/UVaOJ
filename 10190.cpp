#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    vector<int> seq;
    while (cin >> a >> b)
    {
        if (a == 0 || b == 0 || b == 1 || a % b != 0)
        {
            printf("Boring!\n");
            continue;;
        }
        seq.clear();
        seq.push_back(a);
        bool boring = false;
        while (a > 1)
        {
            a /= b;
            if (a != 1 && a % b != 0)
            {
                boring = true;
                break;
            }
            seq.push_back(a);
        }
        if (boring || seq.size() <= 1)
            printf("Boring!\n");
        else
        {
            for (size_t i = 0; i < seq.size(); i++)
            {
                if (i == seq.size() - 1)
                    printf("%d\n", seq[i]);
                else
                    printf("%d ", seq[i]);
            }
        }
    }

    return 0;
}
