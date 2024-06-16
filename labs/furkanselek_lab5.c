#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PANEL_NUM 10

double fpower(double);
int *panel_generator();
double l_rectangular(double (*f)(double), double a, double b, int n);
double r_rectengular(double (*f)(double), double a, double b, int n);
double simpson(double (*f)(double), double a, double b, int n);

int main(void)
{
    double a, b;
    printf("Please insert a: ");
    scanf("%lf", &a);
    printf("\nPlease insert b: ");
    scanf("%lf", &b);
    int *panels;

    panels = panel_generator();
    printf("\n\t\t\t LEFT RECTANGULAR METHOD \t\t TRAPEZOIDAL METHOD \t\t SIMPSON'S METHOD\n");
    for (int i = 0; i < PANEL_NUM; i++)
    {
        printf("Number of panels: %d \t", panels[i]);
        printf("Left rectangular method: %.10lf \t", l_rectangular(fpower, a, b, panels[i]));
        printf("Trapezoidal method: %.10lf \t", (l_rectangular(fpower, a, b, panels[i]) + r_rectengular(fpower, a, b, panels[i]))/2);
        printf("Left rectangular method: %.10lf \t", simpson(fpower, a, b, panels[i]));
        printf("\n");
    }

    free(panels);
    return 0;
}

double fpower(double t)
{
    return 50 * exp(-25 * t)*pow(10,-3);
}

double l_rectangular(double (*f)(double), double a, double b, int n)
{
    double xstart = a;
    double step = (b - a) / (double)n;
    double area = 0;
    for (int i = 0; i < n; i++)
    {
        area += (f(xstart) * step);
        xstart += step;
    }

    return area;
}

double r_rectengular(double (*f)(double), double a, double b, int n)
{
    double step = (b - a) / (double)n;
    double xend = a + step;
    double area = 0;
    for (int i = 0; i < n; i++)
    {
        area += (f(xend) * step);
        xend += step;
    }

    return area;
}

double simpson(double (*f)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double area = 0;
    double x_start = a;
    for (int i = 0; i < n; i++)
    {
        area += (f(x_start) + 4 * f(x_start + (h / 2)) + f(x_start + h));
        x_start += h;
    }
    return area * h / 6;
}

int *panel_generator()
{
    int *n = (int *)malloc(sizeof(int) * PANEL_NUM);
    for (int i = 0; i < PANEL_NUM; i++)
    {
        n[i] = PANEL_NUM * (i + 1);
    }
    return n;
}