#pragma once
#include <cstddef>
#include <iostream>
using namespace std;

/**
 * Функция для вычисления минимума в матрице
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return минимальный элемент
 */
inline float matrix_min(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }

    // первый элемент матрицы
    float min = matrix[0];

    /**
     * Так как двумерные массивы хранятся в памяти как одномерный массив, 
     * а мы получаем указатель на матрицу в памяти, то можем работать с ней как с одномерным 
     * массивом и вычислить минимум пройдясь по массиву за линиию
     * В памяти двумерные массивы 2d[i,j] хранятся как 1d[i * columns + j]
     */
    size_t total = rows * colums;

    for (size_t i = 0; i < total; i++) {
        float value = matrix[i];
        if (value < min) {
            min = value;
        }
    }

    return min;

}


/**
 * Перегрузка, для того чтобы работать с матрицами любого размера, без явной передачи размера
 * @param matrix - матрица
 * @return минимальный элемент
 */
template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_min(float (&matrix)[ROWS][COLUMS]) {
    return matrix_min(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция для вычисления максимума в матрице
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return максимальный элемент
 */
inline float matrix_max(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }
    float max = matrix[0];

    // можно получить размер массива - sizeof(matrix),
    // а можно посчитать количество элементов в матрице
    size_t total = colums * rows;

    for (size_t i = 0; i < total; i++) {
        float value = matrix[i];
        if (value > max) {
            max = value;
        }
    }

    return max;
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_max(float (&matrix)[ROWS][COLUMS]) {
    return matrix_max(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения минимального элемента в нижнетреугольной части матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return минимальный элемент
 */
inline float matrix_bottom_triangle_min(float* matrix, size_t rows, size_t colums) {
    /*
    Если у нас матрица m[4][4], а представление в памяти M
        0  1  2  3  
       -----------
    0 | 4  5  6  2  
    1 | 2  3  4  5  
    2 | 7  8  9  1  
    3 | 3  4  5  6  

    тогда в памяти у нас хранится она следующим образом
    0 m[0][0] => 4
    1 m[0][1] => 5
    2 m[0][2] => 6
    3 m[0][3] => 2
    4 m[1][0] => 2
    5 m[1][1] => 3
    ...
    k m[i, j] => M[i * cols + j]
    k = i * cols + j
    i = k / cols
    j = k % cols

    к примеру для M[k] = m[k/cols][k%cols] 
    берем k = 13
    M[13] = m[13/4][13%4] = m[3][1]

    теперь поймем, что значит нижний треугольник и получим его формулу
    В данной матрице нижний треугольник - это:
    m[1][0] = M[4]
    m[2][0] = M[8]
    m[2][1] = M[9]
    m[3][1] = M[13]
    m[3][2] = M[14]
    m[3][3] = M[15]

    из этого можно получить условие, что нижний треугольник - это элементы массива соответвующие критериям:
    k % colums < k / colums
    */

    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }
    bool min_init = false;
    float min = 0.0f;

    size_t total = colums * rows;

    for (size_t k = 0; k < total; k++) {
        size_t i =  k % colums;
        size_t j = k / colums;

        if (i >= j) {
            continue;
        }

        float value = matrix[k];

        if (!min_init || value < min) {
            min = value;
            min_init = true;
        }
    } 
    return min;
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_bottom_triangle_min(float (&matrix)[ROWS][COLUMS]) {
    return matrix_bottom_triangle_min(&matrix[0][0], ROWS, COLUMS);
}


/**
 * Функция нахождения максимального элемента в нижнетреугольной части матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return максимальный элемент
 */
inline float matrix_bottom_triangle_max(float* matrix, size_t rows, size_t colums) {

    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }
    bool max_init = false;
    float max = 0.0f;

    size_t total = colums * rows;

    for (size_t k = 0; k < total; k++) {
        size_t i =  k % colums;
        size_t j = k / colums;

        if (i >= j) {
            continue;
        }

        float value = matrix[k];

        if (!max_init || value > max) {
            max = value;
            max_init = true;
        }
    } 
    return max;
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_bottom_triangle_max(float (&matrix)[ROWS][COLUMS]) {
    return matrix_bottom_triangle_max(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения максимального элемента в верхнетреугольной части матрицы
 * @param matrix - указатель на матрицу 
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return максимальный элемент
 */
 inline float matrix_top_triangle_max(float* matrix, size_t rows, size_t colums) {

    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }
    bool max_init = false;
    float max = 0.0f;

    size_t total = colums * rows;

    for (size_t k = 0; k < total; k++) {
        size_t i =  k % colums;
        size_t j = k / colums;

        if (i <= j) {
            continue;
        }

        float value = matrix[k];

        if (!max_init || value > max) {
            max = value;
            max_init = true;
        }
    } 
    return max;
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_top_triangle_max(float (&matrix)[ROWS][COLUMS]) {
    return matrix_top_triangle_max(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения минимального элемента в верхнетреугольной части матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return минимальный элемент
 */
 inline float matrix_top_triangle_min(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }
    bool min_init = false;
    float min = 0.0f;

    size_t total = colums * rows;

    for (size_t k = 0; k < total; k++) {
        size_t i =  k % colums;
        size_t j = k / colums;

        if (i <= j) {
            continue;
        }

        float value = matrix[k];

        if (!min_init || value < min) {
            min = value;
            min_init = true;
        }
    } 
    return min;
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_top_triangle_min(float (&matrix)[ROWS][COLUMS]) {
    return matrix_top_triangle_min(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения минимального элемента в главной диагонали матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return минимальный элемент
 */
 inline float matrix_main_diag_min(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }
    bool min_init = false;
    float min = 0.0f;

    size_t total = colums * rows;

    for (size_t k = 0; k < total; k++) {
        size_t i =  k % colums;
        size_t j = k / colums;

        if (i != j) {
            continue;
        }

        float value = matrix[k];

        if (!min_init || value < min) {
            min = value;
            min_init = true;
        }
    } 
    return min;
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_main_diag_min(float (&matrix)[ROWS][COLUMS]) {
    return matrix_main_diag_min(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения максимального элемента в главной диагонали части матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return минимальный элемент
 */
 inline float matrix_main_diag_max(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }
    bool max_init = false;
    float max = 0.0f;

    size_t total = colums * rows;

    for (size_t k = 0; k < total; k++) {
        size_t i =  k % colums;
        size_t j = k / colums;

        if (i != j) {
            continue;
        }

        float value = matrix[k];

        if (!max_init || value > max) {
            max = value;
            max_init = true;
        }
    } 
    return max;
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_main_diag_max(float (&matrix)[ROWS][COLUMS]) {
    return matrix_main_diag_max(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения минимального элемента в второстепенной диагонали матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return минимальный элемент
 */
inline float matrix_secondary_diag_min(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }
    bool min_init = false;
    float min = 0.0f;

    size_t total = colums * rows;

    for (size_t k = 0; k < total; k++) {
        size_t i =  k % colums;  // индекс столбца
        size_t j = k / colums;   // индекс строки

        if (i + j != colums - 1) {
            continue;
        }

        float value = matrix[k];

        if (!min_init || value < min) {
            min = value;
            min_init = true;
        }
    }
    return min;
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_secondary_diag_min(float (&matrix)[ROWS][COLUMS]) {
    return matrix_secondary_diag_min(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения максимального элемента в второстепенной диагонали матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return минимальный элемент
 */
inline float matrix_secondary_diag_max(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || colums == 0 || rows == 0) {
        return 0.0f;
    }
    bool max_init = false;
    float max = 0.0f;

    size_t total = colums * rows;

    for (size_t k = 0; k < total; k++) {
        size_t i =  k % colums;  // индекс столбца
        size_t j = k / colums;   // индекс строки

        if (i + j != colums - 1) {
            continue;
        }

        float value = matrix[k];

        if (!max_init || value > max) {
            max = value;
            max_init = true;
        }
    }
    return max;
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_secondary_diag_max(float (&matrix)[ROWS][COLUMS]) {
    return matrix_secondary_diag_max(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения среднего арифметического всех элементов матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return среднее арифметическое
 */
inline float matrix_avg(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || rows == 0 || colums == 0) {
        return 0.0f;
    }

    float sum = 0.0f;
    size_t total = rows * colums;

    for (size_t k = 0; k < total; ++k) {
        sum += matrix[k];
    }

    return sum / static_cast<float>(total);
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_avg(float (&matrix)[ROWS][COLUMS]) {
    return matrix_avg(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения среднего арифметического элементов нижнетреугольной части матрицы
 * Диагональ не включается
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return среднее арифметическое
 */
inline float matrix_bottom_triangle_avg(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || rows == 0 || colums == 0) {
        return 0.0f;
    }

    float sum = 0.0f;
    size_t count = 0;
    size_t total = rows * colums;

    for (size_t k = 0; k < total; ++k) {
        size_t i = k % colums; // индекс столбца
        size_t j = k / colums; // индекс строки

        if (i >= j) {
            continue;
        }

        sum += matrix[k];
        ++count;
    }

    if (count == 0) {
        return 0.0f;
    }

    return sum / static_cast<float>(count);
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_bottom_triangle_avg(float (&matrix)[ROWS][COLUMS]) {
    return matrix_bottom_triangle_avg(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения среднего арифметического элементов верхнетреугольной части матрицы
 * Диагональ не включается
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @return среднее арифметическое
 */
inline float matrix_top_triangle_avg(float* matrix, size_t rows, size_t colums) {
    if (matrix == nullptr || rows == 0 || colums == 0) {
        return 0.0f;
    }

    float sum = 0.0f;
    size_t count = 0;
    size_t total = rows * colums;

    for (size_t k = 0; k < total; ++k) {
        size_t i = k % colums; // индекс столбца
        size_t j = k / colums; // индекс строки

        if (i <= j) {
            continue;
        }

        sum += matrix[k];
        ++count;
    }

    if (count == 0) {
        return 0.0f;
    }

    return sum / static_cast<float>(count);
}

template<std::size_t ROWS, std::size_t COLUMS>
inline float matrix_top_triangle_avg(float (&matrix)[ROWS][COLUMS]) {
    return matrix_top_triangle_avg(&matrix[0][0], ROWS, COLUMS);
}

/**
 * Функция нахождения суммы элементов каждой строки матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @param result - выходной массив размером rows
 */
inline void matrix_row_sums(float* matrix, size_t rows, size_t colums, float* result) {
    if (matrix == nullptr || result == nullptr || rows == 0 || colums == 0) {
        return;
    }

    for (size_t r = 0; r < rows; ++r) {
        float sum = 0.0f;
        for (size_t c = 0; c < colums; ++c) {
            sum += matrix[r * colums + c];
        }
        result[r] = sum;
    }
}

template<std::size_t ROWS, std::size_t COLUMS>
inline void matrix_row_sums(float (&matrix)[ROWS][COLUMS], float (&result)[ROWS]) {
    matrix_row_sums(&matrix[0][0], ROWS, COLUMS, result);
}

/**
 * Функция нахождения суммы элементов каждого столбца матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @param result - выходной массив размером colums
 */
inline void matrix_col_sums(float* matrix, size_t rows, size_t colums, float* result) {
    if (matrix == nullptr || result == nullptr || rows == 0 || colums == 0) {
        return;
    }

    for (size_t c = 0; c < colums; ++c) {
        float sum = 0.0f;
        for (size_t r = 0; r < rows; ++r) {
            sum += matrix[r * colums + c];
        }
        result[c] = sum;
    }
}

template<std::size_t ROWS, std::size_t COLUMS>
inline void matrix_col_sums(float (&matrix)[ROWS][COLUMS], float (&result)[COLUMS]) {
    matrix_col_sums(&matrix[0][0], ROWS, COLUMS, result);
}

/**
 * Функция нахождения минимального элемента в каждой строке матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @param result - выходной массив размером rows
 */
inline void matrix_row_mins(float* matrix, size_t rows, size_t colums, float* result) {
    if (matrix == nullptr || result == nullptr || rows == 0 || colums == 0) {
        return;
    }

    for (size_t r = 0; r < rows; ++r) {
        float min_value = matrix[r * colums];
        for (size_t c = 1; c < colums; ++c) {
            float value = matrix[r * colums + c];
            if (value < min_value) {
                min_value = value;
            }
        }
        result[r] = min_value;
    }
}

template<std::size_t ROWS, std::size_t COLUMS>
inline void matrix_row_mins(float (&matrix)[ROWS][COLUMS], float (&result)[ROWS]) {
    matrix_row_mins(&matrix[0][0], ROWS, COLUMS, result);
}

/**
 * Функция нахождения минимального элемента в каждом столбце матрицы
 * @param matrix - указатель на матрицу
 * @param rows - количество строк
 * @param colums - количество столбцов
 * @param result - выходной массив размером colums
 */
inline void matrix_col_mins(float* matrix, size_t rows, size_t colums, float* result) {
    if (matrix == nullptr || result == nullptr || rows == 0 || colums == 0) {
        return;
    }

    for (size_t c = 0; c < colums; ++c) {
        float min_value = matrix[c];
        for (size_t r = 1; r < rows; ++r) {
            float value = matrix[r * colums + c];
            if (value < min_value) {
                min_value = value;
            }
        }
        result[c] = min_value;
    }
}

template<std::size_t ROWS, std::size_t COLUMS>
inline void matrix_col_mins(float (&matrix)[ROWS][COLUMS], float (&result)[COLUMS]) {
    matrix_col_mins(&matrix[0][0], ROWS, COLUMS, result);
}