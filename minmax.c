#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 1000  // Size of the array
#define SEED 12345  // Random seed for reproducibility

int main(int argc, char *argv[]) {
    int rank, size;
    int numbers[N], local_numbers[N];
    int local_min, local_max;
    int global_min, global_max;
    int i;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get rank of the process
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get number of processes

    // Randomly generate numbers on the root process
    if (rank == 0) {
        srand(SEED);  // Seed the random number generator
        for (i = 0; i < N; i++) {
            numbers[i] = rand() % 1000;  // Random number between 0 and 999
        }
    }

    // Scatter the numbers to all processes
    MPI_Scatter(numbers, N / size, MPI_INT, local_numbers, N / size, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process calculates its local min and max
    local_min = local_numbers[0];
    local_max = local_numbers[0];

    for (i = 1; i < N / size; i++) {
        if (local_numbers[i] < local_min) {
            local_min = local_numbers[i];
        }
        if (local_numbers[i] > local_max) {
            local_max = local_numbers[i];
        }
    }

    // Reduce the local min and max to find the global min and max
    MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    // Root process prints the final result
    if (rank == 0) {
        printf("The global minimum value is: %d\n", global_min);
        printf("The global maximum value is: %d\n", global_max);
    }

    // Finalize MPI
    MPI_Finalize();

    return 0;
}



