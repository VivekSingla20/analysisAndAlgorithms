#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

// Calculate the distance of point `p` from the line formed by points `a` and `b`
float distanceFromLine(Point A, Point B, Point P) {
    float numerator = abs((B.y - A.y) * (P.x - A.x) - (B.x - A.x) * (P.y - A.y));
    float denominator = sqrt(pow(B.y - A.y, 2) + pow(B.x - A.x, 2));
    return numerator / denominator;
}

// Find which side the point `p` lies on with respect to line `a-b`
// Returns:
// > 1: left side
// > -1: right side
// > 0: on the line
int findSide(Point a, Point b, Point p) {
    int val = (p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

// Recursive function to find convex hull points on one side of line `a-b`
void findHull(vector<Point>& points, Point a, Point b, int side, vector<Point>& hull) {
    float maxDist = 0;
    int farthestPointIndex = -1;

    // Find the farthest point from the line a-b on the specified side
    for (int i = 0; i < points.size(); i++) {
        float tempDist = distanceFromLine(a, b, points[i]);
        if (findSide(a, b, points[i]) == side && tempDist > maxDist) {
            farthestPointIndex = i;
            maxDist = tempDist;
        }
    }

    // No farthest point, so a and b are part of the convex hull
    if (farthestPointIndex == -1) {
        hull.push_back(a);
        hull.push_back(b);
        return;
    }

    Point farthest = points[farthestPointIndex];

    // recursively find points on the hull
    findHull(points, a, farthest, -findSide(a, farthest, b), hull);
    findHull(points, farthest, b, -findSide(farthest, b, a), hull);
}

vector<Point> quickHull(vector<Point>& allPoints) {
    int n = allPoints.size();
    if (n < 3) return allPoints;

    // finding leftmost and rightmost points
    int minX = 0, maxX = 0;
    for (int i = 1; i < n; i++) {
        if (allPoints[i].x < allPoints[minX].x)
            minX = i;
        if (allPoints[i].x > allPoints[maxX].x)
            maxX = i;
    }

    Point leftMost = allPoints[minX];
    Point rightMost = allPoints[maxX];

    vector<Point> hull;

    // recursively find hull on both sides of the line
    findHull(allPoints, leftMost, rightMost, 1, hull);  // upper part
    findHull(allPoints, leftMost, rightMost, -1, hull); // lower part

    return hull;
}

int main() {
    int numPoints;
    cout << "Enter number of points: ";
    cin >> numPoints;

    vector<Point> inputPoints(numPoints);
    cout << "Enter the points (x y):\n";
    for (int i = 0; i < numPoints; i++) {
        cin >> inputPoints[i].x >> inputPoints[i].y;
    }

    vector<Point> convexHull = quickHull(inputPoints);

    cout << "\nConvex Hull points are:\n";
    for (const Point& p : convexHull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
