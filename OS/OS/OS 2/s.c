#include<stdio.h>
int main()
{
        int h,a[50],i,n,sum,min,l;
        int mov[50],j;
        printf("Enter length of disk :: ");
        scanf("%d",&l);
        printf("Enter head position :: ");
        scanf("%d",&h);
        printf("Enter no position to read :: ");
        scanf("%d",&n);
        printf("\nEnter poitions :: ");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);

        //head movement print karayla
        printf("\ntotal movement  :: ");
        dispTotalHead(a,n,h,l);


        //total head moment sathi calculation
        min=a[0];
        for(i=0;i<n;i++)
                if(a[i]<min)
                        min=a[i];

        sum=(l-h)+(l-min);
        printf("\nTotal sum = %d",sum);
}
