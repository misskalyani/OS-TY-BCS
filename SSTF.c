/*
b) Consider a disk queue with requests for I/O to blocks on cylinders 98, 183, 41, 122, 14, 124, 
65, 67. The SSTF scheduling algorithm is used. The head is initially at cylinder number 53 
moving towards larger cylinder numbers on its servicing pass. The cylinders are numbered from 
0 to 199. The total head movement (in number of cylinders) incurred while servicing these 
requests is _______.

GRAPH LABBOOK MADHI AHE .......

Total head movements incurred while servicing these requests
= (65 – 53) + (67 – 65) + (67 – 41) + (41 – 14) + (98 – 14) + (122 – 98) + (124 – 122) + (183 –
124)
= 12 + 2 + 26 + 27 + 84 + 24 + 2 + 59
= 236

*/
#include<stdio.h>
struct disk
{
	int num;
	int flag;
};
int main()
{
	int i,j,sum=0,n,min,loc,x,y;
	struct disk d[20];
	int head;
	int ar[20],a[20];
	printf("Enter number Of Location \t");
	scanf("%d",&n);
	printf("Enter Position Of Head \t");
	scanf("%d",&head);
	printf("Enter elements of Disk queue \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i].num);
		d[i].flag=0;	
	}	
	for(i=0;i<n;i++)
	{
		x=0;min=0;loc=0;
		for(j=0;j<n;j++)
		{
			if(d[j].flag==0)
			{
				if(x==0)
				{
					ar[j]=head-d[j].num;
					if(ar[j]<0)
					{
						ar[j]=d[j].num-head;
					}
					min=ar[j];loc=j;x++;
				}
				else
				{
					ar[j]=head-d[j].num;
					if(ar[j]<0)
					{
						ar[j]=d[j].num-head;
					}
				}
				if(min>ar[j])
				{
					min=ar[j];
					loc=j;
				}
			}
		}
		d[loc].flag=1;
		a[i]=d[loc].num-head;
		if(a[i]<0)
		{
			a[i]=head-d[loc].num;
		}
		head=d[loc].num;
	}
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	printf("\n Movement Of Total Cylinder = %d ",sum);
	return 0;
}
/*
Enter number Of Location        8
Enter Position Of Head  53
Enter elements of Disk queue
98
183
41
122
14
124
65
67

 Movement Of Total Cylinder = 323
 */
