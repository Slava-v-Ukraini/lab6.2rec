#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i = 0)
{
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

void Print(int* a, const int size, int i = 0)
{
    if (i < size) {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int Sum(int* a, const int size, int i = 0)
{
    if (i < size) {
        return a[i] + Sum(a, size, i + 1);
    }
    return 0;
}

double AverageOdd(int* a, const int size, int i = 0, int sum = 0, int count = 0)
{
    if (i < size) {
        if (a[i] % 2 != 0) {  // перевірка на непарність
            sum += a[i];
            count++;
        }
        return AverageOdd(a, size, i + 1, sum, count);
    }
    if (count > 0) {
        return (sum * 1.0) / count;
    }
    else {
        return 0;
    }
}

void ModifyArray(int* a, const int size, int i = 0)
{
    if (i < size) {
        if (a[i] < 0) {  // заміна від'ємних елементів на 0
            a[i] = 0;
        }
        ModifyArray(a, size, i + 1);
    }
}

int main() {
    srand((unsigned)time(NULL));

    const int n = 25;
    int a[n];
    int Low = -40;
    int High = 90;

    Create(a, n, Low, High);
    cout << "Array: ";
    Print(a, n);

    int sum = Sum(a, n);
    cout << "Sum = " << sum << endl;

    double avg = AverageOdd(a, n);
    cout << "Average = " << avg << endl;

    ModifyArray(a, n);
    cout << "Modified array: ";
    Print(a, n);

    return 0;
}
