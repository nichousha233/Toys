#include "stdio.h"
#include <stdlib.h>
#include "mpi.h"
#include "omp.h"
#include <unistd.h>

#define NUM_THREADS 8

int main(int argc, char* argv[]) {
    int rank, size, thread_id, nthreads;
    char host_name[128];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    #pragma omp parallel num_threads(NUM_THREADS) private(thread_id, nthreads, host_name)
    {
        thread_id = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        int temp= gethostname(host_name, sizeof(host_name));
        if(temp==-1)
        {
            perror("gethostname");
            exit(1);
        }
        printf("Hello world from host: %s, rank = %d in size = %d, thread_id = %d in nthreads = %d\n", host_name, rank, size, thread_id, nthreads);
    }
    MPI_Finalize();
    return 0;
}