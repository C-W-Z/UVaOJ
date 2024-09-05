#include <bits/stdc++.h>
using namespace std;

struct Coef
{
    int m; // magnitude
    int x; // power of x
    int y; // power of y
};

vector<Coef> get_poly(string &str)
{
    vector<Coef> poly;
    Coef c = {1, 0, 0};
    bool is_x = false, is_y = false;
    int digit_start = -1;
    size_t i = 0;
    for (; i < str.size(); i++)
    {
        if (digit_start == -1 && isdigit(str[i]))
            digit_start = i;
        else if (digit_start != -1 && !isdigit(str[i]))
        {
            int n = stoi(str.substr(digit_start, i - digit_start));
            // printf("[%d %lld] %d [%d %d]\n", digit_start, i, n, is_x, is_y);
            if (is_x)
                c.x += n;
            else if (is_y)
                c.y += n;
            else
                c.m *= n;
            is_x = false, is_y = false;
            digit_start = -1;
        }
        if (i > 0 && !isdigit(str[i]))
        {
            if (str[i - 1] == 'x')
            {
                c.x = 1;
                is_x = false, is_y = false;
            }
            else if (str[i - 1] == 'y')
            {
                c.y = 1;
                is_x = false, is_y = false;
            }
        }
        if (str[i] == 'x')
            is_x = true;
        if (str[i] == 'y')
            is_y = true;
        if (str[i] == '-')
        {
            if (i != 0)
                poly.push_back(c);
            c = {-1, 0, 0};
            is_x = false, is_y = false;
            int digit_start = -1;
        }
        if (str[i] == '+')
        {
            if (i != 0)
                poly.push_back(c);
            c = {1, 0, 0};
            is_x = false, is_y = false;
            int digit_start = -1;
        }
    }
    if (digit_start != -1)
    {
        int n = stoi(str.substr(digit_start, i - digit_start));
        // printf("[%d %lld] %d [%d %d]\n", digit_start, i, n, is_x, is_y);
        if (is_x)
            c.x += n;
        else if (is_y)
            c.y += n;
        else
            c.m *= n;
        poly.push_back(c);
    }
    else if (i > 0)
    {
        if (str[i - 1] == 'x')
            c.x = 1;
        else if (str[i - 1] == 'y')
            c.y = 1;
        poly.push_back(c);
    }

    return poly;
}

vector<Coef> multiply_poly(vector<Coef> &poly1, vector<Coef> &poly2)
{
    vector<Coef> poly;
    for (auto &&c1 : poly1)
        for (auto &&c2 : poly2)

            poly.push_back({c1.m * c2.m, c1.x + c2.x, c1.y + c2.y});
    sort(poly.begin(), poly.end(), [](Coef &a, Coef &b) {
        if (a.x == b.x)
            return a.y < b.y;
        return a.x > b.x;
    });
    for (size_t i = 0; i < poly.size() - 1; i++)
    {
        if (poly[i + 1].x == poly[i].x && poly[i + 1].y == poly[i].y)
        {
            poly[i].m += poly[i + 1].m;
            poly.erase(poly.begin() + i + 1);
        }
    }
    return poly;
}

void print_poly(vector<Coef> &poly)
{
    string upper, lower;
    char num[16];
    for (size_t i = 0; i < poly.size(); i++)
    {
        Coef &c = poly[i];
        if (c.m == 0)
            continue;
        if (c.m < 0)
        {
            if (i == 0)
            {
                upper += ' ';
                lower += '-';
            }
            else
            {
                upper += "   ";
                lower += " - ";
            }
            c.m *= -1;
        }
        else if (c.m > 0 && i != 0)
        {
            upper += "   ";
            lower += " + ";
        }
        if (c.m != 1 || (c.x == 0 && c.y == 0))
        {
            sprintf(num, "%d", c.m);
            for (char *ptr = num; *ptr != '\0'; ptr++)
            {
                upper += ' ';
                lower += *ptr;
            }
        }
        if (c.x > 0)
        {
            upper += ' ';
            lower += 'x';
            if (c.x > 1)
            {
                sprintf(num, "%d", c.x);
                for (char *ptr = num; *ptr != '\0'; ptr++)
                {
                    upper += *ptr;
                    lower += ' ';
                }
            }
        }
        if (c.y > 0)
        {
            upper += ' ';
            lower += 'y';
            if (c.y > 1)
            {
                sprintf(num, "%d", c.y);
                for (char *ptr = num; *ptr != '\0'; ptr++)
                {
                    upper += *ptr;
                    lower += ' ';
                }
            }
        }
    }

    if (upper.empty() && lower.empty())
    {
        // upper = " ";
        lower = "0";
    }

    printf("%s\n", upper.data());
    printf("%s\n", lower.data());
}

int main()
{
    string poly_str;
    while (cin >> poly_str)
    {
        if (poly_str == "#")
            break;
        vector<Coef> poly1 = get_poly(poly_str);
        cin >> poly_str;
        vector<Coef> poly2 = get_poly(poly_str);
        vector<Coef> poly3 = multiply_poly(poly1, poly2);
        print_poly(poly3);
    }

    return 0;
}
