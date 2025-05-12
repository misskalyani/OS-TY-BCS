#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<mpi.h>
#define N 100
int main(int argc,char ** argv)
{
	int i,global_sum=0,local_sum=0,count=0,num[N],rank,size;

	MPI_Init(&argc,&argv);
	MPI_COMM_rank(MPI_COMM_WORLD,&rank);
	MPI_COMM_size(MPI_COMM_WORLD,&size);

	srand(rank);
	while(count<N)
	{
		num[i]=rand%100;
		if(num[i]%2==0)
		{
			local_sum+=num[i];
			count++;
		}
	}
	MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

	if(rank==0)
	{
		printf("sum of %d even number is %d ",N*size,global_sum);
	}
	MPI_Finalize();	
}