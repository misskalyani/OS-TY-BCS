#include<stdio.h>

void dispTotalHead(int arr[],int n,int head)
{
    int greater[20],smaller[20],g=0,s=0,i;
    
    for (i=0;i<n;i++)
        if(arr[i]>head)
                (greater[g++]=arr[i]);
        else
                (smaller[s++]=arr[i]);
    
    for (i=0;i<g-1;i++)
        for (int j=0;j<g-i-1;j++)
            if (greater[j]>greater[j+1])
            {
                int temp=greater[j];
                greater[j]=greater[j+1];
                greater[j+1]=temp;
            }
    
    for (i=0;i<s-1;i++)
        for (int j=0;j<s-i-1;j++)
            if (smaller[j]<smaller[j+1])
            {
                int temp=smaller[j];
                smaller[j]=smaller[j+1];
                smaller[j+1]=temp;
            }
    
    printf("%d ",head);
    for (i=0;i<g;i++) printf("%d ",greater[i]);
    
    for (i=0;i<s;i++) printf("%d ",smaller[i]);
}
int main()
{
        int h,a[50],i,n,sum,min,max,l;
       // printf("Enter length of disk :: ");
      //  scanf("%d",&l);
        printf("Enter head position :: ");
        scanf("%d",&h);
        printf("Enter no position to read :: ");
        scanf("%d",&n);
        printf("\nEnter poitions :: ");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);

        min=a[0];
        for(i=0;i<n;i++)
                if(a[i]<min)
                        min=a[i];

        max=a[0];
        for(i=0;i<n;i++)
                if(a[i]>max)
                        max=a[i];

        sum=(max-h)+(max-min);
        printf("\ntotal movement  :: ");
        dispTotalHead(a,n,h);
        printf("\nTotal sum = %d",sum);
}