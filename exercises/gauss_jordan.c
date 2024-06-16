#include <stdio.h>
#define N 3

void simple_gauss(double mat[N][N], double b[N]);
void print_matrix(int r, int c, double mat[r][c]);
void print_res(int n, double x[n]);

int main(void)
{
    double mat[N][N] = {{2, 3, 5}, {1, 2, 4}, {4, 7, 3}};

    double b[N] = {10, 5, 15};
    simple_gauss(mat, b);
}

void simple_gauss(double mat[N][N], double b[N])
{
    double work_mat[N][N + 1];
    double m;
    double x[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            work_mat[i][j] = mat[i][j];
        }
        work_mat[i][N] = b[i];
    }

    print_matrix(N, N + 1, work_mat);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j != i)
            {
                m = work_mat[j][i] / work_mat[i][i];
                printf("\n%lf / %lf = m = %lf", work_mat[j][i], work_mat[i][i], m);
                for (int k = i; k <= N; k++)
                {
                    printf("\n%lf is -= %lf * %lf", work_mat[j][k], work_mat[i][k], m);
                    work_mat[j][k] -= work_mat[i][k] * m;
                    printf("\nwhich equals %lf", work_mat[j][k]);
                }
            }
        }
    }
    print_matrix(N, N + 1, work_mat);

    for (int i = 0; i < N; i++)
    {
        x[i] = work_mat[i][N] / work_mat[i][i];
    }

    print_matrix(N, N + 1, work_mat);
    print_res(N, x);
}

void print_matrix(int r, int c, double mat[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%lf\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_res(int n, double x[n])
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%lf\n", x[i]);
    }
    printf("\n");
}
