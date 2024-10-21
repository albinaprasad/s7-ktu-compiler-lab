#include<stdio.h>
#include<string.h>
int main(){
	int s, n, i, j, z, start_state, final_state, current_input, current_state;
	char str[50];
	printf("Enter the no. of states: ");
	scanf("%d",&s);
	int state[s];
	printf("Enter the no. of inputs: ");
	scanf("%d",&n);
	int input[n];
	int transition[s][n];
	for(i=0;i<s;i++){
		printf("Enter the state: ");
		scanf("%d",&state[i]);
	}
	
	printf("Enter start state: ");
	scanf("%d",&start_state);
	
	printf("Enter final state: ");
	scanf("%d",&final_state);
	
	printf("Enter the inputs: ");
	for(i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	printf("Enter Transition State:\n");
	for(i=0;i<s;i++){
		for(j=0;j<n;j++){
			printf("(q%d,%d)=q",state[i],input[j]);
			scanf("%d",&transition[state[i]][input[j]]);
		}
	}
	do{
		printf("Enter input String: ");
		scanf("%s",str);
		
		current_state=start_state;
		for(i=0;i<strlen(str);i++){
			current_input=str[i] - '0';
			current_state=transition[current_state][current_input];
		}
		if(current_state==final_state)
			printf("String is accepted.\n");
		else
			printf("String is NOT accepted.\n");
		printf("do u want to continue?\n1 for yes\n0 for no\n");
		scanf("%d",&z);
	}while(z==1);
	
	return 0;
}