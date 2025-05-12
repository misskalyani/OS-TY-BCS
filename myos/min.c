#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<mpi.h>
#define N 1000
int main(int argc,char **argv)
{
	int i,size,rank,global_min,local_min=INT_MAX,num[N];
	MPI_Init(&argc,&argv);

	MPI_COMM_rank(MPI_COMM_WORLD,&rank);
	MPI_COMM_size(MPI_COMM_WORLD,&size);
	
	srand(rank);

	for(i=0;i<N;i++)
	{
		num[i]=rand%1000;
		if(num[i]<local_min)
			local_min=num[i];

	}
	printf("Process %d  local min %d ",rank,local_min);

	MPI_Reduce(&local_min,&global_min,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
	
	if(rank==0)
	{
		printf("global min = %d ",global_min);
	}

	MPI_Finalize();
	
}