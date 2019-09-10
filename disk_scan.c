/* disk scheduling dengan Scan */
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
	int head,last_head;
	float ave_seek=0.0;
	int direction = 1, hit;
	
	
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
		diske[i].done = 0;
	}
	
	/* read the current head */
	printf("input start track : ");
	scanf("%d",&head);
	printf("\n");
	
	printf ("-----------------------------------\n");
	/*start scan process */
	printf("start head : %d\n",head);
	printf("request \t traversed \n");
	
	hit = 0;
	last_head = head;  //save last head to count traversed range
	while (hit != n_req)
	{	
		/* check if current head hit one of the request */ 
		for (j=0;j<n_req;j++)
		{
			if ((head == diske[j].request) && (diske[j].done == 0))
			{	
				hit++;
				
				/* get the traversed length from last head */
				diske[j].traverse = abs(last_head-diske[j].request);
				last_head = diske[j].request; //save last head to count traversed range
				diske[j].done = 1 ; //set done status
				printf("%d \t %d\n",diske[j].request,diske[j].traverse);
				ave_seek += (float)(diske[j].traverse); //accumulate seek time
			}
		}	
		if (head >= max_track)
				direction *=-1; //change the head direction
			
		head += direction;
	}
	
	printf("\n average seek time : %f", ave_seek/(float)n_req);//print average seek time

	
	return 0;
}
