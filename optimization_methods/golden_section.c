#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ACC 0.1e-4

double Foo(double x)
{
    double y;
    y = x*x - 5*x;
    // y = x*x;
    return y;
}
    // метод золотого сечения ищет минимум/максимум функции
    // при условии того, что она унимодальна на отрезке [a, b]

double SearchMaxByGS(double a, double b, int* i , double accuracy) 
{
    const double golden_ratio = (1 + sqrt(5)) * 0.5; 
    
    double x_1, x_2;
    double temp_func_val_1, temp_func_val_2 = 0;

    puts("start worked:\n");

    // вычисляем значения точек на исходном интервале
    // и значения функции в этих точках

    x_1 = b - (b - a) / golden_ratio;  // divided line segment as 0.382 * lenght
    x_2 = a + (b - a) / golden_ratio;  // divided line segment as 0.618 * lenght

    temp_func_val_1 = Foo(x_1);
    temp_func_val_2 = Foo(x_2);
    
    // т.к. функция унимодальна, можем утверждать, что 
    // интервал можно уменьшить со стороны той точки,
    // в которой функция имеет большее значение 
    // (в случае поиска минимума). Запускаем цикл, 
    // который будет уменьшать размеры интервала до тех пор,
    // пока его длинна не станет меньше точности наших вычислений.
    // Вычислять значение функции в обоих точках необходимо только 
    // в первой итерации, в последующем на каждом интервале необходимо
    // получить координату лишь одной точки.

    while (fabs(b - a) > accuracy) {
        if (temp_func_val_1 >= temp_func_val_2) {
            temp_func_val_1 = temp_func_val_2;
            a = x_1;
            x_1 = x_2;
            x_2 = a + (b - a) / golden_ratio;
            temp_func_val_2 = Foo(x_2);
        } else {
            temp_func_val_2 = temp_func_val_1;
            b = x_2;
            x_2 = x_1;
            x_1 = b - (b - a) / golden_ratio;
            temp_func_val_1 = Foo(x_1);
        }
        printf("x_1 = %lf\n", x_1);
        printf("x_2 = %lf\n", x_2);
        printf("f(x_1) = %lf\n", temp_func_val_1);
        printf("f(x_2) = %lf\n", temp_func_val_2);
        printf("[%lf;%lf]\n", a, b);
        ++(*i);
    }

    double result = (a + b) / 2;
    return result;
}

int main()
{
    int i = 0;
    double x = SearchMaxByGS(-10.0, 10.0, &i, ACC);
    printf("Min x = %.9lf, min y = %.9lf\n", x, Foo(x));
    printf("Count iteration = %d\n", i);
    return EXIT_SUCCESS;    
}