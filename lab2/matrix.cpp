#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
// include <conio.h> - устаревшая библиотека, нет на MacOS.
#include <stdio.h>
#include "m_func.h"

using namespace std;
#define N 5

int main(void) {
    srand(static_cast<unsigned>(time(nullptr))); // для рандома от времени
    float m[N][N];
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            m[i][j] = rand()/100.;
        }
    }
      

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << setw(14) << fixed << setprecision(3) << m[i][j] << ' ';
        cout << endl;
    }

    cout << "\nМинимальный элемент: " << matrix_min(m) << endl;
    cout << "Максимальный элемент: " << matrix_max(m) << endl;
   
    cout << "\nМинимальный элемент нижнего треугольника без диагонали: " << matrix_bottom_triangle_min(m) << endl;
    cout << "Максмальный элемент нижнего треугольника без диагонали: " << matrix_bottom_triangle_max(m) << endl;
   
    cout << "\nМинимальный элемент верхнего треугольника без диагонали: " << matrix_top_triangle_min(m) << endl;
    cout << "Максмальный элемент верхнего треугольника без диагонали: " << matrix_top_triangle_max(m) << endl;
   
    cout << "\nМинимальный элемент главной диагонали: " << matrix_main_diag_min(m) << endl;
    cout << "Максмальный элемент главной диагонали: " << matrix_main_diag_max(m) << endl;

    cout << "\nМинимальный элемент второстепенной диагонали: " << matrix_secondary_diag_min(m) << endl;
    cout << "Максмальный элемент второстепенной диагонали: " << matrix_secondary_diag_max(m) << endl;

    cout << "\nСреднее арифметическое всех элементов: " << matrix_avg(m) << endl;
    cout << "Среднее арифметическое нижнетреугольной части: " << matrix_bottom_triangle_avg(m) << endl;
    cout << "Среднее арифметическое верхнетреугольной части: " << matrix_top_triangle_avg(m) << endl;

    float row_sums[N];
    float col_sums[N];
    float row_mins[N];
    float col_mins[N];

    // Заполняем выходные массивы по строкам и столбцам
    matrix_row_sums(m, row_sums);
    matrix_col_sums(m, col_sums);
    matrix_row_mins(m, row_mins);
    matrix_col_mins(m, col_mins);

    cout << "\nСуммы строк: ";
    for (i = 0; i < N; ++i) {
        cout << row_sums[i] << ' ';
    }
    cout << endl;

    cout << "Суммы столбцов: ";
    for (i = 0; i < N; ++i) {
        cout << col_sums[i] << ' ';
    }
    cout << endl;

    cout << "Минимальные значения строк: ";
    for (i = 0; i < N; ++i) {
        cout << row_mins[i] << ' ';
    }
    cout << endl;

    cout << "Минимальные значения столбцов: ";
    for (i = 0; i < N; ++i) {
        cout << col_mins[i] << ' ';
    }
    cout << endl;

    // getchar();
    return 0;
}