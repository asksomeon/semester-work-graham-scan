#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main() {
  /* Так-то тестовые данные уже сгенерированы, но если нужны новые, то переходим в dataset, удаляем три папочки:
   * insert, remove и search. Переходим в  generate_csv_dataset.py, нажимаем на зеленую стрелочку. Оп, появились.
   * Если не нужны, то смотрим ниже.
   */
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;


  itis::Point points[100] = {};

  string abs_coords;
  string ord_coords;

  // Чтение файла
  auto input_file_x = ifstream(path + "/abs/data(100).txt");
  auto input_file_y = ifstream(path + "/ord/data(100).txt");


  if (input_file_x && input_file_y) {

    //извлекаем все данные из файла и записываем в строку (это второй аргумент)
    getline(input_file_x, abs_coords);
    getline(input_file_y, ord_coords);

    string x_coord;
    string y_coord;

    // делаем из строки стрим
    istringstream str_x(abs_coords);
    istringstream str_y(ord_coords);

    int count = 0;

    //сплитим строку и записываем в массив числа, полученные из строки
    while (getline(str_x, x_coord, ' ') && getline(str_y, y_coord, ' ')) {
      points[count] = {stoi(x_coord), stoi(y_coord)};
      count++;
    }
  }
  //закрытие стрима
  input_file_x.close();
  input_file_y.close();

  //создаем файл с замерами времени
  ofstream out(path + "/answer(100).txt", ios::app);

  //здесь происходят замеры времени и запись в файлик
  for(int i = 0; i < 10; i++) {
    
    const auto time_point_before = chrono::steady_clock::now();
    int n = sizeof(points) / sizeof(points[0]);

    convexHull(points, n);

    const auto time_point_after = chrono::steady_clock::now();
    const auto time_diff = time_point_after - time_point_before;
    const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();


    if(out.is_open()){
      out<<time_elapsed_ns<<endl;
    }
  }

  //эта хрень нужна, чтобы при повторном запуске можно было разделять старые и новые данные
  out<<"----------------------------------"<<endl;
  out.close();
  return 0;
}