#include <stdio.h>

int GCDIntCheck(int m, int n)
{
    int opcount = 0;
    for (int i = (m < n) ? m : n; i > 0; i--)
    {
        opcount++;
        if (m % i == 0 && n % i == 0)
        {
            printf("Operation Count: %d\n", opcount);
            return i;
        }
    }
}

int main()
{
    int m, n;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &m, &n);
    printf("GCD: %d\n", GCDIntCheck(m, n));
}