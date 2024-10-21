# include <stdio.h>
# include <string.h>


int demilter(char s)
{
return (s== ' '||s=='*'||s=='+'|| s=='-'|| s=='/'|| s=='{'|| s=='}'|| s==';');
}

int operator(char s)
{
return (s=='*'||s=='+'|| s=='-'|| s=='/');

}

int key(char* str1)
{
    char keyw[3][100]={"int","float","while"};
    int i;
    for ( i = 0; i < 3; i++)
    {
        if (strcmp(str1,keyw[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void toekn(char* str)
{
    int i=0;
    char buff[15];

    while (str[i] !='\0')
    {
        if (demilter(str[i]))
        {
            if(operator(str[i]))
            {
                printf("Operator %c\n",str[i]);
            }
            else 
            {
              printf("Delimter %c\n",str[i]);  
            }
            i++;
            continue;
        }
            int j=0;
            while (!demilter(str[i]) && str[i] != '\0')
            {
                buff[j]=str[i];
               j++;
               i++;
            }
            buff[j]='\0';
            
            if(key(buff)){
                printf("keyword %s\n",buff); 
            }              
    }
}


void main()
{
    char buffer[100]="{float}";
    toekn(buffer);


}