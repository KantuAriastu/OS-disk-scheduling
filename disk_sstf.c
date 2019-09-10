/* disk scheduling dengan SSTF */
/* Ngakan Putu Ariastu, 10 Desember 2017 */

#include <stdio.h>
#include <stdlib.h>

/* create datatype to store disk data */
typedef struct disk {
	int request; //address requested
	int traverse;//range to traverse to the address
	int done;//done status
}disk;


int main ()
{
	int i,j,k;
	disk diske[30];
	int max_track;
	int n_req;
	int head;
	float ave_seek=0.0;
	int target;
	
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
		diske[i].done = 0; //initialize done status
	}
	
	/* read the current head */
	printf("input start track : ");
	scanf("%d",&head);
	printf("\n");

	printf ("-----------------------------------\n");
	/* start sstf process */
	printf("start head : %d\n",head);
	printf("request \t traversed \n");
	
	target = 0;
	for (i=0;i< n_req; i++)
	{	
		/* search disk which have not been accessed */
		/* also closest with current head */
		for (j=0;j<n_req;j++)
		{	
			if ((diske[j].done == 0) && (abs(diske[target].request-head) > abs(diske[j].request-head)))
				target = j;
		}
		
		/*store range traversed to reach next target */
		diske[target].traverse = abs(head-diske[target].request);
		
		/* current head changed */
		head = diske[target].request;
		diske[target].done =1;	// mark the current disk is done accessed
		
		/* print the status of current process */
		printf("%d \t %d\n",diske[target].request,diske[target].traverse);
		ave_seek += (float)(diske[target].traverse);// accumulate traverse range 
		
		/* choose arbitrary disk which have not accesed as next target*/
		for (j=0; j< n_req; j++)
		{
			if (diske[j].done == 0)
			{	
				target = j;
				break;
			}
		}
		
		
	}
	
	printf("\n average seek time : %f", ave_seek/(float)n_req);// print average seek time

	
	return 0;
}
