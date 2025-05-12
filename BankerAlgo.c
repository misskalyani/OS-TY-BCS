#include<stdio.h>
#include<stdlib.h>
int allocation[20][20],max[20][20],availabel[20],need[20][20],safe[10],s=0;
int finish[20],work[20],cnt=0,flag=0,temp=0;
int p,r,i,j,ch,ind,req[20];

void check()
{
	temp=0;
	s=0;
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			need[i][j]=max[i][j]-allocation[i][j];
	printf("\n Need Table is : \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
			printf("%d\t",need[i][j]);
		printf("\n");	
	}

	for(i=0;i<p;i++)
		finish[i]=0;//false
	for(i=0;i<r;i++)
		work[i]=availabel[i];

	while(temp<2)
	{
		for(i=0;i<p;i++)
		{
			for(j=0;j<r;j++)
			{
				if(finish[i]==0 && need[i][j]<=work[j])
					flag=1;
				else
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				for(j=0;j<r;j++)
					work[j]+=allocation[i][j];
				finish[i]=1;
				safe[s++]=i;
			}
		}
		temp++;
	}

	flag=0;
	for(i=0;i<p;i++)
	{
		if(finish[i]==0)
		{
			flag=1;
			break;
		}
	}
	
	if(flag==1)
	{
		printf("\n System is in DeadLock State");
	}
	else
	{
		printf("\nSystem is in Safe state ");
		printf("\nSafe Sequence is :: ");
		for(i=0;i<p;i++)
			printf("P%d\t",safe[i]);
	}
}
int main()
{
	system("clear");
	printf("\n~~~~~~~~~~~~~~~~~~~~BANKER ALOGRITHM~~~~~~~~~~~~~~~~~~~~~");
	

	printf("\n\nEnter the no of resources and processes:");
	scanf("%d%d",&r,&p);
	

	printf("\nEnter the Allocation Table :\n");

	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&allocation[i][j]);
	
	
	printf("\nEnter the MAX Table :\n");

	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);
	
	
	printf("\nEnter the Vector Availabel  :\n");
	
	for(i=0;i<r;i++)
		scanf("%d",&availabel[i]);

	check();//safety algo

	
	printf("\nDo U Wnt to add new request:[0/1]");//Resource Request Algorithm
	scanf("%d",&ch);

	if(ch==0)
		exit(1);

	printf("\n Enter The Process number : ");
	scanf("%d",&ind);

	printf("\n Enter The Request : ");
	for(i=0;i<r;i++)
		scanf("%d",&req[i]);

	flag=0;
	
	for(i=0;i<r;i++)
		if(req[i]<=need[ind][i] && req[i]<=availabel[i])
			flag=1;
		else
			flag=0;
	
	if(flag==0)
	{
		printf("\n Request can not e satisfied...");
		exit(1);
	}

	for(i=0;i<r;i++)
	{
		allocation[ind][i]+=req[i];
		availabel[i]-=req[i];
	}

	
	check();//safety algo
	return 0;
}
/*


~~~~~~~~~~~~~~~~~~~~BANKER ALOGRITHM~~~~~~~~~~~~~~~~~~~~~

Enter the no of resources and processes:
3
5

Enter the Allocation Table :
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Enter the MAX Table :
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

Enter the Vector Availabel  :

3 3 2

 Need Table is :
7       4       3
1       2       2
6       0       0
0       1       1
4       3       1

System is in Safe state
Safe Sequence is :: P1  P3      P4      P0      P2
Do U Wnt to add new request:[0/1]1

 Enter The Process number : 1

 Enter The Request : 1 0 2

 Need Table is :
7       4       3
0       2       2
6       0       0
0       1       1
4       3       1

System is in Safe state
Safe Sequence is :: P1  P3      P4      P0      P2
--------------------------------

*/
