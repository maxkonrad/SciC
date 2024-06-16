#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x, double y);
double f_exact(double x, double y);
void prompt_values(double *x0, double *y0, double *h, double *xlast);
void euler_method(double x, double y, double x_last, double h, double *result);
void runge_kutta_method(double x, double y, double x_last, double h, double *result);
double percentage_err(double y_exact, double y_approx);

double mean_sq_err(double y_exact, double y_approx, double n);
double root_mean_sq_err(double mse);
double mean_abs_err(double y_exact, double y_approx, double n);
double mean_abs_per_err(double y_exact, double y_approx, double n);

int main(void)
{
    double x0, y0, h, xlast;
    double result_euler, result_rk;
    prompt_values(&x0, &y0, &h, &xlast);
    double result = f_exact(0.99, y0);
    euler_method(x0, y0, xlast, h, &result_euler);
    runge_kutta_method(x0, y0, xlast, h, &result_rk);

    double n = 100;

    printf("\nh \t\t y_euler \t y_runge \t y_exact \t per_err_euler \t per_err_rk \n");
    printf("\n%lf \t %lf \t %lf \t %lf \t %lf \t %lf \n", h, result_euler, result_rk, result, percentage_err(result, result_euler), percentage_err(result, result_rk));

    printf("Results for MSE, RMSE, MAE, MAPE err values\n");
    printf("ERR MSE (EULER): \t %lf\n", mean_sq_err(result, result_euler, n));
    printf("ERR MSE (RUNGE KUTTA): %lf\n", mean_sq_err(result, result_rk, n));

    printf("ERR RMSE (EULER): \t %lf\n", root_mean_sq_err(mean_sq_err(result, result_euler, n)));
    printf("ERR RMSE (RUNGE KUTTA): %lf\n", root_mean_sq_err(mean_sq_err(result, result_rk, n)));

    printf("ERR MAE (EULER):  \t %lf\n", mean_abs_err(result, result_euler, n));
    printf("ERR MAE (RUNGE KUTTA): %lf\n", mean_abs_err(result, result_rk, n));

    printf("ERR MAPE (EULER): \t %lf\n", mean_abs_per_err(result, result_euler, n));
    printf("ERR MAPE (RUNGE KUTTA): %lf\n", mean_abs_per_err(result, result_rk, n));

    return 0;
}

double f(double x, double y)
{
    return -6 * (double)exp(-2 * x) + y + 10;
}

double f_exact(double x, double y)
{
    return (2 * (double)exp(-2 * x)) + (9 * (double)exp(x)) - 10;
}

void prompt_values(double *x0, double *y0, double *h, double *xlast)
{
    printf("Please enter x0, y0, h, xlast in order:");
    scanf("%lf %lf %lf %lf", x0, y0, h, xlast);
}

void euler_method(double x, double y, double x_last, double h, double *result)
{
    while (x <= x_last)
    {
        y = y + h * f(x, y);
        x = x + h;
    }
    *result = y;
}

void runge_kutta_method(double x, double y, double x_last, double h, double *result)
{
    double ta, tb, tc, td;
    while (x <= x_last)
    {
        ta = h * f(x, y);
        tb = h * f(x + h / 2.0, y + ta / 2.0);
        tc = h * f(x + h / 2.0, y + tb / 2.0);
        td = h * f(x + h, y + tc);
        y = y + (ta + 2.0 * tb + 2.0 * tc + td) / 6.0;
        x = x + h;
    }
    *result = y;
}

double percentage_err(double y_exact, double y_approx)
{
    return (double) fabs((y_exact - y_approx) / y_exact) * 100;
}

double mean_sq_err(double y_exact, double y_approx, double n)
{
    double err = 0;
    for (int i = 0; i < n; i++)
    {
        err += (double) pow(y_exact - y_approx, 2);
    }
    return err / n;
}

double root_mean_sq_err(double mse)
{
    double err = (double)sqrt(mse);
    return err;
}

double mean_abs_err(double y_exact, double y_approx, double n)
{
    double err;
    for (int i = 0; i < n; i++)
    {
        err += (double) fabs(y_exact - y_approx);
    }
    err = err / n;
    return err;
}

double mean_abs_per_err(double y_exact, double y_approx, double n)
{
    double err = 0;
    for (int i = 0; i < n; i++)
    {
        err += (double) fabs((y_exact - y_approx) / y_exact);
    }
    err = err * 100 / n;
    return err;
}