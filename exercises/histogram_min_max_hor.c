/*   Author: Furkan Selek
 *   Program: Min Max Histogram Horizontal
 *   Copyright 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define EXIT_SUCCESS 0

int main()
{
    int min, max;
    printf("Enter Min Value (e.g. 0): ");
    scanf("%d", &min);

    printf("Enter Max Value (e.g. 10): ");
    scanf("%d", &max);
    max += 1;
    srand(time(0));

    if (min >= max)
    {
        printf("min number can't be greater than or equal to max number\n");
        return 0;
    }

    int num[N] = {0};
    int *freq_num = (int *)malloc((max - min) * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        num[i] = min + (rand() % (max - min + 1));
        freq_num[num[i]] += 1;
    }

    for (int i = 20; i > 0; i--)
    {
        for (int j = 0; j < max - min; j++)
        {
            if (freq_num[j] >= i)
            {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = min; i < max; i++)
    {
        printf("%d", i);
    }
    printf("\n");

    free(freq_num);
    return EXIT_SUCCESS;
}