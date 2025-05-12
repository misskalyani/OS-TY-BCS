#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 100

int main(int argc,char** argv) 
{
    int rank, size,i,numbers[N],local_sum=0,global_sum=0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(rank);

    for (i=0;i<N;i++) 
    {
        numbers[i]=rand()%100;
        local_sum+=numbers[i];
    }

    MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

    if (rank == 0) 
    {
        printf("Sum of %d random numbers: %d\n",N*size,global_sum);
    }

    MPI_Finalize();
}
