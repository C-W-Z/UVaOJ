#include <bits/stdc++.h>
using namespace std;

struct Point
{
public:
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    const bool operator<(const Point &p) const {
        if (y == p.y)
            return x < p.x;
        return y < p.y;
    }
};

Point P0;

// bool min_point(const Point &a, const Point &b)
// {
//     if (a.y == b.y)
//         return a.x < b.x;
//     return a.y < b.y;
// }

inline int dist_square(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline int cross_product(const Point &a, const Point &b, const Point &c) {
    // a->b X a->c
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool counter_clockwise(const Point &a, const Point &b)
{
    int c = cross_product(P0, a, b);
    if (c == 0)
        return dist_square(P0, a) < dist_square(P0, b);
    return c > 0;
}

struct Kingdom
{
    bool destroy = false;
    vector<Point> houses;
    Kingdom() {}
    Kingdom(vector<Point> &_houses): houses(move(_houses)) {}
    bool inside(Point &p)
    {
        for (int i = 1; i < houses.size(); i++)
            if (cross_product(houses[i - 1], houses[i], p) < 0)
                return false;
        return true;
    }
    void try_destroy(Point &p)
    {
        if (destroy)
            return;
        destroy = inside(p);
    }
    double area()
    {
        double sum = 0;
        for (int i = 1; i < houses.size(); i++)
            sum += (houses[i - 1].x * houses[i].y) - (houses[i].x * houses[i - 1].y);
        return sum / 2;
    }
};

int main()
{
    ios::sync_with_stdio();
    cin.tie(NULL);

    vector<Kingdom> kingdoms;
    int N;
    while (cin >> N)
    {
        if (N == -1)
            break;
        vector<Point> houses(N);
        for (int i = 0; i < N; i++)
        {
            int x, y;
            cin >> x >> y;
            houses[i] = Point(x, y);
        }

        // https://en.wikipedia.org/wiki/Graham_scan

        // P0 = *min_element(houses.begin(), houses.end(), min_point);
        P0 = *min_element(houses.begin(), houses.end());
        sort(houses.begin(), houses.end(), counter_clockwise);

        vector<Point> poly(N + 1);
        int poly_n = 0;
        for (auto &&h : houses)
        {
            while (poly_n > 1 && cross_product(poly[poly_n - 2], poly[poly_n - 1], h) <= 0)
                poly_n--;
            poly[poly_n++] = h;
        }
        poly[poly_n++] = P0;
        poly.resize(poly_n);

        kingdoms.push_back(Kingdom(poly));
    }

    Point missle;
    while (cin >> missle.x >> missle.y)
        for (Kingdom &k : kingdoms)
            k.try_destroy(missle);

    double space = 0;
    for (auto &&k : kingdoms)
        if (k.destroy)
            space += k.area();

    printf("%.2f\n", space);

    return 0;
}
