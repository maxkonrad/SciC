/*
AUTHOR: FURKAN SELEK
EE204 HW1T3
COPYRIGHT 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double x);
double f2(double x);

int *generate_panel();

double rectengular(double (*f)(double), int, double, double);
double trapezoidal(double (*f)(double), int, double, double);

int main(void)
{
    double x_start = 0;
    double x_end = 30;
    int num_panels = 20;

    int *panels = generate_panel();
    printf("\t\t\t RECT f1  \t  TRAP f1  \t  RECT f2  \t  TRAP f2  \t  A_RECT  \t  A_TRAP\n");
    double rect_f1;
    double trap_f1;
    double rect_f2;
    double trap_f2;

    double rect_area;
    double trap_area;

    for (int i = 0; i < num_panels; i++)
    {
        rect_f1 = rectengular(f1, panels[i], x_start, x_end);
        trap_f1 = trapezoidal(f1, panels[i], x_start, x_end);
        rect_f2 = rectengular(f2, panels[i], x_start, x_end);
        trap_f2 = trapezoidal(f2, panels[i], x_start, x_end);

        rect_area = rect_f2 - rect_f1;
        trap_area = trap_f2 - trap_f1;
        printf("Number of panels: %d\t %.5lf \t %.5lf \t %.5lf \t %.5lf \t %.5lf \t %.5lf\n", panels[i], rect_f1, trap_f1, rect_f2, trap_f2, rect_area, trap_area);
    }

    free(panels);
    return 0;
}

double f1(double x){
    return exp(-0.1*pow(x,2));
}
double f2(double x){
    return 2* exp(-0.2*x);
}

int *generate_panel()
{
    int *arr;
    double x = 50;
    arr = (int *)malloc(20 * sizeof(int));
    for (int i = 0; i < 20; i++)
    {
        arr[i] = x * (i+1);
    }

    return arr;
}

double rectengular(double (*f)(double), int num_panel, double x_start, double x_end)
{
    double x = (double) x_start;
    double delta = (x_end - x_start) / num_panel;
    double area = 0;
    for (int i = 0; i < num_panel; i++)
    {
        area += f(x) * delta;
        x += delta;
    }

    return area;
}

double trapezoidal(double (*f)(double), int num_panel, double x_start, double x_end)
{
    double x = (double) x_start;
    double delta = (x_end - x_start) / num_panel;
    double area = 0;
    for (int i = 0; i < num_panel; i++)
    {
        area += f(x) * delta + ((f(x + delta) - f(x)) * delta / 2);
        x += delta;
    }

    return area;
}