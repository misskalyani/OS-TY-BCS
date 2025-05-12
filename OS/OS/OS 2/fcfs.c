#include<stdio.h>
int main()
{
        int h,a[20],l,i,n,sum=0;

        printf("Enter length of disk :: ");
        scanf("%d",&l);
        printf("Enter head position :: ");
        scanf("%d",&a);
        printf("Enter no position to read :: ");
        scanf("%d",&n);

        printf("\nEnter poitions :: ");
        for(i=1;i<=n;i++)
                scanf("%d",&a[i]);

        for(i=0;i<n;i++)
        {
                if(a[i]<a[i+1])
                {                       
                        sum=sum+(a[i+1]-a[i]);
                        printf("\nHead Movement( %d - %d )",a[i+1],a[i]);
                        printf("= %d",sum);
                }
                else
                {
                        sum=sum+(a[i]-a[i+1]);
                        printf("\nHead Movement( %d - %d )",a[i],a[i+1]);
                       printf("%d",sum);
                }
        }

        printf("\nSum = %d",sum);


}
