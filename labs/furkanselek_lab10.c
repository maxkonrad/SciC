#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int r;
    int c;
    double *M;
} matrix;

void create_matrix(matrix *M);
void memAlloc(matrix *M);
void memFree(matrix *M);
void add_matrix(matrix M1, matrix M2);
void print_matrix(matrix M);
void multiply_matrix(matrix M1, matrix M2);
double determinant_matrix(matrix M);
void calc_root(matrix M, matrix * eigen);

int main(void)
{
    matrix M;
    matrix eigen;
    M.c = 2;
    M.r = 2;
    eigen.c = 2;
    eigen.r = 2;
    
    memAlloc(&M);
    memAlloc(&eigen);
    create_matrix(&M);
    double disc = determinant_matrix(M);
    calc_root(M, &eigen);
    multiply_matrix(M, eigen);
    memFree(&M);
    return 0;
}

void create_matrix(matrix *M)
{
    printf("Please insert elements of the matrix: \n");
    for (int i = 0; i < (*M).r; i++)
    {
        for (int j = 0; j < (*M).c; j++)
        {
            scanf("%lf", &(*M).M[((*M).r * i) + j]);
            printf(" ");
        }
        printf("\n");
    }
}

void memAlloc(matrix *M)
{
    (*M).M = (double *)malloc(sizeof(double) * (*M).r * (*M).c);
}

void memFree(matrix *M)
{
    free((*M).M);
    (*M).M = NULL;
}



void print_matrix(matrix M)
{
    printf("The resultant Matrix: \n");
    printf("\nEigenvalue: %lf + %lf i", M.M[0], M.M[1]);
    printf("\nEigenvalue: %lf + %lf i", M.M[2], M.M[3]);
    printf("\n");
}

void multiply_matrix(matrix M1, matrix M2)
{
    matrix mul = {M2.r, M1.c, NULL};
    memAlloc(&mul);

    for (int i = 0; i < M1.r; i++)
    {
        for (int j = 0; j < M2.c; j++)
        {
            mul.M[(mul.c * i) + j] = 0;
            for (int k = 0; k < M1.c; k++)
            {
                mul.M[(M1.c * i) + j] += (M1.M[(M1.c * i) + k] * M2.M[(M2.c * j) + k]);
            }
        }
    }

    print_matrix(mul);
    memFree(&mul);
}


double determinant_matrix(matrix M)
{
    double sum = 0;
    if (M.r == 3)
    {
        sum = M.M[0] * ((M.M[3] * M.M[8]) - (M.M[6] * M.M[5])) -
              M.M[1] * (M.M[0] * M.M[8] - M.M[6] * M.M[2]) +
              M.M[2] * (M.M[0] * M.M[5] - M.M[3] * M.M[2]);
    }
    else if (M.r == 1)
        sum = M.M[0];
    else
    {
        sum = (M.M[0] * M.M[3]) - (M.M[1] * M.M[2]);
    }
    return sum;
}

void calc_root(matrix M, matrix *eigen){
    double lambda[2];
    lambda[0] = M.M[0] + M.M[3] + sqrtf(pow(M.M[1],2) - 4*M.M[0]*M.M[2]);
    lambda[1] = M.M[0] + M.M[3] - sqrtf(pow(M.M[1],2) - 4*M.M[0]*M.M[2]);

    eigen->M[0] = lambda[0];
    eigen->M[3] = lambda[1];
}