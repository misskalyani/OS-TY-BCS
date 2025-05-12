#include<stdio.h>
#include<stdlib.h>
int main()
{
	int f[50],p,i,st,len,j,c,k,a;
	for(i=0;i<50;i++)
	    f[i]=0;
	printf("Enter How Many Blocks Are Already Allocated \t");
	scanf("%d",&p);
	printf("Enter already Allocated Blocks \n");
	for(i=0;i<p;i++)
	{
		scanf("%d",&a);
		f[a]=1;
	}
	x : printf("Enter Index Starting Block And Length ");
	//scanf("%d%d ",&st,&len);w
        scanf("%d%d",&st,&len); // ek extra space hoti maun error
	k=len;
	if(f[st]==0)
	{
		for(j=st;j<(st+k);j++)
		{
			if(f[j]==0)
			{
				f[j]=1;
				printf("%d------------->%d\n",j,f[j]);	
			}
			else
			{
				printf("%d Block Is Already Allocated\n",j);
				k++;
			}
		}
	}
	else
		printf("%d Starting Block is Already Allocated\n",st);

	printf("Do You Want to Enter More File (Yes -1/No -0)");
	scanf("%d",&c);
	if(c==1)
	    goto x;
	else
            exit(0);
}
