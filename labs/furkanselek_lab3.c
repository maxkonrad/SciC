#include <stdio.h>
#include <math.h>

double EPS = 1e-5;

double f_Id(double VD);
double (*f)(double);
double bisect(double (*f)(double), double, double, double, double);

double Is = 1e-12; // A
int N = 1;
double VT = 0.026; // V
static int iteration = 1;

int main(void)
{
    double x1 = -1, x2 = 1;
    double Idiode;
    printf("For verification: Is(0.6V) = 0.010524A = %lf A\n", f_Id(0.6));
    printf("Please insert diode current Id: ");
    scanf("%lf", &Idiode);
    printf("\nApproximate root (diode voltage) = %lfV\n", bisect(f_Id, x1, x2, EPS, Idiode));
    printf("Total iterations = %d\n", iteration);
    return 0;
}

double f_Id(double VD)
{
    return Is * (exp(VD/N/VT) - 1);
}

double bisect(double (*f)(double), double x1, double x2, double epsilon, double Idiode)
{
    double y;
    for (y = (x1 + x2) / 2.0; fabs(x1 - y) > epsilon; y = (x1 + x2) / 2.0)
    {
        iteration += 1;
        if ((f(x1)- Idiode) * (f(y) - Idiode) <= 0)
        {
            x2 = y;
        }
        else
        {
            x1 = y;
        }
    }
    return (y);
}
