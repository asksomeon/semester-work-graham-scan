#include <iostream>

#include "data_structure.hpp"

using namespace std;

int main() {

    // Обьясняю. Нам нужен массив с точками (мы его уже задали, как пример). Если же Вы хотите добавить еще точек,то { x, y } (x - координата по оси OX, y - координата по OY)
    // Для того, чтобы запустить данный алгоритм нам нужно вставить наш массив и формулу (n) в метод (15 строка)
    itis::Point points[] = { { 0, 3 }, { 1, 1 }, { 2, 2 }, { 4, 4 }, { 0, 0 },
                       { 1, 2 }, { 3, 1 }, { 3, 3 } };
    int n = sizeof(points) / sizeof(points[0]);
    cout << "The points in the convex hull are: \n";
    convexHull(points, n);
    return 0;

}
