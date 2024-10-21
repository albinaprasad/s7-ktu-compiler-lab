//my code
char stk[100];
int i=0;
int error =0;

 void E();
 void Ep();
 void T();
 void Tp();

#include <stdio.h>
#include <string.h>
void main()
{
    printf("ENter the string");
    scanf("%s",stk);
    E();

    if(strlen(stk)== i && error==0)
    {
        printf("Accepted");
    }

else{
    printf("Rejectded");
}

}
void E()
{
    T();
    Ep();
}

void Ep()
{
    if( stk[i] == '+')
    {
        i++;
        T();
        Ep();
    }
}

void T()
{
    F();
    Tp();
}

void Tp()
{
    if(stk[i]=='*')
    {
        i++;
        F();
        Tp();
    }
}

void F()
{
    if(stk[i] == '(')
    {
        i++;
        E();
        if(stk[i] == ')')
        {
            i++;
        }
        else
        {
            error=1;
        }
    }
   
    
       else if(stk[i] == 'a')
        {
            i++;
        }
    
    else 
    {
        error=1;

    }
}
