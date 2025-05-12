#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int h,a[20],min,m,i,j,k,n,sum=0,visited[20]={0};
    printf("Enter head position :: ");
    scanf("%d",&h);
    printf("Enter no of positions to read :: ");
    scanf("%d",&n);
    printf("\nEnter positions :: ");
    for (i=0;i<n;i++) 
        scanf("%d", &a[i]);
    for (i=0;i<n;i++) 
    {
        min=9999; k=0;
        for (j=0;j<n;j++) 
        {
            if (!visited[j]) 
            {
                m=abs(h-a[j]); 
                if (m<min) 
                {
                    min=m;
                    k=j;
                }
                
            }
        }
        sum+=min;
        h=a[k];
        visited[k]=1;
   
    }
    printf("\n\nTotal sum ==> %d\n",sum);
}
