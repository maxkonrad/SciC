#include <stdio.h>
#include <string.h>

int main(void)
{
    struct student
    {
        char firstname[16];
        char lastname[32];
        int grade;
        int id_num;
    };

    struct student class[32];
    char filename[32] = "Class.txt";


    FILE *file_ptr;
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL)
    {
        printf("Not able to open the file.");
        return 0;
    }
    for (int i = 0; i < 18; i++)
    {
        fscanf(file_ptr, "%d %s %s %d", &class[i].id_num, class[i].firstname, class[i].lastname, &class[i].grade);
    }
    printf("ID, FIRST NAME, LAST NAME, GRADE\n");

    for (int i = 0; i < 18; i++){
        printf("%d, %s, %s, %d", class[i].id_num, class[i].firstname, class[i].lastname, class[i].grade);
        printf("\n");
    }

    fclose(file_ptr);
    return 0;
}