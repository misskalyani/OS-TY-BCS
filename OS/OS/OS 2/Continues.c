#include<stdio.h>
#include<stdlib.h>
int main()
{
        int f[50],st,len,i,c;

        for(i=0;i<50;i++)
                f[i]=0;

        printf("\nEnter start and length of pre allocated Blocks :: ");
        scanf("%d%d",&st,&len);

        for(i=st;i<(st+len);i++)
        {
                f[i]=1;
                printf("\n%d ----------------> %d",i,f[i]);
        }

        x: printf("\n\nEnter Start and Length of New File :: ");
        scanf("%d%d",&st,&len);

        for(i=st;i<(st+len);i++)
        {
                if(f[i]==1)
                {
                        printf("\nThe Blocks Are Not Continous...........");
                        goto y;
                }
        }

        for(i=st;i<(st+len);i++)
        {
                f[i]=1;
                printf("\n%d ----------------> %d",i,f[i]);
        }

        y: printf("\n\nDo you want to add more files [Yes:1/No:0]  :: ");
        scanf("%d",&c);

        if(c==1)
                goto x;
        else
                exit(0);
        
}
