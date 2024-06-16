/*
AUTHOR: FURKAN SELEK
EE204 HW1T1
COPYRIGHT 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prompt_size(int *);
void prompt_mat(double **, int);
int check_symmetric(double *, int);
void check_definete(double *mat, int mat_size);
void check_def_status(int mat_size, double Dk[mat_size]);

int main(void)
{
    double *mat;
    int mat_size = 1;

    prompt_size(&mat_size);
    mat = (double *)malloc(mat_size * mat_size * sizeof(double));
    prompt_mat(&mat, mat_size);

    if (check_symmetric(mat, mat_size))
    {
        check_definete(mat, mat_size);
    }
    else
    {
        printf("Matrix is not symmetric, so it is not definite.\n");
    }
    free(mat);
    return 0;
}

void prompt_size(int *mat_size_p)
{
    int stop = 0;
    while (!stop)
    {
        printf("Please enter matrix size (e.g 3 for 3x3 matrix): ");
        scanf("%d", mat_size_p);

        if (*mat_size_p >= 1 && *mat_size_p <= 3)
        {
            stop = 1;
            printf("\nMatrix is %dx%d size.\n", *mat_size_p, *mat_size_p);
        }
        else
        {
            printf("Size can be from 1 to 3.\n");
        }
    }
}

void prompt_mat(double **mat_p, int mat_size)
{
    for (int i = 0; i < mat_size * mat_size; i++)
    {
        printf("Please enter element [%d][%d]: ", i / mat_size, i % mat_size);
        scanf("%lf", &(*mat_p)[i]);
    }
}

double determinant_matrix(double *mat, int mat_size)
{
    double sum = 0;
    if (mat_size == 3)
    {
        sum = mat[0] * ((mat[4] * mat[8]) - (mat[7] * mat[5])) -
              mat[1] * ((mat[3] * mat[8]) - (mat[6] * mat[5])) +
              mat[2] * ((mat[3] * mat[7]) - (mat[6] * mat[4]));
    }
    else if (mat_size == 1)
        sum = mat[0];
    else
    {
        sum = (mat[0] * mat[3]) - (mat[1] * mat[2]);
    }
    return sum;
}

int check_symmetric(double *mat, int mat_size)
{
    int symmetric = 1;
    for (int i = 0; i < mat_size; i++)
    {
        for (int j = 0; j < mat_size; j++)
        {
            if (mat[i * mat_size + j] != mat[j * mat_size + i])
            {
                symmetric = 0;
                break;
            }
        }
    }
    if (symmetric)
        printf("Matrix is symmetric.\n");
    else
        printf("Matrix is not symmetric.\n");
    return symmetric;
}

void check_definete(double *mat, int mat_size)
{
    if (mat_size == 3)
    {
        double sub_mat[4];
        sub_mat[0] = mat[0];
        sub_mat[1] = mat[1];
        sub_mat[2] = mat[3];
        sub_mat[3] = mat[4];

        double det1 = determinant_matrix(mat, 3);
        double det2 = determinant_matrix(sub_mat, 2);
        double det3 = mat[0];

        double Dk[3] = {det1, det2, det3};
        check_def_status(3, Dk);
    }
    else if (mat_size == 2)
    {
        double det = determinant_matrix(mat, 2);
        double Dk[2] = {det, mat[0]};
        check_def_status(2, Dk);
    }
    else
    {
        double Dk[1] = {mat[0]};
        check_def_status(1, Dk);
    }
}

void check_def_status(int mat_size, double Dk[mat_size])
{
    int pos_def = 0;
    int neg_def = 0;
    int pos_semi = 0;
    int neg_semi = 0;
    for (int i = 0; i < mat_size; i++)
    {
        if (Dk[i] > 0)
        {
            pos_def += 1;
        }
        else if (Dk[i] < 0)
        {
            neg_def += 1;
        }
        else if (Dk[i] == 0)
        {
            if (i == 2)
            {
                pos_semi += 1;
            }
            else
            {
                neg_semi += 1;
            }
        }
    }
    if (pos_def == mat_size)
    {
        printf("Matrix is positive definite.\n");
    }
    else if (neg_def == mat_size)
    {
        printf("Matrix is negative definite.\n");
    }
    else if (pos_semi == mat_size)
    {
        printf("Matrix is positive semi-definite.\n");
    }
    else if (neg_semi == mat_size)
    {
        printf("Matrix is negative semi-definite.\n");
    }
    else
    {
        printf("Matrix is indefinite.\n");
    }
}