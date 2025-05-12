#include<stdio.h>
int main()
{
	int i,j,f[50],k,len,st;
	int a,c,p;
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
	x: printf("\nEnter Index Starting Block And Length ");
	//scanf("%d%d ",&st,&len);w
        scanf("%d%d",&st,&len); // ek extra space hoti maun error
    k=len;
    if(f[st]==0)
    {
    	for(i=st;i<(st+len);i++)
    	{
    		if(f[i]==0)
    		{
    			f[i]=1;
    			printf("\n%d-------->%d",i,f[i]);
			}
			else
			{
				printf("\nBlocks Are Already allocated ");
				k++;
			}
		}
	}
		  	printf("\nDo You Want to Enter More File (Yes -1/No -0)");
	scanf("%d",&c);
	if(c==1)
	    goto x;
	else
            exit(0);
	    
}
