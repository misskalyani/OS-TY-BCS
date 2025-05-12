#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<mpi.h>
#define N 1000
int main(int argc,char **argv)
{
	int size,rank,i,num[N],local_sum=0,global_sum=0;
	float global_avg=0;
	MPI_Init(&argc,&argv);
	MPI_COMM_rank(MPI_COMM_WORLD,&rank);
	MPI_COMM_size(MPI_COMM_WORLD,&size);

	srand(rank);
	for(i=0;i<N;i++)
	{
		num[i]=rand%1000;
		local_sum+=num[i];
	}
	MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	
	if(rank==0)
	{
		global_avg=(float)global_sum/N*size;
		printf("Avg %d ",global_avg);
		printf("Sum %2.f ",global_sum);
	}
	
	MPI_Finalize();
}