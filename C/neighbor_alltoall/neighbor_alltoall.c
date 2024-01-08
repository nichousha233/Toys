#include "stdio.h"
#include "mpi.h"



int main(int argc, char* argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    MPI_Comm recv_comm;
    int dims[1] = {1}, periods[1] = {1};
    MPI_Cart_create(MPI_COMM_SELF, 1, dims, periods, 0, &recv_comm);
    // int x_out[4] = {1,2,3,4};
    // int x_in[4] = {0,0,0,0};
    int x_out[2] = {1,2};
    int x_in[2] = {0,0};

    // MPI_Neighbor_alltoall(x_out, 2, MPI_INT, x_in, 2, MPI_INT, recv_comm);
    MPI_Neighbor_alltoall(x_out, 1, MPI_INT, x_in, 1, MPI_INT, recv_comm);

    printf("x_in = [%d, %d]\n", x_in[0], x_in[1]);
    // printf("x_in = [%d, %d, %d, %d]\n", x_in[0], x_in[1], x_in[2], x_in[3]);

    MPI_Comm_free(&recv_comm);
    MPI_Finalize();
    return 0;
}