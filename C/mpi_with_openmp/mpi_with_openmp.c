#include "stdio.h"
#include "mpi.h"
#include "omp.h"

#define NUM_THREADS 8

int main(int argc, char* argv[]) {
    int rank, size, thread_id, nthreads;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    #pragma omp parallel num_threads(NUM_THREADS) private(thread_id, nthreads)
    {
        thread_id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("Hello world for rank = %d in size = %d, thread_id = %d in nthreads = %d\n", rank, size, thread_id, nthreads);
    }
    MPI_Finalize();
    return 0;
}