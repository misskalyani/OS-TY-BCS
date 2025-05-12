#include<stdio.h>
#include<stdlib.h>
void main()
{
	int f[50],index[50],i,n,st,len,j,c,k,ind,count=0;
	for(i=0;i<50;i++)
		f[i]=0;
	x:printf("Enter The Index Block : ");
	scanf("%d",&ind);
	
	if(f[ind]!=1)
	{
		printf("Enter Number of blocks needed and number of files for the index %d on the disk :\n",ind);
		scanf("%d",&n);	
	}
	else{
		printf("%d index is already allocated \n ",ind);
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
		for(i=0;i<n;i++)
			f[index[i]]=1;
		printf("\nAlloacted Indexed");
		for(i=0;i<n;i++)
			printf("\n%d------->%d : %d ",i,index[i],f[index[i]]);
	}
	else
	{
			printf("\nFile In The Index is already allocated \n");
		printf("\nEnter Another file Indexed ");
		goto y;
	}
}
