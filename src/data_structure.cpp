#include "data_structure.hpp"
#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

// файл с определениями

namespace itis {

  Point p0;

// Служебная функция для поиска ближайшей вершины в стеке
  Point nextToTop(stack<Point> &S)
  {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
  }

// Свап двух вершин
  int swap(Point &p1, Point &p2)
  {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
  }

// Возвращает квадрат расстояния между двумя вершинами р1 и р2
  int dist(Point p1, Point p2)
  {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  }

  int orientation(Point p, Point q, Point r)
  {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
      return 0;
    return (val > 0) ? 1 : 2;
  }

//Сортировка массива точек, относительно первой точки. Сортируется по высоте
  int compare(const void *vp1, const void *vp2)
  {
    Point *p1 = (Point *) vp1;
    Point *p2 = (Point *) vp2;

    // Находим ориентацию точки в пространстве относительно двух других
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
      return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
  }

// Выводит выпуклую оболочку множества из n точек. Основой метод программы! Его вызываем в мейне!!!
  void convexHull(Point points[], int n)
  {
    //Находим самую нижнюю точку, "первую" ( у нее минимальное значение по оси ординат)
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
      int y = points[i].y;

      // Если у нас их несколько, то берем самую левую
      if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        ymin = points[i].y, min = i;
    }

    // Поместим самую нижнюю точку в первую позицию
    swap(points[0], points[min]);

    // Сортируем n-1 точек относительно первой точки. Выбираем точку p1
    //перед p2 в отсортированном выводе, если p2 имеет больший полярный угол (в направлении против
    //часовой стрелки), чем p1
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    //Создаем пустой стек и кладем в него первые три точки
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Обрабатываем оставшиеся n-3 точки
    for (int i = 3; i < n; i++)
    {
      // Удаляем вершину, если при добавлении новой точки мы делаем поворот направо
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
        S.pop();
      S.push(points[i]);
    }

    // Теперь в стеке есть все точки выпуклой оболочки. Выводим их в консоль
    while (!S.empty())
    {
      Point p = S.top();
      cout << "(" << p.x << ", " << p.y << ")" << endl;
      S.pop();
    }
  }
}  // namespace itis