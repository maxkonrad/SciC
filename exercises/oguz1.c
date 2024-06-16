#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stackNode
{
    char data[100];
    int top;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr s, char c)
{
    s->data[++(s->top)] = c;
}

char pop(struct stackNode *s)
{
    //    if (is_empty(s)) {
    //        printf("Stack underflow\n");
    //        exit(EXIT_FAILURE);
    //    }burası neden hata veriyor anlamadım
    return s->data[(s->top)--];
}

// Check stack is empty
int is_empty(struct stackNode *s)
{
    return (s->top == -1);
}

int main(int argc, const char *argv[])
{
    StackNodePtr stackPtr = NULL;
    char c;
    
    printf("Enter a line of text\n");
    while ((c = getchar() != '\n'))
    {
        push(stackPtr, c);
    }

    return 0;
}