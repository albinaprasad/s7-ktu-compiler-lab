#include <stdio.h>
#include <string.h>

FILE * fp;
int b=0,s=0;
int reset()
{
    b=0;
    s=0;
    fseek(fp,-1,SEEK_CUR);
    return 1;
}

int dig(char ch)
{
    if(ch >= '0' && ch <= '9')
    return 1;

    return 0;
}

int op(char ch)
{
    if(ch == '*' || ch == '+' || ch == '-'|| ch == '/')
    return 1;

    return 0;
}


int iden(char ch) {
	if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_') return 1;
	return 0;
}

int key(char *buff)
{
    if(strcmp(buff,"main")==0 || strcmp(buff,"void")==0)
    return 1;

    return 0;
}

int sym(char ch) {
	if(ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == ';' || ch == ',') return 1;
	return 0;
}

void main()
{
    fp=fopen("input_1.txt","r");
    char buff[100],ch;

    while ((ch=fgetc(fp)) != EOF)
    {
        buff[b++]=ch;
        switch(s)
        {
            case 0:
                if(dig(ch))
                s=1;
                if(iden(ch))
                s=2;
                if(op(ch))
                s=3;
                if(sym(ch))
                s=4;

                break;
                case 1:
                if(!dig(ch))
                {
                    buff[b-1]='\0';
                    printf("digit :%s",buff);
                    reset();
                }
                break;
                case 2:
                if(!dig(ch) && !iden(ch))
                {
                    buff[b-1]='\0';
                if (key(buff))
                {
                    printf("keyword :%s",buff);
                }
                else{
                    printf("identifier :%s",buff);
                }
                reset();
                }
                break;

                case 3:
                 if(!op(ch))
                {
                    buff[b-1]='\0';
                    printf("digit :%s",buff);
                    reset();
                }
        }
        
    }
    
}