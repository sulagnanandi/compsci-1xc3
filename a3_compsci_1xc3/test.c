#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "utility.h"
#include "myAO.h"

bool isPositiveInteger(const char *s)
{
    if (!s || !*s)
        return false;
    if (s[0] == '0' && s[1])
        return false;
    for (int i = 0; s[i]; i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}

bool validInput(int argc, char *argv[])
{
    if (argc != 5 && argc != 7)
        return false;
    if (strcmp(argv[1], "0") && strcmp(argv[1], "1"))
        return false;
    if (strlen(argv[2]) != 1)
        return false;
    char op = argv[2][0];
    if (op != '+' && op != '-' && op != 'T' && op != 's' && op != '*')
        return false;
    for (int i = 3; i < argc; i++)
        if (!isPositiveInteger(argv[i]))
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    if (!validInput(argc, argv))
        return 1;
    int nA = atoi(argv[3]), mA = atoi(argv[4]);
    double **A = allocateMatrix(nA, mA), **result = NULL;
    if (!A)
        return 1;
    char op = argv[2][0];
    if (argc == 5)
    {
        result = transposeMatrices(A, nA, mA);
        freeMatrix(A, mA);
    }
    else
    {
        int nB = atoi(argv[5]), mB = atoi(argv[6]);
        double **B = allocateMatrix(nB, mB);
        if (!B)
            return 1;
        if (op == '+')
            result = addMatrices(A, B, nA, mA, nB, mB);
        else if (op == '-')
            result = subtractMatrices(A, B, nA, mA, nB, mB);
        else if (op == '*')
            result = multiplicationMatrices(A, B, nA, mA, nB, mB);
        else if (op == 's')
            result = solveAxB(A, B, nA, mA, nB, mB);
        freeMatrix(A, mA);
        freeMatrix(B, mB);
    }
    if (!result)
        return 1;
    if (!strcmp(argv[1], "1"))
    {
        int rows = (argc == 5 ? mA : mA);
        int cols = (op == '*' ? atoi(argv[6]) : (op == 's' ? 1 : nA));
        printMatrix(result, rows, cols);
    }
    freeMatrix(result, mA);
    return 0;
}