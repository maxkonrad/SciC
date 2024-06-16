#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct stackNode *StackNodePtr;

struct stackNode
{
    char data;
    StackNodePtr nextPtr;
};

void push(StackNodePtr *topPtr, char info);
char pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);

int main()
{
    StackNodePtr stackPtr = NULL;
    char c;
    printf("Enter a line of text: ");
    while ((c = getchar()) != '\n')
    {
        push(&stackPtr, c);
    }

    while(!isEmpty(stackPtr)){
        printf("%c", pop(&stackPtr));
    }
    printf("\n");
    return 0;
}

void push(StackNodePtr *topPtr, char info)
{
    StackNodePtr newPtr;
    newPtr = malloc(sizeof(struct stackNode));
    if (newPtr != NULL) {
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    } else {
        printf("Memory not allocated.\n");
    }
}

char pop(StackNodePtr *topPtr)
{
    if (*topPtr != NULL) {
        StackNodePtr tempPtr;
        char popValue;

        tempPtr = *topPtr;
        popValue = (*topPtr)->data;
        *topPtr = (*topPtr)->nextPtr;
        free(tempPtr);

        return popValue;
    } else {
        printf("Stack is empty.\n");
        return '\0'; // Return null character if stack is empty
    }
}

int isEmpty(StackNodePtr topPtr)
{
    return topPtr == NULL;
}
