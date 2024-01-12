#include "stdio.h"
#include "stdlib.h"
#include "mpi.h"


double All_reduce_performance(int max_iter) {
    int count = 0;
    double t1, t2;
    double all_reduce_time_cost = 0.0;
    double global, local;
    for (count = 0; count < max_iter; count++){
        local = count;
        t1 = MPI_Wtime();
        MPI_Allreduce(&local, &global, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
        t2 = MPI_Wtime();
        all_reduce_time_cost += t2 - t1;
    }
    return all_reduce_time_cost;
}

int main(int argc, char* argv[]) {
    int rank, size;
    double t1, t2;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int max_iter = 100;

    double t_allreduce;

    t1 = MPI_Wtime();
    t_allreduce = All_reduce_performance(max_iter);
    t2 = MPI_Wtime();

    if (rank == 0) printf("MPI_Allreduce %d times took %.3f ms, in which MPI_Allreduce took %.3f ms\n",
                            max_iter, (t2-t1)*1e3, t_allreduce*1e3);
    
    MPI_Finalize();
    return 0;
}