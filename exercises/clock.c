/*   Author: Furkan Selek
 *   Program: Clock (not finished)
 *   Copyright 2024
 */
#include <stdio.h>
#include <math.h>

#define HRADIUS 10
#define MRADIUS 10
#define PI 3.141593

void PrintPattern(float angle, int radius);
float hour2ang(int hour);
float min2ang(int min);

int main(void)
{
    int hour, min;
    printf("Please enter the hour (24-h): ");
    scanf("%d", &hour);

    printf("Please enter the min: ");
    scanf("%d", &min);
    PrintPattern(hour2ang(hour), HRADIUS);
    PrintPattern(min2ang(min), MRADIUS);

    return 0;
}

void PrintPattern(float angle, int radius)
{
    int endX = radius + (radius * cos(angle));
    int endY = radius + (radius * sin(angle));
    printf("ENDX = %d, ENDY= %d", endX, endY);
    printf("\n");
    for (int i = 0; i <= radius * 2; i++)
    {
        for (int j = 0; j <= radius * 2; j++)
        {
            if (j == radius && i == radius)
                printf("+");
            else if ((((i - radius) * (i - radius)) + ((j - radius) * (j - radius)) >= radius * radius) || floor((angle - (PI/2)) * 10) == floor(atan2(-i + radius, j - radius) * 10))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

float hour2ang(int hour)
{
    if (hour < 0 || hour >= 24)
    {
        return 0;
    }
    else
    {
        return (hour % 12) * PI / 6;
    }
}

float min2ang(int min)
{
    if (min < 0 || min > 60)
    {
        return 0;
    }
    else
    {
        return (min)*PI / 30;
    }
}