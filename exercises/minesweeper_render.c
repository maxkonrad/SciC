#include <stdio.h>
#include <time.h>

int main(void){

    int mine_num;
    printf("Enter N (number of mines): ");
    scanf("%d", &mine_num);

    int mine_arr[15][30] = {0};

    srand(time(0));

    for (int i = 0; i < mine_num; i++){
        int x = rand() % 30;
        int y = rand() % 15;

        if(mine_arr[y][x] == 1){
            i--;
        } else {
            mine_arr[y][x] = 1;
        }
    }

    printf("Here’s the random minefield: \n");

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 30; j++){
            if (mine_arr[i][j] == 1) printf ("x");
            else printf("0");
        }
        printf("\n");
    }

    return 0;

}