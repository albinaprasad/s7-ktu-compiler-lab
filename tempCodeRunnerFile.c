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