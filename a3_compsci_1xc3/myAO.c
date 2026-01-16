#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **allocateMatrix(int cols, int rows)
{
    double **matrix = malloc(rows * sizeof(double *));
    if (!matrix)
        return NULL;
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(cols * sizeof(double));
        if (!matrix[i])
            return NULL;
    }
    return matrix;
}

void freeMatrix(double **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

double **addMatrices(double **A, double **B, int nA, int mA, int nB, int mB)
{
    if (nA != nB || mA != mB)
        return NULL;
    double **C = allocateMatrix(nA, mA);
    if (!C)
        return NULL;
    for (int i = 0; i < mA; i++)
        for (int j = 0; j < nA; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

double **subtractMatrices(double **A, double **B, int nA, int mA, int nB, int mB)
{
    if (nA != nB || mA != mB)
        return NULL;
    double **C = allocateMatrix(nA, mA);
    if (!C)
        return NULL;
    for (int i = 0; i < mA; i++)
        for (int j = 0; j < nA; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

double **multiplicationMatrices(double **A, double **B, int nA, int mA, int nB, int mB)
{
    if (nA != mB)
        return NULL;
    double **C = allocateMatrix(nB, mA);
    if (!C)
        return NULL;
    for (int i = 0; i < mA; i++)
        for (int j = 0; j < nB; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < nA; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

double **transposeMatrices(double **A, int nA, int mA)
{
    double **C = allocateMatrix(mA, nA);
    if (!C)
        return NULL;
    for (int i = 0; i < nA; i++)
        for (int j = 0; j < mA; j++)
            C[j][i] = A[i][j];
    return C;
}

void swapRows(double **matrix, int row1, int row2, int cols)
{
    for (int j = 0; j < cols; j++)
    {
        double tmp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = tmp;
    }
}

double **solveAxB(double **A, double **B, int nA, int mA, int nB, int mB)
{
    if (mA != mB || nB != 1 || nA != mA)
        return NULL;
    double **aug = allocateMatrix(nA + 1, mA);
    if (!aug)
        return NULL;
    for (int i = 0; i < mA; i++)
    {
        for (int j = 0; j < nA; j++)
            aug[i][j] = A[i][j];
        aug[i][nA] = B[i][0];
    }
    for (int k = 0; k < nA; k++)
    {
        int maxRow = k;
        for (int i = k + 1; i < nA; i++)
            if (fabs(aug[i][k]) > fabs(aug[maxRow][k]))
                maxRow = i;
        if (fabs(aug[maxRow][k]) < 1e-9)
        {
            freeMatrix(aug, mA);
            return NULL;
        }
        if (maxRow != k)
            swapRows(aug, k, maxRow, nA + 1);
        for (int i = k + 1; i < nA; i++)
        {
            double f = aug[i][k] / aug[k][k];
            for (int j = k; j <= nA; j++)
                aug[i][j] -= f * aug[k][j];
            aug[i][k] = 0;
        }
    }
    double **x = allocateMatrix(1, mA);
    if (!x)
    {
        freeMatrix(aug, mA);
        return NULL;
    }
    for (int i = mA - 1; i >= 0; i--)
    {
        x[i][0] = aug[i][nA];
        for (int j = i + 1; j < nA; j++)
            x[i][0] -= aug[i][j] * x[j][0];
        x[i][0] /= aug[i][i];
    }
    freeMatrix(aug, mA);
    return x;
}
