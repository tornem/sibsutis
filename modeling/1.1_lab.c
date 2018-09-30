#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define N 10000000

int main ()
{
    long int* rand_arr = malloc(sizeof(long int) * N);
    int freq[20];
    double xi = 0;
    long int mask = 0b00000011111111111111111111000000;

    memset(freq, 0, sizeof(freq));

    // printf("long max = %ld\n", LONG_MAX);

    rand_arr[0] = time(0);

    rand_arr[0] = rand_arr[0]*rand_arr[0];
    rand_arr[0] = rand_arr[0] & mask;
    rand_arr[0] = rand_arr[0] << 6;

    //printf("%ld\n", rand_arr[0]);
    for (int i = 1; i < N; ++i) {
        rand_arr[i] = rand_arr[i-1]*rand_arr[i-1];
        rand_arr[i] = rand_arr[i] & mask;
        //printf("%ld\n", rand_arr[i]);
    }

    // делим наш интервал на 20 равных частей
    // и считаем кол-во значений, попавших туда
    for (int i = 0; i < N; ++i) {
        double m = LONG_MAX/20000000000;
        for (int j = 0; j < 20; ++j) {
            //printf("[%ld] ? [%f]\n", rand_arr[i], m);
            if (rand_arr[i] <= m){
                //printf("!!! YES !!!\n");
                ++freq[j];
                break;
            }
            m += LONG_MAX/20;
        }
    }

    for (int i = 0; i < 20; ++i) {
        printf("%d\n", freq[i]);
    }

    for (int i = 0; i < 20; ++i) {
        xi += ((freq[i] - N/20.0) * (freq[i] - N/20.0)) / (N/20.0);
    }

    printf("%f\n", xi);


}