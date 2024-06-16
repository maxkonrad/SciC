/*   Author: Furkan Selek
 *   Program: F C K Converter
 *   Copyright 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define ERROR_INVALID_CHARACTER 1
#define ERROR_OVERFLOW 2

int str_to_float(char *str, float *num);

int main(int argc, char **argv)
{
    float fahr = 0, kelv = 0, celc = 0, prompted_value = 0;
    float *prompted_num = &prompted_value;
    char *prompt;

    if (argc == 3)
    {
        int retval = str_to_float(argv[2], prompted_num);
        if (retval == SUCCESS)
        {
            if (strcmp(argv[1], "--fahrenheit") == 0 || strcmp(argv[1], "-f") == 0)
            {
                prompt = "Fahrenheit";
                fahr = prompted_value;
                celc = (fahr - 32) * 5.0 / 9.0;
                kelv = celc + 273.15;
            }
            else if (strcmp(argv[1], "--celsius") == 0 || strcmp(argv[1], "-c") == 0)
            {
                prompt = "Celsius";
                celc = prompted_value;
                fahr = (celc * 9.0 / 5.0) + 32;
                kelv = celc + 273.15;
            }
            else if (strcmp(argv[1], "--kelvin") == 0 || strcmp(argv[1], "-k") == 0)
            {
                prompt = "Kelvin";
                kelv = prompted_value;
                celc = kelv - 273.15;
                fahr = (celc * 9.0 / 5.0) + 32;
            }
            printf("%.2f %s is: %.2f Fahrenheit, %.2f Celsius, and %.2f Kelvin\n", prompted_value, prompt, fahr, celc, kelv);
        }
        else
        {
            printf("Invalid argument %s\n", argv[2]);
            return EXIT_FAILURE;
        }
    }
    else
    {
        printf("Invalid number of arguments, argument count: %d\n", argc);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


int str_to_float(char *str, float *num)
{
    float sign = 1.0;
    int decimal_found = 0;
    *num = 0.0;
    if (*str == '-')
    {
        sign = -1.0;
        ++str;
    }
    else if (*str == '+')
    {
        ++str;
    }
    while (*str)
    {
        if (*str == '.')
        {
            if (decimal_found)
            {
                printf("Error: multiple decimal points encountered.\n");
                return ERROR_INVALID_CHARACTER;
            }
            decimal_found = 1;
        }
        else if (*str >= '0' && *str <= '9')
        {
            if (decimal_found)
            {
                *num += (*str - '0') * (sign / (10.0 / sign)); 
                sign *= 10.0;
            }
            else
            {
                *num = *num * 10.0 + (*str - '0'); 
            }
        }
        else
        {
            printf("Error: non numeric character '%c' encountered.\n", *str);
            return ERROR_INVALID_CHARACTER;
        }
        str++;
    }

    *num *= (sign < 0) ? -1 : 1;
    return SUCCESS;
}
