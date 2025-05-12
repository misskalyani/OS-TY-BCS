#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 1000  // Size of the array
#define SEED 12345  // Random seed for reproducibility

int main(int argc, char *argv[]) {
    int rank, size;
    int local_sum = 0, total_sum = 0;
    int numbers[N], local_numbers[N];
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

    // Each process calculates its partial sum
    for (i = 0; i < N / size; i++) {
        local_sum += local_numbers[i];
    }

    // Reduce all partial sums to calculate the total sum on the root process
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Root process prints the final result
    if (rank == 0) {
        printf("The total sum of the randomly generated numbers is: %d\n", total_sum);
    }

    // Finalize MPI
    MPI_Finalize();

    return 0;
}

Explanation:
MPI_Init: Initializes the MPI environment.
MPI_Comm_rank: Gets the rank (ID) of the process in the communicator.
MPI_Comm_size: Gets the number of processes in the communicator.
MPI_Scatter: Distributes portions of the array (numbers[]) from the root process (rank 0) to all other processes.
Partial sum calculation: Each process computes the sum of its portion of the numbers.
MPI_Reduce: Reduces the partial sums from all processes to get the total sum, which is collected on the root process.
MPI_Finalize: Cleans up the MPI environment.

Compile the program:mpicc -o summpi summpi.c
Run the program mpirun -np 4 ./summpi