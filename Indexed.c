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
	else
	{
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
/*
Enter The Index Block : 4
Enter Number of blocks needed and number of files for the index 4 on the disk :
7
10
44
32
56
78
83
89
File In The Index is already allocated
Enter Another file Indexed 5
23
45
12
28
17
16
Allocated
File Indexed
4----------->5 : 1
4----------->23 : 1
4----------->45 : 1
4----------->12 : 1
4----------->28 : 1
4----------->17 : 1
4----------->16 : 1
*/
