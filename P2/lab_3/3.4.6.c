#include <string.h>
int main()
{
    char a[100][100];
    int i, n, j, s = 0;
    scanf("%d ", &n);
    for (i = 1; i <= n; i++)
        gets(a[i]);
    for (i = 1; i <= n; i++)
    {
        if (a[i][strlen(a[i]) - 1] == '.' || a[i][strlen(a[i]) - 1] == '!' || a[i][strlen(a[i]) - 1] == '?')
        {
            for (j = i; j >= i - s; j--)
            {
                printf("%s\n", a[j]);
            }
            s = 0;
        }
        else
        {
            s++;
        }
    }
}