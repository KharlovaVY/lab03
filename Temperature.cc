//
// файл Temperature.cc с реализациями функций, объявленных в Temperature.h
//
#include "Temperature.h"
using namespace std;

// оператор ввода температуры из текстового потока в формате:
// 0K (по Кельвину), -42C (по Цельсию), 451F (по Фаренгейту)
istream&
operator>>(istream& in, Temperature& Temp) {
    in.setstate(ios_base::goodbit);
    in >> Temp.value;
    in >> Temp.scale;
    // Проверить правильность формата введенных температур
    if (check(Temp)!=0){
        cout << "Wrong temperature format: " << Temp.value << Temp.scale << endl;
        in.setstate(ios_base::failbit);
    }
}

// функция, преобразующая температуру input в шкалу to
double
convert(const Temperature& input, char to) {
    double Kelvins;
    switch (input.scale) {
    case 'K':
    case 'k':
        Kelvins = input.value;
        break;
    case 'C':
    case 'c':
        Kelvins = input.value + 273.15;
        break;
    case 'F':
    case 'f':
        Kelvins = 5 * (input.value - 32) / 9 + 273.15;
        break;

    }
    switch (to) {
    case 'K':
        return Kelvins;
        break;
    case 'C':
        return Kelvins - 273.15;
        break;
    case 'F':
        return (9 * (Kelvins - 273.15)) / 5 + 32;
        break;

    }
}

// оператор «меньше» для двух температур в произвольных шкалах.
// сравнение температур происходит в одной шкале - в Кельвинах
bool
operator<(const Temperature& lhs, const Temperature& rhs) {
    double lhs_K, rhs_K;
    lhs_K = convert(lhs, 'K');
    rhs_K = convert(rhs, 'K');
    return lhs_K < rhs_K;
    //return convert(lhs,'K')< convert(rhs,'K');
}

// проверка корректности температуры при вводе:
// шкала может быть только C, F, K
// температура в Кельвинах всегда положительна.
// Функция возвращает 0, если формат температуры правильный,
//                    1, если шкала не равна C, F, K
//                    2, если температура меньше 0K
int check(const Temperature& Temp){
    if(Temp.scale!='K' && Temp.scale!='C' && Temp.scale!='F' && Temp.scale!='k' && Temp
            .scale!='f' && Temp.scale!='c'){
        return 1;
    }
    if (convert(Temp,'K')<0){
        return 2;
    }
    return 0;
}