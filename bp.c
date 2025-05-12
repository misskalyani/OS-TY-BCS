#include<stdio.h>
int av[20],al[20][20],mx[20][20],p,r,ne[20][20],i,j,c,need[20][20],work[20],finis[20],safeseq[20];
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
int issafe()
{
	for(i=0;i<p;i++)
		work[i]=av[i];
	for(i=0;i<p;i++)
		finis[i]=0;	
	int count=0;
	while(count<p)
	{
		int found=0;
		for(i=0;i<p;i++)
		{
			if(finis[i]==0)
			{
				int f=1;
				for(j=0;j<r;j++)
				{
					if(need[i][j]>work[j])
					{
						f=0;
						break;
					}
				}
				if(f==0)
				{
					for(j=0;j<p;j++)
					{
						work[j]+=al[i][j];
						safeseq[count++]=i;
						finis[i]=1;
						found=1;
					}
				}
			}
		
		}
		if(found==0)
		return 0;
		
	}
	printf("\n Safe Sequence \n");
	for(i=0;i<p;i++)
		printf("%d\n",safeseq[i]);
	printf("\n ");
	return 1;	
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
			case 5:if(issafe())
						printf("\n Safe  ");		
					else
						printf("\n Non Safe ");
						break;
									
		}
	}while(c<=5);
}
