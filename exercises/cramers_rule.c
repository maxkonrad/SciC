#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

typedef struct
{
    double *M;
    int r;
    int c;
} matrix;

int prompt_matrix(matrix *M, matrix *b);
double determinant_matrix(matrix M);
void copy_matrix(matrix *dest, const matrix *src);
void replace_column(matrix *M, matrix b, int n);
void cramers_rule(matrix M, matrix b);
void print_matrix(matrix M);
void memFree(matrix *M);
void memAlloc(matrix *M);

int main(void)
{
    matrix mat1 = {NULL, 0, 0};
    matrix b = {NULL, 0, 0};
    if (!prompt_matrix(&mat1, &b))
    {
        cramers_rule(mat1, b);
        memFree(&mat1);
        memFree(&b);
    }
    else
    {
        printf("Size of matrix can't be larger than 3 or less than 0!\n");
    }

    return 0;
}

void cramers_rule(matrix M, matrix b)
{
    double det = determinant_matrix(M);
    if (det < 1e-9 && det > -1e-9)
    {
        printf("Matrix is singular or nearly singular, cannot apply Cramer's rule :/.\n");
        return;
    }
    double new_det;
    matrix new_mat;
    new_mat.c = new_mat.r = M.c;
    memAlloc(&new_mat);
    for (int i = 0; i < b.r; i++)
    {
        copy_matrix(&new_mat, &M);
        replace_column(&new_mat, b, i);
        new_det = determinant_matrix(new_mat);
        printf("x%d = %.2lf\n", i + 1, new_det / det);
    }
    memFree(&new_mat);
}

double determinant_matrix(matrix M)
{
    double sum = 0;
    if (M.r == 3)
    {
        sum = M.M[0] * ((M.M[4] * M.M[8]) - (M.M[7] * M.M[5])) -
              M.M[1] * ((M.M[3] * M.M[8]) - (M.M[6] * M.M[5])) +
              M.M[2] * ((M.M[3] * M.M[7]) - (M.M[6] * M.M[4]));
    }
    else if (M.r == 1)
        sum = M.M[0];
    else
    {
        sum = (M.M[0] * M.M[3]) - (M.M[1] * M.M[2]);
    }
    return sum;
}

int prompt_matrix(matrix *M, matrix *b)
{
    int n;

    printf("Please insert the n of the square matrix: ");
    scanf("%d", &n);

    if (n > 3 || n <= 0)
    {
        return FAIL;
    }

    (*M).c = n;
    (*M).r = n;
    (*b).c = 1;
    (*b).r = n;

    memAlloc(M);
    memAlloc(b);

    printf("\nPlease insert the rhs of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &(*b).M[i]);
    }

    printf("\nPlease insert the elements of the matrix: ");
    for (int i = 0; i < n * n; i++)
    {
        scanf("%lf", &(*M).M[i]);
    }

    return SUCCESS;
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

void replace_column(matrix *M, matrix b, int n)
{
    for (int i = 0; i < (*M).r; i++)
    {
        (*M).M[i * (*M).c + n] = b.M[i];
    }
}

void print_matrix(matrix M)
{
    printf("The resultant Matrix: \n");
    for (int i = 0; i < M.r * M.c; i++)
    {
        printf("%lf\t", M.M[i]);
        if ((i + 1) % M.c == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

void copy_matrix(matrix *dest, const matrix *src)
{
    for (int i = 0; i < (*src).c * (*src).r; i++)
    {
        (*dest).M[i] = (*src).M[i];
    }
}