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
	 	printf("Enter the number of blocks needed for the file: ");
   	 	scanf("%d", &n);
		
	}	
	else
	{
		printf("%d index is already allocated \n ",ind);
		goto x;
	}
	y:count=0;
	
   // printf("Enter the block numbers:\n");
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
		printf("Allocated\n");
		printf("File Indexed \n");
		for(k=0;k<n;k++)
			printf("%d----------->%d : %d \n",ind,index[k],f[index[k]]);
	}
	else
	{
		printf("File In The Index is already allocated \n");
		printf("Enter Another file Indexed ");
		goto y;
	}
}
