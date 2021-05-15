// Marta Dziêgielewska
// Shortest distance between two points
// 14.01.2020

#include <iostream>
#include <math.h>
#include <cfloat>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Point {
    public: int x, y;
};

int compareX(const void* a, const void* b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    return (p1->y - p2->y);
}

float distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// the shortest distance in P[] n x n
float brute_force(Point P[], int n) {
    float min = 9999;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (distance(P[i], P[j]) < min) {
                min = distance(P[i], P[j]);
            }
        }
    }
    return min;
}

// distance between the closes points on the strip
float strip_closest(Point strip[], int size, float d) {
    float min = d;
    for (int i=0; i<size; ++i) {
        for (int j=i+1; j<size && (strip[j].y - strip[i].y) < min; ++j) {
            if (distance(strip[i], strip[j]) < min) {
                min = distance(strip[i], strip[j]);
            }
        }
    }
    return min;
}

// finding smallest distance in P[] sorted according to x coordinate
float closest_util(Point PX[], Point PY[], int n) {
    if (n <= 3)
        return brute_force(PX, n);

    int mid = n/2;
    Point middle_point = PX[mid];

    // separating the points
    // assuming all x coordinates are distinct
    // sorted points on the left
    Point PY_L[mid];
    // sorted points on the right
    Point PY_R[n-mid];

    int li = 0, ri = 0;
    for (int i=0; i<n; i++) {
      if (PY[i].x < middle_point.x)
         PY_L[li++] = PY[i];
      else
         PY_R[ri++] = PY[i];
    }

    float distance_left = closest_util(PX, PY_L, mid);
    float distance_right = closest_util(PX+mid, PY_R, n-mid);
    float d = min(distance_left, distance_right);

    // array of points close to the like passing through the middle point
    Point strip[n];
    int j=0;
    for (int i=0; i<n; i++) {
        if (abs(PY[i].x - middle_point.x) < d) {
            strip[j] = PY[i];
            j++;
        }
    }
    return min(d, strip_closest(strip, j, d));
}

float closest(std::vector<Point> P, int n) {
    // PX and PY are sorted
    Point PX[n];
    Point PY[n];
    for (int i=0; i<n; i++) {
        PX[i] = P[i];
        PY[i] = P[i];
    }
    qsort(PX, n, sizeof(Point), compareX);
    qsort(PY, n, sizeof(Point), compareY);

    // recursion to find the smallest distance
    return closest_util(PX, PY, n);
}

int main()
{
	std::vector<Point> P;
	for(int i=0 ; i<100 ; i++) {
        P.push_back({rand()/100, rand()/100});
	}
    int n =P.size();

    cout << "The shortest distance: " << closest(P, n-1);
    return 0;
}
