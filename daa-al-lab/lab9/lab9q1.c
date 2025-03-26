#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *createHashTable(char str[])
{
    int n = strlen(str);
    int *alph = (int *)calloc(256, sizeof(int));
    for (int i = 0; i < 256; i++)
        alph[i] = n;
    for (int i = n - 2; i >= 0; i--)
    {
        if (alph[(int)str[i]] == n)
            alph[(int)str[i]] = n - i - 1;
    }
    return alph;
}

int horspool(char s[], char p[])
{
    int *alph = createHashTable(p);
    int i = 0;
    int j = 0;
    int sn = strlen(s);
    int pn = strlen(p);
    while (i <= sn - pn)
    {
        while (j < pn && s[i + j] == p[j])
            j++;
        if (j == pn)
        {
            free(alph);
            return i;
        }
        i += alph[(int)s[i + pn - 1]];
        j = 0;
    }
    free(alph);
    return -1;
}

int main()
{
    char s[] = "this_is_a_demo_of_horspool_success";
    char p[] = "demo";
    printf("\n%d\n", horspool(s, p));
    return 0;
}
