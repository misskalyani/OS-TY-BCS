#include<stdio.h>
int main()
{
	int av[20],i,j,al[20][20],ma[20][20],ne[20][20],r,p;
	 printf("Enter number of resources:\n");
	 scanf("%d",&r);
	  printf("Enter number of proces:\n");
	 scanf("%d",&p);
	   printf("Enter max:\n");
	   for(i=0;i<p;i++)
	   {
	   	for(j=0;j<r;j++)
	   	{
		   
	 		scanf("%d",&ma[i][j]);
	 	}
	 }
	  
	   printf("Enter allocation:\n");
	   for(i=0;i<p;i++)
	   {
	   	for(j=0;j<r;j++)
	   	{
		   
	 		scanf("%d",&al[i][j]);
	 	}
	 }
	   printf("Enter Avaliable:\n");
	   for(i=0;i<r;i++)
	   {
	   
		   
	 		scanf("%d",&av[i]);
	 	
	 }
	    printf("disp Avaliable:\n");
	   for(i=0;i<r;i++)
	   {
	   
		   
	 		printf("%d",av[i]);
	 	
	 }
	    printf("disp need:\n");
	   for(i=0;i<p;i++)
	   {
	   	for(j=0;j<r;j++)
	   	{
		   ne[i][j]=ma[i][j]-al[i][j];
	 		
	 	}
	 
	 }
	  printf("disp need:\n");
	   for(i=0;i<p;i++)
	   {
	   	for(j=0;j<r;j++)
	   	{
		   
	 		printf("%d\t",ne[i][j]);
	 	}
	 	printf("\n");
	 }
}
