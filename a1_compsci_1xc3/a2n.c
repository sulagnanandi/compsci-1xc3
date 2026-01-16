#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

void my_a2n(int a, int n);

int main(int argc, char *argv[])
{
    if (argc != 3)
    { // argv[0] = "./a2n", argv[1] = "a", argv[2] = "n". argc = sizeOf(argv)/sizeOf(argv[0])
        printf("Incorrect number of inputs! Expected two numbers separated by a space.\n");
        return 1;
    }

    int a = atoi(argv[1]);
    int n = atoi(argv[2]);
    if (n < 0)
    {
        printf("Please ensure n is non-negative.\n");
        return 1;
    }
    my_a2n(a, n);
}

void my_a2n(int a, int n)
{

    int result = a << n;

    printf("Calculation result using my_a2n: %d\n", result);
}