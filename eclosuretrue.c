#include <stdio.h>
#define st 10 // Maximum handle limit

int arr[st][st];
int visited[st], seen[st];

void eps(int node) {
	if(visited[node]) return;
	visited[node] = 1;
	printf("%d ", node); 
	for(int i = 0; i < st; i++) 
    if(arr[node][i]) eps(i);
}

void main() {
	FILE *fp = fopen("td.txt","r");
	int s1, s2; char in;
	while(fscanf(fp, "%d %c %d", &s1, &in, &s2) != EOF) {
		seen[s1] = 1; 
		seen[s2] = 1;
		if(in == 'e') arr[s1][s2] = 1;
	}
	fclose(fp);
	
	for(int i = 0; i < st; i++) { 
		if(!seen[i]) continue;
		printf("E-CLOSURE(%d) = ", i);
		for(int j = 0; j < st; j++) visited[j] = 0;
		eps(i); 
		printf("\n"); 
	}
}