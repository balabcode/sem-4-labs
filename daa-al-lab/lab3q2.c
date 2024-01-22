#include <stdio.h>
#include <string.h>

// brute force string matching

void string_search(char *string, char *pattern)
{
    int n = strlen(string) - 1;
    int m = strlen(pattern) - 1;
    int i = 0;
    int found = 0;
    int opcount = 0;
    for (; i < n - m + 1; i++)
    {
        int j = 0;
        for (; j < m; j++)
        {
            opcount++;
            if (string[i + j] != pattern[j])
                break;
        }
        if (j == m)
        {
            found = 1;
            break;
        }
    }
    if (found)
        printf("Found pattern at index: %d\n", i);
    else
        printf("Could not find the pattern\n");
    printf("Opcount: %d\n", opcount);
}

int main()
{
    char str[100], target[100];
    printf("Enter string: ");
    fgets(str, 100, stdin);
    printf("Enter substring: ");
    fgets(target, 100, stdin);
    string_search(str, target);
}