#include <iostream>
#include <cmath>
using namespace std;

// ===== Завдання: Proc6 =====
// Процедура знаходить кількість цифр C і суму цифр S числа K
void DigitCountSum(int K, int &C, int &S)
{
    if (K == 0) { C = 1; S = 0; return; }

    int last = K % 10;
    C++;
    S += last;

    if (K / 10 != 0)
        DigitCountSum(K / 10, C, S);
}

// ===== Завдання: Proc47 =====
// Функція обчислення X^n через рекурсію (без циклів)
double PowerInt(double X, int n)
{
    if (n == 0) return 1;

    if (n > 0)
        return X * PowerInt(X, n - 1);
    else
        return 1.0 / PowerInt(X, -n);
}

// ===== INTEGER13 =====

// 1) Введення
bool in_ThreeDigit(int &N)
{
    cout << "Введіть тризначне число: ";
    cin >> N;

    if (cin.fail()) return true;
    if (N < 100 || N > 999) return true;

    return false;
}

// 2) Підрахунок
int process_Integer13(int N)
{
    int first = N / 100;
    int lastTwo = N % 100;
    return lastTwo * 10 + first;
}

// 3) Виведення
void out_Integer13(int R)
{
    cout << "Отримане число: " << R << endl;
}

// ===== Процедури задач =====

// Proc6 для 5 чисел
void task_Proc6()
{
    cout << "=== Proc6: DigitCountSum ===" << endl;
    for (int i = 1; i <= 5; i++)
    {
        int K;
        cout << "Введіть число #" << i << ": ";
        cin >> K;

        int C = 0, S = 0;
        DigitCountSum(K, C, S);

        cout << "Кількість цифр = " << C 
             << ", сума = " << S << endl;
    }
}

// Proc47 для 3 пар чисел
void task_Proc47()
{
    cout << "=== Proc47: PowerInt ===" << endl;
    for (int i = 1; i <= 3; i++)
    {
        double X;
        int n;
        cout << "Введіть X та n: ";
        cin >> X >> n;

        cout << "X^n = " << PowerInt(X, n) << endl;
    }
}

// Integer13
void task_Integer13()
{
    int N;

    if (in_ThreeDigit(N)) {
        cout << "Помилка: некоректне число!" << endl;
        return;
    }

    int res = process_Integer13(N);
    out_Integer13(res);
}

// ===== Головне меню =====
void task_Menu()
{
    int choice;

    cout << "===== МЕНЮ =====" << endl;
    cout << "1 — Proc6 (DigitCountSum)" << endl;
    cout << "2 — Proc47 (PowerInt)" << endl;
    cout << "3 — Integer13" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;

    switch (choice)
    {
    case 1: task_Proc6(); break;
    case 2: task_Proc47(); break;
    case 3: task_Integer13(); break;
    }
}

int main()
{
    task_Menu();
    return 0;
}
