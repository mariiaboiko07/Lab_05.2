// Lab_05.2.cpp
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 1 (1-й спосіб: void-функції)

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, dx, eps, s = 0;
    int n = 0;

    cout << "xp  = "; cin >> xp;
    cout << "xk  = "; cin >> xk;
    cout << "dx  = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x"
        << " |" << setw(17) << "ln((x+1)/(x-1))"
        << " |" << setw(13) << "S"
        << " |" << setw(8) << "n"
        << " |" << endl;
    cout << "-------------------------------------------------------" << endl;

    double x = xp;
    while (x <= xk + dx / 2.0)
    {
        S(x, eps, n, s);

        cout << "|" << setw(8) << setprecision(2) << x
            << " |" << setw(17) << setprecision(6) << log((x + 1.0) / (x - 1.0))
            << " |" << setw(13) << setprecision(6) << s
            << " |" << setw(8) << n
            << " |" << endl;

        x += dx;
    }
    cout << "-------------------------------------------------------" << endl;

    return 0;
}

void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = 1.0 / x; // Перший доданок a_0 для Варіанту 1
    s = a;              // Початкове значення суми в дужках

    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);

    s *= 2.0;           // Враховуємо множник 2 за формулою Варіанту 1
}

void A(const double x, const int n, double& a)
{
    double R = (2.0 * n - 1.0) / ((2.0 * n + 1.0) * x * x); // Коефіцієнт R для Варіанту 1
    a *= R;
}