#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <limits.h>

#define N 100

int main(int argc, char** argv)
{
    int rank,i,size,numbers[N],local_min = INT_MAX,global_min;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(rank);


    for (i=0;i<N;i++) 
    {
        numbers[i] = rand() % 1000;  
        if (numbers[i] < local_min) 
        {
            local_min = numbers[i];
        }
    }

    printf("Process %d: Local minimum = %d\n", rank, local_min);

    MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    if (rank == 0) 
    {
        printf("Global minimum = %d\n", global_min);
    }

    MPI_Finalize();
}
