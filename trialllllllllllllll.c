#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char a[10][10],f[10];
char ch;
int m,i=0,j=0,n;

void first(char c);
void  follow(char c);


void main()
{
    int z;
    char c;

    printf("Enter the number of productions:\n");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%s%c",a[i],&ch);
    }
    
    do
    {
         m=0;
        printf("Enter the element whose First & Follow is to be found: ");
        scanf("%c", &c);
        first(c);
        printf("First(%c) = {", c);
        for (i = 0; i < m; i++) {
            printf("%c", f[i]);
        }
        printf("}\n");

        m=0;
        strcpy(f," ");

        follow(c);
        printf("Follow(%c) = {", c);
        for (i = 0; i < m; i++) {
            printf("%c", f[i]);
        }
        printf("}\n");

       printf("Enter the number of z:\n");
    scanf("%d%c", &z,&ch);

    } while (z==1);
    
}

void first(char c)
{
    int k;
    if(!isupper(c))
    {
        f[m++]=c;
        return;
    }

    for ( k = 0; k < n; k++)
    {
        if (a[k][0]== c)
        {
            if (a[k][2]=='$')
            {
                follow(a[k][0]);
            }
            else if(islower(a[k][2]))
            {
                f[m++]=a[k][2];
            }
            else{
                first(a[k][2]);
            }
            
        }
        
    }
    
}

void follow(char c)
{
    if(a[0][0]==c)
    {
        f[m++]='$';
    }


    for ( i = 0; i < n; i++)
    {
        for(j=2;j<strlen(a[i]);j++)
        {
            if (a[i][j]==c)
            {
                if (a[i][j+1] != '\0')
                {
                    first(a[i][j+1]);
                }
                if (a[i][j+1] == '\0' && c != a[i][0])
                {
                    follow(a[i][0]);
                }
            }
            
        }
    }
    
}