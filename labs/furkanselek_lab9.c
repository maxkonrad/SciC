#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

struct data_vec
{
    int coord[2];
    double mag;
    double phase;
};

struct stack_vec
{
    int count;
    struct data_vec data[3];
};
void prompt_vals(struct data_vec *data);
void init_stack(struct stack_vec *);
void push(struct stack_vec *stack, struct data_vec data);
struct data_vec pop(struct stack_vec *stack);
void calc_vals(struct data_vec *data);
void print_stack(struct stack_vec stack);

int main(void)
{
    struct data_vec data1;
    struct data_vec data2;
    struct data_vec data3;
    struct stack_vec stack;

    init_stack(&stack);
    prompt_vals(&data1);
    calc_vals(&data1);
    prompt_vals(&data2);
    calc_vals(&data2);
    prompt_vals(&data3);
    calc_vals(&data3);
    push(&stack, data1);
    push(&stack, data2);
    push(&stack, data3);
    if (stack.data[0].mag == stack.data[1].mag)
    {
        struct data_vec temp = pop(&stack);
        pop(&stack);
        push(&stack, temp);
    }
    else if (stack.data[1].mag == stack.data[2].mag)
    {
        pop(&stack);
    }

    print_stack(stack);

    return 0;
}

void prompt_vals(struct data_vec *data)
{
    printf("\nPlease enter x: ");
    scanf("%d", &(data->coord[0]));

    printf("\nPlease enter y: ");
    scanf("%d", &(data->coord[1]));
}

void init_stack(struct stack_vec *stack)
{
    stack->count = 0;
}

void push(struct stack_vec *stack, struct data_vec data)
{
    if (stack->count < 3)
    {
        stack->data[stack->count] = data;
        stack->count++;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

struct data_vec pop(struct stack_vec *stack)
{
    stack->count--;
    return stack->data[stack->count - 1];
}

void calc_vals(struct data_vec *data)
{
    data->mag = sqrt(pow(data->coord[0], 2) + pow(data->coord[1], 2));
    data->phase = 180 * atan2(data->coord[1], data->coord[0]) / M_PI;
    printf("\n* Magnitude of the vector is %lf", data->mag);
    printf("\n* Phase of the vector is %lf", data->phase);
}

void print_stack(struct stack_vec stack)
{   
    printf("\n");
    for (int i = 0; i < stack.count; i++)
    {
        printf("x = %d, y = %d, Mag = %lf, x = %lf", stack.data[i].coord[0], stack.data[i].coord[1], stack.data[i].mag, stack.data[i].phase);
        printf("\n");
    }
}