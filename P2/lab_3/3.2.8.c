#include <stdio.h>
#include <string.h>

int verifAnagrame(char a[], char b[]){
    int vfrec1[101], vfrec2[101], i;
  for (i = 0; i <= 100; i++)
    {
        vfrec1[i] = 0;
        vfrec2[i] = 0;
    }

    if (strcmp(a, b) == 0)
    {
        return 0;
    }

    for (i = 0; i < strlen(a); i++)
    {
        const firstLetter = (a[i] >= 'a' && a[i] <= 'z') ? 'a' : 'A';
        vfrec1[(int)a[i] - firstLetter]++;
    }
    for (i = 0; i < strlen(b); i++)
    {
        const firstLetter = (b[i] >= 'a' && b[i] <= 'z') ? 'a' : 'A';
        vfrec2[(int)b[i] - firstLetter]++;
    }
    for (i = 0; i <= 100; i++)
        if (vfrec1[i] != vfrec2[i])
        {
            return 0;
        }
        return 1;
}

int main()
{
    char a[100], b[100];
    fflush(stdin);
    gets(a);
    fflush(stdin);
    gets(b);
    printf("%d",verifAnagrame(a,b));
  
    return 0;
}