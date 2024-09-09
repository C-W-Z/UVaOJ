#include <bits/stdc++.h>
using namespace std;

bool fold(vector<stack<string>> &cards, int idx)
{
    auto &curr = cards[idx];
    if (idx >= 3)
    {
        auto &third = cards[idx - 3];
        if (curr.top()[0] == third.top()[0] || curr.top()[1] == third.top()[1])
        {
            third.push(curr.top());
            curr.pop();
            if (curr.empty())
                cards.erase(cards.begin() + idx);
            idx -= 3;
            return true;
        }
    }
    auto &first = cards[idx - 1];
    if (curr.top()[0] == first.top()[0] || curr.top()[1] == first.top()[1])
    {
        first.push(curr.top());
        curr.pop();
        if (curr.empty())
            cards.erase(cards.begin() + idx);
        idx -= 1;
        return true;
    }
    return false;
}

int main()
{
    string card;
    while (cin >> card)
    {
        if (card == "#")
            break;
        vector<stack<string>> cards(1);
        cards[0].push(card);
        for (int i = 0; i < 51; i++)
        {
            cin >> card;
            cards.push_back(stack<string>());
            cards.back().push(card);
            bool change = true;
            while (change)
            {
                change = false;
                for (int idx = 1; idx < cards.size(); idx++)
                    if (fold(cards, idx))
                    {
                        change = true;
                        break;
                    }
            }
        }
        if (cards.size() == 1)
            printf("%lld pile remaining:", cards.size());
        else
            printf("%lld piles remaining:", cards.size());
        for (auto &&c : cards)
            printf(" %lld", c.size());
        printf("\n");
    }

    return 0;
}
