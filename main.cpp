#include <iostream>
using namespace std;
int main() {


//задание 1
    cout << "   Задание 1" << endl;
    cout << "bool        - " << sizeof(bool)        << " байт" << endl;
    cout << "char        - " << sizeof(char)        << " байт" << endl;
    cout << "short int   - " << sizeof(short int)   << " байт" << endl;
    cout << "int         - " << sizeof(int)         << " байт" << endl;
    cout << "long int    - " << sizeof(long int)    << " байт" << endl;
    cout << "long long   - " << sizeof(long long)   << " байт" << endl;
    cout << "float       - " << sizeof(float)       << " байт" << endl;
    cout << "double      - " << sizeof(double)      << " байт" << endl;
    cout << "long double - " << sizeof(long double) << " байт" << endl;


//задание 2
    cout << "   Задание 2" << endl;
    int value;
    cout << "Введите целое число: ";
    cin >> value;
    if (cin.fail()) {
        cout << "Введено неверное целое число!!" << endl;
        return 1;
    }
    cout << "Двоичное представление: ";
    unsigned int u_value = value;
    for (int i=31;i>=0;--i){
        int bit=(u_value>>i)&1;
        cout << bit;
        if (i==31){              //разделитель
            cout<<"  ";
        }
    }
    cout << '\n';


//задание 3
    cout << "   Задание 3" << endl;
    union {
        float f;
        unsigned int u;
    } fu;
    cout << "Введите дробное число: ";
    cin >> fu.f;
    if (cin.fail()) {
        cout << "Введено неверное дробное число!" << endl;
        return 1;
    }
    cout << "float: ";
    for (int i = 31; i >= 0; --i) {
        int bit = (fu.u >> i) & 1;
        cout << bit;
        if (i == 31) {      //разделитель знаковый ьит
            cout << "  "; 
        }
        if (i == 23) {      //разделитель между полем порядка и мантиссой
            cout << "  "; 
        }
    }
    cout << '\n';


//задание 4
    cout << "   Задание 4" << endl;
    union {
    double d;                  
    unsigned long long u_long; 
    } du;
    cout << "Введите дробное число: ";
    cin >> du.d;
    cout << "double: ";
    if (cin.fail()) {
        cout << "Введено неверное дробное число!" << endl;
        return 1;
    }
    for (int i = 63; i >= 0; --i) {
        int bit = (du.u_long >> i) & 1; 
        cout << bit;
        if (i == 63) {
            cout << "  ";
        }
        if (i == 52) {
            cout << "  ";
        }
    }
    cout << '\n';


//задание 5
    cout << "   Задание 5" << endl;
    int type, pos, op;

    cout << "Выберите тип числа (1 - int, 2 - float, 3 - double): ";
    cin >> type;
    if (cin.fail() || type < 1 || type > 3) {
        cout << "неверный выбор типа!" << endl;
        return 1;
    }
    //int
    if (type == 1) {
        int x;
        cout << "Введите число int: ";
        cin >> x;
        if (cin.fail()) { cout << "Ошибка ввода!"; return 1; }

        cout << "Введите номер бита (0..31): ";
        cin >> pos;
        if (cin.fail() || pos < 0 || pos > 31) { cout << "Ошибка ввода!"; return 1; }

        cout << "Операция (1 - установить |, 2 - сбросить &, 3 - инвертировать ^): ";
        cin >> op;
        if (cin.fail() || op < 1 || op > 3) { cout << "Ошибка ввода!"; return 1; }

        unsigned int u = x;
        cout << "До:    ";
        for (int i = 31; i >= 0; i--) { cout << ((u >> i) & 1); if (i == 31) cout << "  "; }
        cout << " = " << x << endl;

        unsigned int mask = 1u << pos;
        if (op == 1)      u |= mask;
        else if (op == 2) u &= ~mask;
        else              u ^= mask;

        cout << "После: ";
        for (int i = 31; i >= 0; i--) { cout << ((u >> i) & 1); if (i == 31) cout << "  "; }
        cout << " = " << (int)u << endl;
    }
    //float
    else if (type == 2) {
        union { float f; unsigned int u; } x;
        cout << "Введите число float: ";
        cin >> x.f;
        if (cin.fail()) { cout << "Ошибка ввода!"; return 1; }

        cout << "Введите номер бита (0..31): ";
        cin >> pos;
        if (cin.fail() || pos < 0 || pos > 31) { cout << "Ошибка ввода!"; return 1; }

        cout << "Операция (1 - установить |, 2 - сбросить &, 3 - инвертировать ^): ";
        cin >> op;
        if (cin.fail() || op < 1 || op > 3) { cout << "Ошибка ввода!"; return 1; }

        cout << "До:    ";
        for (int i = 31; i >= 0; i--) { cout << ((x.u >> i) & 1); if (i == 31 || i == 23) cout << "  "; }
        cout << " = " << x.f << endl;

        unsigned int mask = 1u << pos;
        if (op == 1)      x.u |= mask;
        else if (op == 2) x.u &= ~mask;
        else              x.u ^= mask;

        cout << "После: ";
        for (int i = 31; i >= 0; i--) { cout << ((x.u >> i) & 1); if (i == 31 || i == 23) cout << "  "; }
        cout << " = " << x.f << endl;
    }
    // double
    else if (type == 3) {
        union { double d; unsigned long long u; } x;
        cout << "Введите число double: ";
        cin >> x.d;
        if (cin.fail()) { cout << "Ошибка ввода!"; return 1; }

        cout << "Введите номер бита (0..63): ";
        cin >> pos;
        if (cin.fail() || pos < 0 || pos > 63) { cout << "Ошибка ввода!"; return 1; }

        cout << "Операция (1 - установить |, 2 - сбросить &, 3 - инвертировать ^): ";
        cin >> op;
        if (cin.fail() || op < 1 || op > 3) { cout << "Ошибка ввода!"; return 1; }

        cout << "До:    ";
        for (int i = 63; i >= 0; i--) { cout << ((x.u >> i) & 1); if (i == 63 || i == 52) cout << "  "; }
        cout << " = " << x.d << endl;

        unsigned long long mask = 1ULL << pos;
        if (op == 1)      x.u |= mask;
        else if (op == 2) x.u &= ~mask;
        else              x.u ^= mask;

        cout << "После: ";
        for (int i = 63; i >= 0; i--) { cout << ((x.u >> i) & 1); if (i == 63 || i == 52) cout << "  "; }
        cout << " = " << x.d << endl;
    }


//идз
    cout << "   идз(сделать нечётным)" << endl;
    int number;
    cout << "Введите целое число: ";
    cin >> number;
    if (cin.fail()) {
        cout << "Введено неверное число!" << endl;
        return 1;
    }
    int result = number | 1; 
    cout << "Результат: " << result << endl;
return 0; 
}