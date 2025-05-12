#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<mpi.h>
#define N 100
int main(int argc,char **argv)
{
	int i,size,rank,num[N],local_sum=0,global_sum=0,count=0;
	
	MPI_Init(&argc,&argv);
	MPI_COMM_rank(MPI_COMM_WORLD,&rank);
	MPI_COMM_size(MPI_COMM_WORLD,&size);
	
	srand(rank);

	while(count<N)
	{
		num[i]=rand%100;
		if(num[i]%2==1)
		{
			local_sum+=num[i];
			count++;
		}
	}
	MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0)
	{
		printf("sum of %d odd number is %d ",N*size,globl_sum);
	}
	MPI_Finalize();	
}