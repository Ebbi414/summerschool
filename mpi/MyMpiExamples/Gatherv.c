#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define NTASKS 4

void print_buffers(int *printbuffer, int *sendbuffer, int buffersize);
void init_buffers(int *sendbuffer, int *recvbuffer, int buffersize);


int main(int argc, char *argv[])
{
    int ntasks, rank;
    int sendbuf[2 * NTASKS], recvbuf[2 * NTASKS];
    int printbuf[2 * NTASKS * NTASKS];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (ntasks != NTASKS) {
        if (rank == 0) {
            fprintf(stderr, "Run this program with %i tasks.\n", NTASKS);
        }
        MPI_Abort(MPI_COMM_WORLD, -1);
    }

    /* Initialize message buffers */
    init_buffers(sendbuf, recvbuf, 2 * NTASKS);

    /* Print data that will be sent */
    print_buffers(printbuf, sendbuf, 2 * NTASKS);

    /* TODO: use a single collective communication call (and maybe prepare
     *       some parameters for the call) */
    /* Send (0,1,2,...,7) everywhere */
    /* MPI_Bcast(sendbuf, 2 * NTASKS, MPI_INT, 0, MPI_COMM_WORLD); */

    /* Scatter the elements from task 0 */
    /* MPI_Scatter(sendbuf, 2, MPI_INT, recvbuf, 2, MPI_INT, 0,
	        MPI_COMM_WORLD); */
    /* Gather varying size data to task 1 */
    
    /* MPI_Gatherv(sendbuf:data to be gathered; sendcount: number of elements pulled from each process; sendtype; recvbuf: receive buffer;
		 recvcounts: array of lenght ntasks, entry i specifies hom many to receive from that process; displs: array of lenght ntasks,
		 entry i specifies the displacement relative to resvbuf; recvtype; root: rank of receiving process; comm: communicator) */

    int offsets[NTASKS] = { 0, 1, 2, 4 };
    int counts[NTASKS] = { 1, 1, 2, 4 };

    MPI_Gatherv(sendbuf, counts[rank], MPI_INT, recvbuf, counts,
                offsets, MPI_INT, 1, MPI_COMM_WORLD);
              
    /* Print data that was received */
    /* TODO: add correct buffer */

    /* print_buffers(printbuf, sendbuf, 2 * NTASKS); */
    /* print_buffers(printbuf, recvbuf, 2 * NTASKS); */
    print_buffers(printbuf, recvbuf, 2 * NTASKS);

    MPI_Finalize();
    return 0;
}


void init_buffers(int *sendbuffer, int *recvbuffer, int buffersize)
{
    int rank, i;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    for (i = 0; i < buffersize; i++) {
        recvbuffer[i] = -1;
        sendbuffer[i] = i + buffersize * rank;
    }
}


void print_buffers(int *printbuffer, int *sendbuffer, int buffersize)
{
    int i, j, rank, ntasks;

    MPI_Gather(sendbuffer, buffersize, MPI_INT,
               printbuffer, buffersize, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

    if (rank == 0) {
        for (j = 0; j < ntasks; j++) {
            printf("Task %i:", j);
            for (i = 0; i < buffersize; i++) {
                printf(" %2i", printbuffer[i + buffersize * j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
