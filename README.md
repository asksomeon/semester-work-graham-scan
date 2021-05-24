# Алгоритм Грэхема

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)

**_Измените status badge сверху для отображения статуса сборки вашего проекта._**

`Actions > CMake > ... > Create status badge`

Алгоритм Грэхема

Это алгоритм построения минимальной выпуклой оболочки. Используется в различных программах при построении поверхностей, при расчете площадей, при строительстве объектов. То есть там, где требуется рассчитать область и где важен ее размер.

Алгоритм заботает за O(n*log(n)). Это теоретическая сложность.

## Петрова Александра, Городскова Анастасия

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Петрова       | 50        |                       |
| Городскова    | 50        |                       |
| Google        | 100       | все еще самый главный |

**Девиз команды**
> Мы учимся в прекрасном здании, из него можно выйти через окно! С 13 этажа (фактически 14...)

## Структура проекта

- [`src`](src)/[`include`](include) - реализация алгоритма (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности алгоритма;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов;

## Требования (Prerequisites)

Рекомендуемые требования:
С++ компилятор c поддержкой стандарта C++17 (например, GNU GCC 8.1.x и выше).

Система автоматизации сборки CMake (версия 3.20.2 и выше).

Интерпретатор Python (версия 3.9.5 и выше).

Рекомендуемый объем оперативной памяти - не менее 16 ГБ.

Свободное дисковое пространство объемом ~ 16 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

### Пример (Windows(Мака нету...))

#### Сборка проекта


Склонируйте проект к себе на устройство через Git for Windows (либо используйте возможности IDE): Берёте это: https://vk.com/away.php?to=https%3A%2F%2Fgithub.com%2Fasksomeon%2Fsemester-work-graham-scan.git&cc_key= , копируете(Ctrl+С).

Запускаете, допустим, CLion, там должна быть кнопочка Clone либо же в панели наверху находите Git, нажимаете, видите Clone...

Вставляете URL и нажимаете на кнопочку Clone.

Если нужны тесты, то в semester-work-graham-scan находите benchmark и demo_benchmark. Там все написано. Если же просто хотите запустить проект, то в semester-work-graham-scan находите main.

Тестовые данные были сгенерированы на языке python. Запускаются из файла с аналогичным названием.

Тестовые данные представлены в CSV формате.

Еще про тесты. Так как этот алгоритм обрабатывает точки, то нам нужны такие, которые не будут повторяться. Поэтому, если Вы сгенерировали набор данных и, магия, у Вас не сработал алгоритм, это не значит, что Вы его сломали, скорее всего... это значит, что где-то какая-то точка повторяется. И он не знает, как с ней поступить. Мы могли бы это обработать, нооооо... Это, как бы так лучше выразиться, лишает данный алгоритм смысла, так как он призван находить оболочку во множестве точек, а не находить повторяющиеся.

По названию директории `/dataset/data/` можно понять, что здесь хранятся наборы данных для контрольных тестов по
**добавлению** элементов в структуру данных. Названия файлов `100.csv`. `5000000.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). Так как у нас точки, а у них есть координаты, то там две папочки с ординатами - ord, та, которая ось OY и абсциссами - abs, ось OX.

#### Контрольные тесты (benchmarks)
 Наборы данных должны находиться в папке семестровой
работы на [Google Drive](https://drive.google.com/drive/folders/1RiNhZZqu3mAZXgP5d_QFWymc9NMz023N?authuser=0).

Результаты замеров записываются в файл!!! (А то вдруг испугаетесь))

## Источники

https://habr.com/ru/post/144921/
https://e-maxx.ru/algo/convex_hull_graham
https://ru.wikipedia.org/wiki/Алгоритм_Грэхема

