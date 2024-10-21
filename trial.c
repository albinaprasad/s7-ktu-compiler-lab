#include <stdio.h>
#include <string.h>

char e[100];
char temp='Z';

void main()
{
    int i;
 printf("Enter the expression: ");
    scanf("%s", e);

    int l =strlen(e);
    while(strlen(e)>3)
    {
        int flag=0;
        if(flag!=1)
        {
            for ( i = 0; i < l; i++)
            {
                if(e[i]=='*' || e[i]=='/')
                {
                    printf("%c=%c%c%c\n", temp, e[i - 1], e[i], e[i + 1]);
                    e[i-1]=temp;
                    temp--;

                
                for ( int j = i; e[j] !='\0'; j++)
                {
                    e[j]=e[j+2];
                    
                }
                     flag=1;
                    break;
            }
            }
            
        }
        if(flag!=1)
        {
            for ( i = 0; i < l; i++)
            {
                if(e[i]=='+' || e[i]=='-')
                {
                    printf("%c=%c%c%c\n", temp, e[i - 1], e[i], e[i + 1]);
                    e[i-1]=temp;
                    temp--;

                
                for ( int j = i; e[j] !='\0'; j++)
                {
                    e[j]=e[j+2];
                  
                }

                flag=1;
                break;
                }
            }
            
        }

    }
printf("\n%s",e);
}