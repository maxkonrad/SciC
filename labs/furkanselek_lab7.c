#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TOTAL_CARDS 13
#define CARDS_PER_PLAYER 3
#define PLAYERS 4

typedef struct
{
    char value;
} Card;

typedef struct
{
    Card items[TOTAL_CARDS];
    int stack_top;
} Stack;

void init_stack(Stack *_stack);
void push(Stack *_stack, Card new_card);
Card pop(Stack *_stack);
void shuffle_cards(Card *deck, int n);
void deal_cards(Stack *player_stacks[]);
void display_cards(Stack *player_stacks[]);
void check_winner(Stack *player_stacks[]);

int main(void)
{
    Stack *player_stacks[PLAYERS];
    for (int i = 0; i < PLAYERS; i++)
    {
        player_stacks[i] = (Stack *)malloc(sizeof(Stack));
        init_stack(player_stacks[i]);
    }

    deal_cards(player_stacks);
    display_cards(player_stacks);
    check_winner(player_stacks);

    for (int i = 0; i < PLAYERS; i++)
    {
        free(player_stacks[i]);
    }
    return 0;
}

void init_stack(Stack *_stack)
{
    _stack->stack_top = 0;
}

void push(Stack *_stack, Card new_card)
{
    if (_stack->stack_top < TOTAL_CARDS)
    {
        _stack->items[_stack->stack_top] = new_card;
        _stack->stack_top++;
    }
    else
    {
        return;
    }
}

Card pop(Stack *_stack)
{
    if (_stack[0].stack_top > 0)
    {
        _stack[0].stack_top--;
    }
    return _stack[0].items[_stack[0].stack_top];
}

void shuffle_cards(Card *deck, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int j = i + rand() % (n - 1);
        Card temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void deal_cards(Stack *player_stacks[])
{
    char values[] = {'A',
                     '2',
                     '3',
                     '4',
                     '5',
                     '6',
                     '7',
                     '8',
                     '9',
                     'T',
                     'J',
                     'Q',
                     'K'};
    Card *Deck = (Card *)malloc(sizeof(Card) * TOTAL_CARDS);
    for (int i = 0; i < TOTAL_CARDS; i++)
    {
        Deck[i].value = values[i];
    }
    shuffle_cards(Deck, TOTAL_CARDS);
    for (int i = 0; i < CARDS_PER_PLAYER; i++)
    {
        push(player_stacks[0], Deck[i]);
        push(player_stacks[1], Deck[i + 3]);
        push(player_stacks[2], Deck[i + 6]);
        push(player_stacks[3], Deck[i + 9]);
        // printf("\n%c", player_stacks[0]->items[0].value);
    }
}

void display_cards(Stack *player_stacks[])
{
    for (int i = 0; i < PLAYERS; i++)
    {
        printf("Player%d: ", i + 1);
        for (int j = 0; j < CARDS_PER_PLAYER; j++)
        {
            printf("%c ", player_stacks[i]->items[j].value);
        }
        printf("\n");
    }
}

void check_winner(Stack *player_stacks[])
{
    for (int i = 0; i < PLAYERS; i++)
    {
        for (int j = 0; j < CARDS_PER_PLAYER; j++)
        {
            if (player_stacks[i]->items[j].value == 'A')
            {
                printf("\nWinner is player %d", i + 1);
                return;
            };
        }
        printf("\n");
    }
}
