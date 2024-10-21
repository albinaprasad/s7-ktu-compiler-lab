#include<stdio.h>
#include<string.h>

struct {
    char op[2],a1[10],a2[10],res[10];
}in[10];
int i=0,n;

void main()
{
    printf("Ente the number");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Ente the string");
        scanf("%s%s%s%s",in[i].op,in[i].a1,in[i].a2,in[i].res);
    }
    
    for (size_t i = 0; i < n; i++)
    {
        if(strcmp(in[i].op,'+')==0)
        {
            printf("\nmov R0  %s",in[i].a1);
            printf("\nADD R0  %s",in[i].a2);
            printf("\nmov %s  R0",in[i].res);
        }
        
        if(strcmp(in[i].op,"-")==0)
        {
            printf("\nmov R0  %s",in[i].a1);
            printf("\nSUB R0  %s",in[i].a2);
            printf("\nmov %s  R0",in[i].res);
        }
        

    }
    

}