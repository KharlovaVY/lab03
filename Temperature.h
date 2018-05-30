//
// заголовочный файл Temperature.h с определениями шкалы и температуры,
// а также объявлениями операторов над ними и функции преобразования
//

#ifndef LAB01_TEMPERATURE_H
#define LAB01_TEMPERATURE_H
#include <iostream>
#include <sstream>
using namespace std;

// тип данных для температуры и шкалы
struct Temperature {
    double value;
    char scale;
};

// оператор ввода температуры из текстового потока в формате:
// 0K (по Кельвину), -42C (по Цельсию), 451F (по Фаренгейту)
istream& operator>>(istream& in, Temperature& Temp);

// функция, преобразующая температуру input в шкалу to
double convert(const Temperature& input, char to);

// оператор «меньше» для двух температур в произвольных шкалах.
bool operator<(const Temperature& lhs, const Temperature& rhs);

// проверка корректности температуры при вводе
int check(const Temperature& Temp);
#endif //LAB01_TEMPERATURE_H
