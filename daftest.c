#include<stdio.h>
#include<string.h>

void main()
{
    int start ,final,s,n,cur,curv;
    int in[10],state[10],trans[10][10];
     char str[10];
     int z;
    printf("Enter the no. of states: ");
	scanf("%d",&s);
    printf("Enter the no. of inputs: ");
	scanf("%d",&n);
        printf("Enter the no. of strat: ");
	scanf("%d",&start);
    printf("Enter the no. of final: ");
	scanf("%d",&final);


    for (size_t i = 0; i < s; i++)
    {
        printf("Enter the  states: ");
	     scanf("%d",&state[i]);
    }
    
    for (size_t i = 0; i < n; i++)
    {
        printf("Enter the  inputs: ");
	     scanf("%d",&in[i]);
    }
    
    for (size_t i = 0; i < s; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
        printf("\nq%d,%d->q",state[i],in[j]);
	    scanf("%d",&trans[state[i]][in[j]]);
        }
    }

    printf("\nenter string");
    scanf("%s",str);

    do
    {
        cur=start;
        for (size_t i = 0; i < strlen(str); i++)
        {
            curv=str[i]-'0';
            cur=trans[cur][curv];
        }
        		if(cur==final)
			printf("String is accepted.\n");
		else
		printf("String is NOT accepted.\n");
        
		printf("do u want to continue?\n1 for yes\n0 for no\n");
		scanf("%d",&z);
    } while (z==1);
    
        
    
}