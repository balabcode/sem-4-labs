#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int num;
    struct node *next;
};

bool prime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    struct node *num1 = (struct node *)malloc(sizeof(struct node));
    struct node *num2 = (struct node *)malloc(sizeof(struct node));

    int m, n, count = 0;
    printf("Enter m and n: ");
    scanf("%d %d", &m, &n);

    struct node *temp1 = num1;
    struct node *temp2 = num2;

    for (int i = 1; i <= m; i++)
    {
        count++;
        if (prime(i) && m % i == 0)
        {
            temp1->num = i;
            temp1->next = (struct node *)malloc(sizeof(struct node));
            temp1 = temp1->next;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        count++;
        if (prime(i) && n % i == 0)
        {
            temp2->num = i;
            temp2->next = (struct node *)malloc(sizeof(struct node));
            temp2 = temp2->next;
        }
    }

    temp1->next = NULL;
    temp2->next = NULL;

    int gcd = 1;

    while (num1->next != NULL && num2->next != NULL)
    {
        if (num1->num == num2->num)
        {
            gcd *= num1->num;
            num1 = num1->next;
            num2 = num2->next;
        }
        else if (num1->num > num2->num)
        {
            num2 = num2->next;
        }
        else
        {
            num1 = num1->next;
        }
    }

    printf("sum: %d", m + n);
    printf("count: %d", count);
    printf("GCD: %d\n", gcd);

    free(num1);
    free(num2);

    return 0;
}