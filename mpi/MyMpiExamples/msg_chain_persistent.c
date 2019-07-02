#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int i, myid, ntasks;
    int size = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status statuses[2];
    MPI_Request requests[2];

    double t0, t1;

    int source, destination;
    int count;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message buffers */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++) {
        message[i] = myid;
    }

    /* Set source and destination ranks */
    if (myid < ntasks - 1) {
        destination = myid + 1;
    } else {
        destination = 0; //MPI_PROC_NULL; null destination
    }
    if (myid > 0) {
        source = myid - 1;
    } else {
        source = ntasks-1; //MPI_PROC_NULL; null source
    }

    /* Start measuring the time spend in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();

    /* Send and receive messages as defined in exercise */
    /* TODO: Implement the communication using non-blocking
             sends and receives */

    /* int MPI_Isend(void *buf, count, MPI_Datatype datatype, dest, tag, MPI_Comm comm, MPI_Request *request);
       buf: initial address of send buffer (choice)
       count: number of elements in send buffer (integer)
       datatype: datatype of each send buffer element (handle)
       dest: rank of destination (integer)
       tag: message tag (integer)
       comm: communicator (handle)
       request: communication request (handle)

       int MPI_Irecv(void *buf,int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request);
       buf: initial address of receive buffer (choice)
       count: number of elements in receive buffer (integer)
       datatype: datatype of each receive buffer element (handle)
       source: rank of source (integer)- or MPI_ANY_SOURCE
       tag: message tag (integer)- or MPI_ANY_TAG
       comm: communicator (handle)
       request: communication request (handle)
    */
    
    //MPI_Isend(message, size, MPI_INT, destination, destination, MPI_COMM_WORLD, requests); //req. is a pointer so requests = &requests[0]
    //MPI_Irecv(receiveBuffer, size, MPI_INT, source, myid ,MPI_COMM_WORLD, &requests[1]);
    
    //MPI_Recv_init: Create a persistent request for a receive
    //MPI_Recv_init(void *buf,int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request);
    
    MPI_Recv_init(receiveBuffer, size, MPI_INT, source, myid ,MPI_COMM_WORLD, &requests[1]);   
    MPI_Send_init(message, size, MPI_INT, destination, destination, MPI_COMM_WORLD, requests); //req. is a pointer so requests = &requests[0]
    
    
    MPI_Start(&requests[1]);
    MPI_Start(&requests);
    
    printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n", myid,
           size, destination, destination);

    /* Blocking wait for messages */
    /* TODO: Add here the synchronization call so that you can
             be sure that all messages have been received */


   /*  MPI_Get_count(&statuses[0], MPI_INT, &count);
    printf("Receiver: %d. received elements: %d. Tag %d. Sender: %d.\n",
           myid, count, statuses[0].MPI_TAG, statuses[0].MPI_SOURCE); */

    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout); //clean the memory

    printf("Time elapsed in rank %2d: %6.3f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}

