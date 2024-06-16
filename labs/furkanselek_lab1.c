#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int r;
    int c;
    double *M;
} matrix;

void create_matrix(matrix *M);
void create_matrix_n(matrix *M);
void memAlloc(matrix *M);
void memFree(matrix *M);
void add_matrix(matrix M1, matrix M2);
void print_matrix(matrix M);
void multiply_matrix(matrix M1, matrix M2);
void transpose_matrix(matrix M);    
void determinant_matrix(matrix M);

int main(void)
{
    int done = 0;
    int choice;

    matrix M1 = {0, 0, NULL};
    matrix M2 = {0, 0, NULL};

    while (!done)
    {
        printf("Which matrix operation would you like to do today? \n");
        printf("1-Addition\n");
        printf("2-Multiplication\n");
        printf("3-Transpose\n");
        printf("4-Determinant\n");
        printf("0-Exit\n\n");

        printf("You should insert matricies as the following: (e.g 2x2 matrix):\n el1 el2 \n el3 el4\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Note that you will need two matricies for this operation. \n");
            create_matrix_n(&M1);
            create_matrix_n(&M2);
            if (M1.r != M2.r || M1.c != M2.c)
            {
                printf("They need to be at the same size.\n");
                break;
            }
            printf("Insert the first matrix\n");
            memAlloc(&M1);
            create_matrix(&M1);
            printf("Insert the second matrix\n");
            memAlloc(&M2);
            create_matrix(&M2);
            add_matrix(M1, M2);
            memFree(&M1);
            memFree(&M2);
            break;
        case 2:
            printf("Note that you will need two matricies for this operation. \n");
            printf("Enter the dimensions of the first matrix. \n");
            create_matrix_n(&M1);
            printf("Enter the dimensions of the second matrix. \n");
            create_matrix_n(&M2);
            if (M1.c != M2.r)
            {
                printf("Columns of first matrix must be equal to rows of second matrix.\n");
                memFree(&M1);
                memFree(&M2);
                break;
            }
            memAlloc(&M1);
            printf("Insert the first matrix\n");
            create_matrix(&M1);
            printf("Insert the second matrix\n");
            memAlloc(&M2);
            create_matrix(&M2);
            multiply_matrix(M1, M2);
            memFree(&M1);
            memFree(&M2);
            break;
        case 3:
            create_matrix_n(&M1);
            memAlloc(&M1);
            create_matrix(&M1);
            transpose_matrix(M1);
            memFree(&M1);
            break;
        case 4:
            create_matrix_n(&M1);
            memAlloc(&M1);
            create_matrix(&M1);
            if (M1.r != M1.c || M1.c > 3)
            {
                printf("It must be a square matrix and can't be bigger than size of 3 rows.\n");
                memFree(&M1);
                break;
            }
            determinant_matrix(M1);
            memFree(&M1);
            break;
        case 0:
            printf("Bye.\n");
            done = 1;
            break;

        default:
            printf("Invalid input, please insert a number.\n");
            break;
        }
    }
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

void create_matrix_n(matrix *M)
{
    printf("Please insert number of rows in the matrix: ");
    scanf("%d", &(*M).r);
    printf("\n");
    printf("Please insert number of columns in the matrix: ");
    scanf("%d", &(*M).c);
    printf("\n");
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

void add_matrix(matrix M1, matrix M2) {
    matrix sum = {M1.r, M1.c, NULL};
    memAlloc(&sum);
    for (int i = 0; i < M1.r * M1.c; i++) {
        sum.M[i] = M1.M[i] + M2.M[i];
    }
    print_matrix(sum);
    memFree(&sum);
}


void print_matrix(matrix M)
{
    printf("The resultant Matrix: \n");
    for (int i = 0; i < M.r; i++)
    {
        for (int j = 0; j < M.c; j++)
        {
            printf("%lf", M.M[(M.r * i) + j]);
            printf("\t");
        }
        printf("\n");
    }
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

void transpose_matrix(matrix M)
{
    matrix Tr = {M.c, M.r, NULL};
    memAlloc(&Tr);
    for (int i = 0; i < M.r; i++)
    {
        for (int j = 0; j < M.c; j++)
        {
            Tr.M[(Tr.c * j) + i] = M.M[(M.c * i) + j];
        }
    }
    print_matrix(Tr);
    memFree(&Tr);
}

void determinant_matrix(matrix M)
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
    printf("\nDeterminant: %.2lf\n", sum);
}