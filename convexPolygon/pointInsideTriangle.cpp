#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    float x, y;
};

float calcArea(Point a, Point b, Point c)
{
    return abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

bool isInside(Point a, Point b, Point c, Point p)
{
    float abcArea = calcArea(a, b, c);

    float pbcArea = calcArea(p, b, c);
    float apcArea = calcArea(a, p, c);
    float abpArea = calcArea(a, b, p);

    float eps = 0.0001;
    return abs(abcArea - (pbcArea + apcArea + abpArea)) < eps;
}

int main()
{
    Point a, b, c, p;

    cout << "enter coordinates of triangle vertices:" << endl;
    cout << "vertex a (x y): ";
    cin >> a.x >> a.y;
    cout << "vertex b (x y): ";
    cin >> b.x >> b.y;
    cout << "vertex c (x y): ";
    cin >> c.x >> c.y;

    cout << "enter coordinates of test point p (x y): ";
    cin >> p.x >> p.y;

    if (isInside(a, b, c, p))
    {
        cout << "point is inside the triangle" << endl;
    }
    else
    {
        cout << "point is outside the triangle" << endl;
    }

    return 0;
}
