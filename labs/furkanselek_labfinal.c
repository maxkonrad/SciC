#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double h = 1E-4;
// h is the infintesmall value here, if it was bigger, our scale would be bigger

double derivative(double (*f)(double x), double x);
double func(double x);
double newton_rapshon(double x_init, double epsilon, double(*func)(double));

int main(void)
{
    double x0, epsilon;
    printf("Please insert x0: ");
    scanf("%lf", &x0);
    printf("\nPlease insert epsilon: ");
    scanf("%lf", &epsilon);

    printf("\nValue of root is equal to: %lf\n", newton_rapshon(x0, epsilon, func));
    return 0;
}

// Take the derivative as wanted
double derivative(double (*f)(double x), double x)
{
    return ((f(x + h) - f(x - h)) / (2*h));
}
// function implementation
double func(double x)
{
    return exp(x) - 3;
}
/*
here we have the key function I don't understand why it didn't work :(
*/ 
double newton_rapshon(double x_init, double epsilon, double(*func)(double))
{
    double delta = 2.0 * epsilon;
    while (fabs(delta) > epsilon)
    {
        delta = func(x_init) /derivative(func, x_init);
        x_init = x_init - delta;
    }
    return x_init;
}