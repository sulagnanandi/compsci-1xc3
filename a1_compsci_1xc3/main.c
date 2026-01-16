#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void my_a2n(int a, int n, int m);
void a2n_with_pow(int a, int n, int m);
void a2n_with_loop(int a, int n, int m);

int main(int argc, char *argv[])
{

    clock_t start, end;
    double my_a2n_time, a2n_with_pow_time, a2n_with_loop_time;

    if (argc != 3)
    { // argv[0] = "./main", argv[1] = "n", argv[2] = "m". argc = sizeOf(argv)/sizeOf(argv[0])
        printf("Incorrect number of inputs! Expected two numbers separated by a space.\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    if (n < 0 || m < 0)
    {
        printf("Please ensure n and m are non-negative.\n");
        return 1;
    }

    start = clock();
    my_a2n(1, n, m);
    end = clock();
    my_a2n_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CPU time for my_a2n: %lf seconds\n", my_a2n_time);

    start = clock();
    a2n_with_pow(1, n, m);
    end = clock();
    a2n_with_pow_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CPU time for a2n_with_pow: %lf seconds\n", a2n_with_pow_time);

    start = clock();
    a2n_with_loop(1, n, m);
    end = clock();
    a2n_with_loop_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CPU time for a2n_with_loop: %lf seconds\n", a2n_with_loop_time);
}

void my_a2n(int a, int n, int m)
{
    int result = 0;

    for (int i = 0; i < m; i++)
    {
        result = a << n;
    }

    printf("Calculation result using my_a2n: %d\n", result);
}

void a2n_with_pow(int a, int n, int m)
{
    int result = 0;

    for (int i = 0; i < m; i++)
    {
        result = a * pow(2, n);
    }

    printf("Calculation result using a2n_with_pow: %d\n", result);
}

void a2n_with_loop(int a, int n, int m)
{
    int result = a;
    for (int i = 0; i < m; i++)
    {
        result = a;
        for (int j = 0; j < n; j++)
        {
            result *= 2;
        }
    }
    printf("Calculation result using a2n_with_loop: %d\n", result);
}