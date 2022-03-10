#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256

void printLines(char **cuv, int start, int end, int reverse)
{
    int i;

    if (reverse == 1)
    {
        for (i = end; i >= start; i--)
            printf("%s\n", cuv[i]);
    }
    // else
    // {
    //     for (i = start; i >= end; i--)
    //         printf("%s\n", cuv[i]);
    // }
}

int main()
{
    int n, m, i, x;
    int start = 0, end = 0, current = 0;
    char **cuv;
    scanf("%d", &n);
    cuv = malloc(MAX_LEN * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        cuv[i] = malloc(MAX_LEN * sizeof(char *));
        gets(cuv[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (strchr(cuv[i], '.') != 0 || strchr(cuv[i], '?') != 0 || strchr(cuv[i], '!') != 0)
        {
            printLines(cuv, start, i, 1);
            start = i;
        }
    }
    printLines(cuv, start, i - 1, 0);
}