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
        
    // MPI_Comm_split Creates new communicators based on colors and keys
    // int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm)
    // INPUT PARAMETERS:
    // comm: communicator (handle)
    // color: control of subset assignment (nonnegative integer).
    // Processes with the same color are in the same new communicator
    // key: control of rank assignment (integer)
    // OUTPUT PARAMETERS
    // newcomm: new communicator (handle)

    // Get the rank and size in the original communicator
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int color;
    if (world_rank < 2){
       color = 1;
    } else {
        color = 2;
    }

    MPI_Comm subcomm; //Defining the communicator variable;
    MPI_Comm_split(MPI_COMM_WORLD, color,world_rank, &subcomm);

    /* Reduction operation applies a reduction operation op to sendbuf(different type of operation)
       over the sent of tasksand places the result in recvbuf on root 
       MPI_REduce(sendbuf, recvbuf, count: #of element in send buffer,datatype(MPI_INT), op(e.g.MPI_SUM; look at the table), 
       root: rank of root process: the first palce in communicator for putting the recvbuff, comm: communicator) */ 
    
    MPI_Reduce(sendbuf, recvbuf, NTASKS*2, MPI_INT, MPI_SUM, 0, subcomm);
    
    /* Print data that was received */
    /* TODO: add correct buffer */
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
