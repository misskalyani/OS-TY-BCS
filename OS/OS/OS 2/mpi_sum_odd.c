#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 100

int main(int argc,char** argv) 
{
    int rank,num,size,i,numbers[N],local_sum=0,global_sum=0,count=0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(rank);

    while(count < N) 
    {
        num=rand()%100;
        if(num%2!=0)
        {  
            numbers[count]=num;
            local_sum += num;
            count++;
        }
    }

    MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

    if (rank == 0) 
    {
        printf("Sum of %d random Odd numbers: %d\n",N*size,global_sum);
    }

    MPI_Finalize();
}
