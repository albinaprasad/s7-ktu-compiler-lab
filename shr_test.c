#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char ac[10],s[50],a[15],act[100];
int i=0,j=0,c=0;
void check();

int main()
{
    printf("Enter the string \n");
    scanf("%s",a);
    printf("stack \t input\t action\n");
    c= strlen(a);
    
     for(i=0;j<c;i++,j++){
        
        strcpy(ac,"SHIFT");
        s[i]=a[j];
        s[i+1]='\0';
        a[j]=' ';
        printf("\n$%s\t %s \t",s,a);
         check();

     }
     if(s[0]=='E' && s[1]=='\0')
     {
        printf("\nAccepted\n");
     }
}
void check()
{
    strcpy(act,"REDUCE  -->E");

    for(int z=0;z<c;z++)
    {
        if(s[z]== 'i')
        {
            printf("%s",act);
            s[z]='E';
            s[z+1]='\0';
            printf("\n$%s\t %s \t",s,a);
        }
    }

        for(int z=0;z<c;z++)
    {
        if(s[z]== 'E' && s[z+1]== '+' &&  s[z+2]== 'E')
        {
            printf("%s",act);
            s[z]='E';
            s[z+1]='\0';
            s[z+2]== '\0';
            i=i-2;
            printf("\n$%s\t %s \t",s,a);
        }
    }

     for(int z=0;z<c;z++)
    {
        if(s[z]== 'E' && s[z+1]== '*' &&  s[z+2]== 'E')
        {
            printf("%s",act);
            s[z]='E';
            s[z+1]='\0';
            s[z+2]== '\0';
            i=i-2;
            printf("\n$%s\t %s \t",s,a);
        }
    }
}