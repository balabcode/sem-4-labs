#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int top;
    int size;
} Stack;

Stack *createStack(int size)
{
    Stack *temp = (Stack *)calloc(1, sizeof(Stack));
    temp->size = size;
    temp->data = (int *)calloc(size, sizeof(int));
    temp->top = -1;
    return temp;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return (s->top == s->size - 1);
}

void push(Stack *s, int x)
{
    if (!isFull(s))
        s->data[++(s->top)] = x;
    else
        printf("Stack is full!\n");
}

int pop(Stack *s)
{
    if (!isEmpty(s))
        return (s->data[(s->top)--]);
    else
        return -69;
}

int peek(Stack *s)
{
    return s->data[s->top];
}

int display(Stack *s)
{
    printf("Stack Contents: ");
    for (int i = 0; i <= s->top; i++)
        printf("%d  ", s->data[i]);
    printf("\n\n");
}

// POSTFIX EVALUATION:
int isOperator(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '%');
}

void evaluatePostfix(char expression[])
{
    // Sample:  a+b*c/d -> (a+((b*c)/d)) -> abc*d/+
    Stack *s = createStack(10);
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (!isOperator(expression[i]))
        {
            push(s, expression[i] - '0');
        }
        else
        {
            int a = pop(s);
            int b = pop(s);
            switch (expression[i])
            {
            case (int)'*':
                push(s, a * b);
                break;

            case (int)'/':
                push(s, (double)b / a);
                break;

            case (int)'+':
                push(s, a + b);
                break;

            case (int)'-':
                push(s, b - a);
                break;
            }
        }
    }
    printf("The result is: %d\n", pop(s));
}