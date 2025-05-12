#include<stdio.h>
int main()
{
	int f[50],index[50],i,j,k,count,n,ind;
	for(i=0;i<50;i++)
		f[i]=0;
	x:printf("enter index block  ");
	scanf("%d",&ind);
	if(f[ind]!=1)
	{
		printf("Enter number of needed blocks ");
		scanf("%d",&n);
	}
	else
	{
		printf("%d file is already allocated ",ind);
		goto x;
	}
	y:count=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&index[i]);
		if(f[index[i]]==0)
		count++;
	}
	if(count==n)
	{
		for(j=0;j<n;j++)
			f[index[j]]=1;
		printf("Allocated Indexed \n");
		for(k=0;k<n;k++)
		{
			printf("%d----->%d : %d \n",ind,index[k],f[index[k]]);
		}
	}
	else
	{
		printf("File in th already allocated \n enter another index ");
		goto y;
	}
}
