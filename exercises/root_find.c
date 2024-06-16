#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

struct Node {
    char c_code[N];
    char courses[N];
    struct Node *next;
};

typedef struct Node* course_list;

void insert_front(int c_select, course_list *clist);
void insert_rear(int c_select, course_list *clist);
int course_check(int c_select, course_list list);
void print_cl(course_list list);

char *c[6];
char *d[6];

int main(void) {
    c[0] = "EE311";
    d[0] = "Digital Electronics";
    c[1] = "EE411";
    d[1] = "Fundamentals of Photonics";
    c[2] = "EE425";
    d[2] = "Microwave Engineering";
    c[3] = "EE443";
    d[3] = "Embedded Systems";
    c[4] = "EE455";
    d[4] = "Mobile Communication";
    c[5] = "EE461";
    d[5] = "Nonlinear Control Systems";
    
    course_list list = NULL;
    int oSel, CSel;
    
    while (1) {
        printf("Please Choose an Operation\n");
        printf("1-Add a course in front of the Course List\n");
        printf("2-Add a course at the end of the Course List\n");
        scanf("%d", &oSel);
        printf("Select a Course\n");
        
        for (int i = 0; i < 6; i++) {
            printf("%d. %s-%s\n", i + 1, c[i], d[i]);
        }
        
        scanf("%d", &CSel);
        
        if (CSel < 1 || CSel > 6) {
            printf("Please insert a valid course\n");
            continue;
        }
        
        if (!course_check(CSel - 1, list)) {
            continue;
        }
        
        switch (oSel) {
            case 1:
                insert_front(CSel - 1, &list);
                break;
            case 2:
                insert_rear(CSel - 1, &list);
                break;
            default:
                printf("Please select either add_front or add_end option (1 or 2)\n");
                break;
        }
        
        printf("The updated course list:\n");
        print_cl(list);
        printf("\n");
    }
    
    return 0;
}

void insert_front(int c_select, course_list *clist) {
    course_list node = (course_list)malloc(sizeof(struct Node));
    strcpy(node->c_code, c[c_select]);
    strcpy(node->courses, d[c_select]);
    node->next = *clist;
    *clist = node;
}

void insert_rear(int c_select, course_list *clist) {
    course_list node = (course_list)malloc(sizeof(struct Node));
    strcpy(node->c_code, c[c_select]);
    strcpy(node->courses, d[c_select]);
    node->next = NULL;
    
    if (*clist == NULL) {
        *clist = node;
    } else {
        course_list temp = *clist;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

int course_check(int c_select, course_list list) {
    while (list != NULL) {
        if (strcmp(c[c_select], list->c_code) == 0) {
            printf("The course is already inserted\n");
            return 0;
        }
        list = list->next;
    }
    return 1;
}

void print_cl(course_list list) {
    while (list != NULL) {
        printf("Course Code: %s, Course Name: %s\n", list->c_code, list->courses);
        list = list->next;
    }
}