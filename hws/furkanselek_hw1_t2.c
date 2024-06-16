/*
AUTHOR: FURKAN SELEK
EE204 HW1T2
COPYRIGHT 2024
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592

double d = 0.5;
double L = 1.4;
double lambda_g = 3.6;
double a = 2.28;

static int iteration = 0;
double (*f)(double);
double *tolerance_value_generator();
double newton_method(double, double, double (*f)(double));

double deg2rad(double x);
double func(double);
double dfunc_dx(double x);
double K();
double e_r(double x);

int main(void)
{
    double init_guess = 90;
    int stop = 0;
    while (!stop)
    {
        printf("Please enter an initial guess (between 90 and 270): ");
        scanf("%lf", &init_guess);

        if (init_guess >= 90 && init_guess <= 270)
        {
            stop = 1;
        }
        else
        {
            printf("Can't be greater than 270 or less than 90\n");
        }
    }

    init_guess = deg2rad(init_guess);

    double *generated_values = tolerance_value_generator();
    double root;
    for (int i = 0; i < 6; i++)
    {
        iteration = 0;
        root = newton_method(generated_values[i], init_guess, func);
        printf("\nTolerance: %lf", generated_values[i]);
        printf("\nRoot of f(x) where x in radians: %lf", root);
        printf("\nDielectric constant (e_r): %lf", e_r(root));
        printf("\nNumber of iterations: %d\n", iteration);
    }

    free(generated_values);
    return 0;
}

double newton_method(double tolerance, double init_guess, double (*f)(double))
{
    double deltax = tolerance * 2;
    double x0 = init_guess;
    while (fabs(deltax) > tolerance)
    {
        iteration +=1;
        deltax = func(x0) / dfunc_dx(x0);
        x0 = x0 - deltax;
    }
    return (x0);
}

double *tolerance_value_generator()
{
    double T = 1e-6;
    double *arr;
    arr = (double *)malloc(6 * sizeof(double));
    for (int i = 0; i < 6; i++)
    {
        arr[i] = T * pow(10, i);
    }
    return arr;
}

double func(double x)
{
    return tan(x) - K() * x;
}

double dfunc_dx(double x)
{
    return (1 / cos(x)) * (1 / cos(x)) - K();
}

double K()
{
    return (tan(2 * PI * (d + L) / lambda_g) / 2 / PI / (d / lambda_g));
}

double e_r(double x)
{
    return ((pow(a / d, 2) * pow(x / PI, 2)) + 1) / (pow((2 * a) / lambda_g, 2) + 1);
}

double deg2rad(double x)
{
    return x * PI / 180;
}