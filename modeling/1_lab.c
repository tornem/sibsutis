#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 10000000
#define EXP 2.71828
#define PI 3.14

int main()
{
    double *rand_arr = malloc(sizeof(double) * N);
    int freq[20];
    double xi = 0;
    double cache_var_0 = EXP;
    double cache_var_1 = PI;
    double cache_var_2 = 0;

    memset(freq, 0, sizeof(freq));

    rand_arr[0] = cache_var_0/4.0;
    rand_arr[1] = cache_var_1/4.0;

    for (int i = 2; i < N; ++i) {
        cache_var_2 = fmod((5.0 * cache_var_0 + 7.0 * cache_var_1), 4.0);
        rand_arr[i] = cache_var_2 / 4.0;
        cache_var_0 = cache_var_1;
        cache_var_1 = cache_var_2;
    }

    // делим наш интервал на 20 равных частей
    // и считаем кол-во значений, попавших туда
    for (int i = 0; i < N; ++i) {
        double m = 0.05;
        for (int j = 0; j < 20; ++j) {
            //printf("[%f] ? [%f]\n", rand_arr[i], m);
            if (rand_arr[i] <= m){
                //printf("!!! YES !!!\n");
                ++freq[j];
                break;
            }
            m += 0.05;
        }
    }

    // for (int i = 0; i < 20; ++i) {
    //     printf("%d\n", freq[i]);
    // }

    for (int i = 0; i < 20; ++i) {
        xi += ((freq[i] - N/20.0) * (freq[i] - N/20.0)) / (N/20.0);
    }

    printf("%f\n", xi);

    return 0;
}