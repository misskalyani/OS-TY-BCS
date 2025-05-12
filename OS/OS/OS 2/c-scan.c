#include<stdio.h>
void dispheadMOV(int ar[],int n,int head,int len)
{
        int i,j,temp;
        
        for (i=0;i<n-1;i++)
        {
                for (j=0;j<n-i-1;j++)
                if (ar[j]>ar[j+1])
                {
                        temp=ar[j];
                        ar[j]=ar[j+1];
                        ar[j+1]=temp;
                }
        }
        printf("\n%d -->",head);
        for (i=0;i<n;i++)
                if (ar[i]>head)
                printf("%d -->",ar[i]);

        printf("%d -->0 -->",len);       
        
        for (i=0;i<n;i++)
                if (ar[i]<head)
                printf("%d -->",ar[i]);
}

int main()
{
        int h,a[50],i,n,sum,min[50],l,max,j=0;
        printf("Enter length of disk :: ");
        scanf("%d",&l);
        printf("Enter head position :: ");
        scanf("%d",&h);
        printf("Enter no position to read :: ");
        scanf("%d",&n);
        printf("\nEnter poitions :: ");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);

        

        for(i=0;i<n;i++)
                if(a[i]<h)
                        min[j++]=a[i];
        
        max=min[0];
        for(i=0;i<j;i++)
                if(max<min[i])
                        max=min[j];

        dispheadMOV(a,n,h,l);

        sum=(l-h)+(l-0)+(max-0);
        printf("\nTotal sum = %d",sum);
}