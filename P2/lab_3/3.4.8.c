#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256

int main()
{
    char s1[MAX_LEN], s2[MAX_LEN];
    int max_attempts=10;
    gets(s1);
    gets(s2);
    char *ptr= strstr(s1,s2);
    while(ptr != NULL && max_attempts!=0){
    char *from=ptr, *to=ptr+strlen(s2);
    strcpy( from,to);
    // printf("%p %s\n",ptr,s1);
    ptr = strstr(s1,s2);
    max_attempts--;
    }
    printf("%s",s1);
}