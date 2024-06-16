#include <stdio.h>
#define SUCCESS 0
#define FAIL 1
#define N 2

int find_det(float mat[], float *det);
void init2x2_matrix(float mat[], float a1, float a2, float a3, float a4);
void print_mat(float A[]);
int main(void)
{
    float Vg, Vb, Rg, Rb, Rl, i1, i2;
    float b1, b2;
    float valdet_A, valdet_A1, valdet_A2;

    float A[N * N], A1[N * N], A2[N * N];

    printf("Please insert Vg and Vb in order (V): ");
    scanf("%f %f", &Vg, &Vb);

    printf("Please insert Rg, Rb and Rl in order (ohm): ");
    scanf("%f %f %f", &Rg, &Rb, &Rl);

    init2x2_matrix(A, Rg + Rb, -Rb, -Rb, Rb + Rl);
    b1 = Vg - Vb;
    b2 = Vb;

    for (int i = 0; i < N*N; i++){
        A1[i] = A[i];
    }
    for (int i = 0; i < N*N; i++){
        A2[i] = A[i];
    }

    A1[0] = b1;
    A1[2] = b2;

    A2[1] = b1;
    A2[3] = b2;

    if (!find_det(A, &valdet_A))
    {
        find_det(A1, &valdet_A1);
        find_det(A2, &valdet_A2);
        i1 = valdet_A1 / valdet_A;
        i2 = valdet_A2 / valdet_A;
        printf("\ni1 is %.2f", i1);
        printf("\ni2 is %.2f\n", i2);
        if (i1 >= i2)
        {
            printf("Battery is charging\n");
        }
        else
        {
            printf("Battery is discharging\n");
        }
    }
    else
    {
        printf("Can't evaluate a determinant value near 0. \n");
    }
    return 0;
}

int find_det(float mat[], float *det)
{
    *det = mat[0] * mat[3] - mat[1] * mat[2];
    return (*det <= 1e-9 && *det >= -1e-9) ? FAIL : SUCCESS;
}

void init2x2_matrix(float mat[], float a1, float a2, float a3, float a4)
{
    mat[0] = a1;
    mat[1] = a2;
    mat[2] = a3;
    mat[3] = a4;
}

void print_mat(float A[])
{
    printf("\n");
    for (int i = 0; i < N * N; i++)
    {
        printf("%.2f", A[i]);
        if (i % 2)
            printf("\n");
    }
}
