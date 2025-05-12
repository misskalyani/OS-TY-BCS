#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<limits.h>
#define N 1000
int main(int argc,char **argv)
{
	int i,rank,size,local_max=INT_MIN,global_max,num[N];

	MPI_Int(&argc,&argv);

	MPI_COMM_rank(MPI_COMM_WORLD,&rank);

	MPI_COMM_size(MPI_COMM_WORLD,&size);

	srand(rank);

	for(i=0;i<N;i++)
	{
		num[i]=rand%1000;
		if(num[i]>local_max)
		{
			local_max=num[i];
		}
	}
	printf("Process %d \t Local_sum %d ",rank,local_sum);
	MPI_Reduce(&local_max,&global_max,1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);

	if(rank==0)
	{
		printf("Global_Sum=%d ",global_sum);
	}
	MPI_Finalize();
}