#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
};

float calcArea(vector<Point> &points, int n)
{
    float area = 0.0;

    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += (points[i].x * points[j].y);
        area -= (points[j].x * points[i].y);
    }

    area = abs(area) / 2.0;
    return area;
}

int calcDet(vector<vector<int>> &matrix)
{
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

int getOrientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

Point p0;
bool compare(Point p1, Point p2)
{
    int o = getOrientation(p0, p1, p2);
    if (o == 0)
        return (pow(p1.x - p0.x, 2) + pow(p1.y - p0.y, 2)) <
               (pow(p2.x - p0.x, 2) + pow(p2.y - p0.y, 2));

    return (o == 2);
}

vector<Point> findHull(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
        return points;

    int minY = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < minY) || (minY == y && points[i].x < points[minIdx].x))
        {
            minY = points[i].y;
            minIdx = i;
        }
    }

    swap(points[0], points[minIdx]);
    p0 = points[0];

    sort(points.begin() + 1, points.end(), compare);

    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && getOrientation(p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++;
    }

    if (m < 3)
        return points;

    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    for (int i = 3; i < m; i++)
    {
        while (hull.size() > 1 && getOrientation(hull[hull.size() - 2],
                                                 hull[hull.size() - 1],
                                                 points[i]) != 2)
            hull.pop_back();

        hull.push_back(points[i]);
    }

    return hull;
}

int main()
{
    int n;
    cout << "enter number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "enter the coordinates of points (x y):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = findHull(points);

    cout << "points in convex hull:" << endl;
    for (Point p : hull)
    {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    float area = calcArea(hull, hull.size());
    cout << "area of convex polygon: " << area << endl;

    return 0;
}
