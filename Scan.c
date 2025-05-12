/*

Consider a disk queue with requests for I/O to blocks on cylinders 98, 183, 41, 122, 14, 124, 65, 
67. The SCAN scheduling algorithm is used. The head is initially at cylinder number 53 moving 
towards larger cylinder numbers on its servicing pass. The cylinders are numbered from 0 to 199. 
The total head movement (in number of cylinders) incurred while servicing these requests is 
_______.

GRAPH LABBOOK MADHI AHE .......

Total head movements incurred while servicing these requests
= (65 – 53) + (67 – 65) + (98 – 67) + (122 – 98) + (124 – 122) + (183 – 124) + (199 – 183) + 
(199 – 41) + (41 – 14)
= 12 + 2 + 31 + 24 + 2 + 59 + 16 + 158 + 27
= 331

*/
#<include<stdio.h>
int main()
{
	int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],temp1=0;
	float avg;
	printf("Enter The MAX range of disk \t");
	scanf("%d",&max);
	printf("Enter The INitial head Posistion \t");
	scanf("%d",&head);
	printf("Enter The Size of queue request \t");
	scanf("%d",&n);
	printf("Enter The queue of disk position to be read \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp>=head)
		{
			queue1[temp1]=temp;
			temp1++;
		}
		else
		{
			queue2[temp2]=temp;
			temp2++;
		}
		
	}
	for(i=0;i<temp1-1;i++)
	{
		for(j=i+1;j<temp1;j++)
		{
			if(queue[i]>queue1[j])
			{
				temp=queue1[i];
				queue[i]=queue1[j];
				queue[j]=temp;
			}
		}
	}
}
