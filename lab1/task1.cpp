#include <iostream>
#include <stdexcept>
using namespace std;

// Изначальная функция power
// int power(int x,int n)
// {
//     int i, p=1;
//     for(i=1;i<n;i++) p*=x;
//     return p;
// }


double power(double x, int n)
{

    // Выбрасываем исключение если число равно 0 и степень отрицательная
    if (x == 0 && n < 0) {
        throw invalid_argument("0 нельзя возводить в отрицательную степень.");
    }

    // если степень равна 0, то возвращаем 1 – это микрооптимизация для чистаемости, но можно и без нее обойтись
    if (n == 0) return 1.0;

    int abs_n = (n < 0) ? -n : n; // получаем степень по модулю

    double p = 1.0;
    // цикл для возведения числа в степень начинаем с 0 и до модуля степени
    for (int i = 0; i < abs_n; i++) p *= x;

    // если степень отрицательная, то переворачиваем результат
    if (n < 0) return 1.0 / p;
    
    return p;
}


// Изначальная функция main
// int main(void)
// {
//     int i, k;
//     for (i = 0; i < 10; i++)
//     {
//         k = power(2, i);
//         cout<<"i = "<<i<<", k = "<<k<<endl;
//     }
//     return 0;
// }

int main (void) {

    double base;
    int exp;
    cout<<"Введите число и степень:"<<endl;
    cin>>base>>exp;
    try {
        double result = power(base, exp);
        cout<<"Ответ: "<<base<<"^"<<exp<<"="<<result<<endl;
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
        return 1;
    }
    return 0;
}