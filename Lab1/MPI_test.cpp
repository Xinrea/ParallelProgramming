//Author: Xinrea
//Date: 2018/7/5
//basic sample of using MPI
//Use mpirun to run this program, use `-np` to set process number

#include <mpich/mpi.h>
#include <cstdio>

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Init(&argc,&argv);  //begin
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    printf("HelloWord from process %d of %d\n",rank,size);
    MPI_Finalize();
    return 0;
}
