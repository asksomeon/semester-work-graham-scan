#include <iostream>

#include "data_structure.hpp"

using namespace std;

int main() {

    itis::Point points[] = { { 0, 3 }, { 1, 1 }, { 2, 2 }, { 4, 4 }, { 0, 0 },
                       { 1, 2 }, { 3, 1 }, { 3, 3 } };
    int n = sizeof(points) / sizeof(points[0]);
    cout << "The points in the convex hull are: \n";
    convexHull(points, n);
    return 0;

}