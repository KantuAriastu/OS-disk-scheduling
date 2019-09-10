/* disk scheduling dengan FCFS */
/* Ngakan Putu Ariastu, 10 Desember 2017 */

#include <stdio.h>
#include <stdlib.h>


/* create datatype to store disk data */
typedef struct disk {
	int request; //address requested
	int traverse;//range to traverse to the address
}disk;


int main ()
{
	int i,j,k;
	disk diske[30];
	int max_track;
	int n_req;
	int head;
	float ave_seek=0.0;
	
	
	/* read max  track of the disk */
	printf("input max track : ");
	scanf("%d",&max_track);
	printf("\n");
	
	/* read max data to be processed */
	printf("input number of request : ");
	scanf("%d",&n_req);
	printf("\n");
	
	/*read disk request */
	printf("input request queue: ");
	for (i=0;i<n_req;i++)
	{
		scanf("%d",&diske[i].request);
	}
	
	/* read the current head */
	printf("input start track : ");
	scanf("%d",&head);
	printf("\n");
	
	printf ("-----------------------------------\n");
	/*start fifo process */
	printf("start head : %d\n",head);
	
	/* calclulate range to each other */
	for (i=0;i< n_req; i++)
	{	
		diske[i].traverse = abs(head-diske[i].request);
		head = diske[i].request	;
	}
	
	/* print all the track */
	printf("request \t traversed \n");
	for (i=0;i<n_req;i++)
	{
		printf("%d \t %d\n",diske[i].request,diske[i].traverse);
		ave_seek += (float)(diske[i].traverse);
	}
	printf("\n average seek time : %f", ave_seek/(float)n_req);// print average seek time

	
	return 0;
}
