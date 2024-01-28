#include <stdio.h>
#include <stdlib.h>

int tos = 0;
int opcount = 0;

int *findPrimeFactors(int x)
{
    tos = 0;
    int *temp = (int *)calloc(100, sizeof(int));
    int original = x;
    for (int i = 2; i <= original; i++)
    {
        opcount++;
        while (x % i == 0)
        {
            temp[++tos] = i;
            x = x / i;
        }
    }
    temp[0] = tos;
    return temp;
}

int GCDMiddleSchool(int m, int n)
{
    int *mFactors = findPrimeFactors(m);
    int *nFactors = findPrimeFactors(n);
    int gcd = 1;
    int i = 1, j = 1;
    while (i <= mFactors[0] && j <= nFactors[0])
    {
        opcount++;
        if (mFactors[i] == nFactors[j])
        {
            gcd *= mFactors[i];
            i++;
            j++;
        }
        else if (mFactors[i] <= nFactors[j])
            i++;
        else
            j++;
    }
    return gcd;
}

int main()
{
    printf("Enter two numbers: ");
    int m, n;
    scanf("%d %d", &m, &n);
    int gcd = GCDMiddleSchool(m, n);
    printf("GCD of %d and %d is %d\n", m, n, gcd);
    printf("Number of operations: %d\n", opcount);
    return 0;
}

// ANUJ GOATED
// #include <stdio.h>
// int opcount = 0;
// int nextPrime(int x, int i)
// {

//     for (i = i % 2 ? i + 2 : i + 1; i < x; i++)
//     {
//         int f = 0;
//         if (x % i == 0)
//         {
//             if (i % 2 == 0)
//                 f = 1;
//             for (int j = 3; j < i / 2; j += 2)
//             {
//                 opcount += 1;
//                 if (i % j == 0)
//                 {
//                     f = 1;
//                     break;
//                 }
//             }
//             if (f == 0)
//                 return i;
//         }
//     }
//     return i;
// }
// int findgcd(int m, int n)
// {
//     int c = m, d = n;
//     int f = 2;
//     int ans = 1;
//     while (f <= m && f <= n)
//     {
//         while (m % f == 0 && n % f == 0)
//         {
//             opcount++;
//             ans *= f;
//             m /= f;
//             n /= f;
//             printf("%d ", f);
//         }
//         int x = nextPrime(c, f);
//         int y = nextPrime(d, f);
//         // printf("%d %d\n",x,y);
//         while (x != y)
//         {
//             opcount++;
//             if (x >= c || y >= d)
//                 return ans;
//             if (x > y)
//                 y = nextPrime(d, y);
//             else
//                 x = nextPrime(c, x);
//         }
//         f = x;
//         // printf("%d\n",f);
//     }
//     return ans;
// }
// int main()
// {
//     unsigned int m, n;
//     printf("Enter numbers: ");
//     scanf("%d", &m);
//     scanf("%d", &n);
//     printf("\nGCD: %d", findgcd(m, n));
//     printf("\nOpcount: %d\n", opcount);
//     return 0;
// }