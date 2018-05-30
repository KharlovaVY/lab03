#include <iostream>
#include <vector>
#include "Temperature.h"

using namespace std;

int
main()
{

    // Ввести несколько значений температуры с клавиатуры
    size_t number_count;
    cerr << "Enter number of input temperatures: ";
    cin >> number_count;

    cerr << "Enter list of temperatures (in form like -10C, 451F, 273K): ";
    vector<Temperature> xs(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> xs[i];
        if (cin.fail()){
            return -1;
        }
        // Преобразовать все температуры к одной шкале - Кельвина
        xs[i].value = convert(xs[i], 'K');
        xs[i].scale = 'K';
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    double min = xs[0].value;
    double max = xs[0].value;
    for (int i = 0; i < number_count; i++) {
        if (xs[i].value < min) {
            min = xs[i].value;
        }
        if (max < xs[i].value) {
            max = xs[i].value;
        }
    }

    vector<size_t> counts(column_count);
    for (int i = 0; i < number_count; i++) {
        size_t column = (size_t)((xs[i].value - min) / (max - min) * column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // ищем интервал с наибольшим количеством элементов
    // Можно было бы считать в предыдущем цикле, но так более наглядно.
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    // Печать гистограммы введенных температур
    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            // Point: код должен быть в первую очередь понятным.
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        // выравнивание гистограммы по правому краю:
        // вначале печатаем (max_count - height) пробелов
        for (size_t i = 0; i < max_count - height; i++) {
            cout << " ";
        }
        // а затем печатаем оставшиеся (height) звездочек
        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}