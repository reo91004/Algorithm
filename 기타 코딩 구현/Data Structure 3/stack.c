#include "stack.h"
#include "graph.h"

void stackcreate(STACK* s)
{
    s->top = NULL;
}

int stackisEmpty(STACK* s)
{
    if (s->top == NULL) return 1;
    return 0;
}

void push(STACK* s, int item)
{
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = item;

    newnode->next = s->top;
    s->top = newnode;
}

int pop(STACK* s)
{
    node* deleted_node;
    deleted_node = s->top;
    int data;
    if (!stackisEmpty(s)) data = deleted_node->data;
    else data = -1;
    s->top = s->top->next;
    free(deleted_node);

    return data;
}

int top(STACK* s)
{
    return s->top->data;
}