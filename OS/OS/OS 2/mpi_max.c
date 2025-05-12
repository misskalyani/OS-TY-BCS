#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <limits.h>

#define N 1000

int main(int argc, char** argv)
{
    int rank, i, size, numbers[N], local_max = INT_MIN, global_max;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(rank);

    for (i = 0; i < N; i++) 
    {
        numbers[i] = rand() % 1000;  
        if (numbers[i] > local_max) 
        {
            local_max = numbers[i];
        }
    }

    printf("Process %d: Local maximum = %d\n", rank, local_max);

    MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) 
    {
        printf("Global maximum = %d\n", global_max);
    }

    MPI_Finalize();
}
