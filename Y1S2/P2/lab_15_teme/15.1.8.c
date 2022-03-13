

#include<stdio.h>
#include<string.h>
int main()
{
    int i,contor0=0,contor1=0,schimbare=-1;
    char s[100];
    scanf("%s",&s);
    for (i=0; i<=strlen(s)-1; i++)
    {
        if(schimbare==-1)
        {
            if(s[i]=='0')
            {
                contor0++;
                schimbare=0;
            }
            else
            {
                contor1++;
                schimbare=1;
            }
            continue;
        }
        if(s[i]=='0'&&schimbare==1)
        {
            contor0++;
            schimbare=0;
            continue;
        }
        else if(s[i]=='1'&&schimbare==0)
        {
            schimbare=1;
            contor1++;
            continue;
        }
    }
    if(contor0==contor1)
        printf("%d inversari ale secventelor formate din 1 sau 0",contor0);
    else if(contor0<contor1)
        printf("%d inversari ale secventelor formate din 0",contor0);
    else
        printf("%d inversari ale secventelor formate din 1",contor1);
    return 0;
}


