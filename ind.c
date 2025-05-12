#include<stdio.h>
int main()
{
	int f[50],index[20],i,j,n;
	int count=0,ind;
	for(i=0;i<50;i++)
		f[i]=0;
	x:printf("\nEnter Index ");
	scanf("%d",&ind);
	if(f[ind]!=1)
	{
		printf("\nIndex for %d files ",ind);
		scanf("%d",&n);
	}
	else
	{
			printf("\nIndex for %d already allocated ",ind);	
			goto x;
	}
	y:count=0;
	for(i=0;i<n;i++)
	{
			scanf("%d",&index[i]);
			if(f[index[i]]==0);
			count++;
	}
	if(count==n)
	{
		for(i=0;i<n;i++)
			f[index[i]]=1;
		printf("\nAllocated Index")	;
		for(i=0;i<n;i++)
			printf("\n%d--------> %d : %d",i,index[i],f[index[i]]);	
	}
	else
	{
		printf("\nIndex already allocated try ");
			goto y;
	}
}
