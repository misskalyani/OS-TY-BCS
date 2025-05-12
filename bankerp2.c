#include<stdio.h>
int av[20][20],al[20][20],mx[20][20],p,r,ne[20][20],i,j,c,need[20][20];
void accAvailable()
{
	printf("\nEnter Avilable\n ");
	for(i=0;i<r;i++)
	scanf("%d",&av[i]);
}
void dispAvailable()
{
	printf("\n Avilable \n");
	for(i=0;i<r;i++)
	printf("%d",av[i]);
}
void dispmax()
{
	printf("\nAllocation \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
		printf("%d \t",al[i][j]);
		}
		printf("\n ");
	}
	printf("\nMax \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
		printf("%d \t",mx[i][j]);
		}
		printf("\n ");
	}
}
void dispneed()
{
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=mx[i][j]-al[i][j];
		}
	
	}
	printf("\nneed \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
		printf("%d \t",need[i][j]);
		}
		printf("\n ");
	}
}
int main()
{

	printf("Enter No Of process ");
	scanf("%d",&p);
	printf("Enter No Of resource ");
	scanf("%d",&r);
	printf("Enter Allocation ");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
	scanf("%d",&al[i][j]);
	}
	printf("Enter Max ");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
	scanf("%d",&mx[i][j]);
	}
	do{
		
	printf("Enter choice \n");
	scanf("%d",&c);
		switch(c)
		{
			case 1:accAvailable();
					break;
			case 2:	dispmax();
					break;
			case 3:	dispneed();
					break;
			case 4:	dispAvailable();
					break;			
		}
	}while(c<=5);
}
