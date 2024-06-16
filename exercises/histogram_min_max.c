/*   Author: Furkan Selek
 *   Program: Min Max Histogram
 *   Copyright 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define EXIT_SUCCESS 0

int main(){
    int min, max;
    printf("Enter Min Value (e.g. 0): ");
    scanf("%d", &min);

    printf("Enter Max Value (e.g. 10): ");
    scanf("%d", &max);
    max+=1;
    srand(time(0));

    if (min >= max){
        printf("min number can't be greater than or equal to max number\n");
        return 1;
    }

    int num[N] = {0};
    int * freq_num = (int*) malloc((max- min) * sizeof(int));
    for (int i = 0; i < N; i++){
        num[i] = min + (rand() % (max - min + 1));
        freq_num[num[i]] += 1;
    }

    for (int i = 0; i < max-min; i++){
        printf("%d has been used %5d times as follows: ", min + i, freq_num[i]);
        for (int j = 0; j < freq_num[i]; j++){
            printf("*");
        }
        printf("\n");
        }

    free(freq_num);
    return EXIT_SUCCESS;
}