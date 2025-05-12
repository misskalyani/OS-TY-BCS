#include<stdio.h>

int n,m;
int available[10];
int max[10][10];
int alloc[10][10];
int need[10][10];
int finish[10];
int safeSeq[10];
int work[10];

void acceptAvailable()
{
    int i;
    printf("Enter available resources:\n");
    for (i=0;i<m;i++)
        scanf("%d",&available[i]);
}

void displayAllocationMax()
{
    int i,j;
    printf("\nAllocation Matrix:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
            printf("%d ",alloc[i][j]);
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
            printf("%d ",max[i][j]);
        printf("\n");
    }
}

void calculateNeed()
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

void displayNeed()
{
    int i,j;
    printf("\nNeed Matrix:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }
}

void displayAvailable()
{
    int i;
    printf("\nAvailable Resources:\n");
    for (i=0;i<m;i++)
        printf("%d ",available[i]);
    printf("\n");
}

int isSafe()
{
    int i,j,count = 0;
    for (i=0;i<m;i++)
        work[i] = available[i];
    for (i=0;i<n;i++)
        finish[i] = 0;
    while (count < n)
    {
        int found = 0;
        for (i=0;i<n;i++)
        {
            if (finish[i] == 0)
            {
                int flag = 1;
                for (j=0;j<m;j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    for (j=0;j<m;j++)
                        work[j] += alloc[i][j];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0)
            return 0;
    }

    printf("\nSystem is in a safe state\nSafe sequence: ");
    for (i=0;i<n;i++)
        printf("%d ",safeSeq[i]);
    printf("\n");
    return 1;
}

int main()
{
    int i,j,c;
    
    printf("Enter number of processes and resources: ");
    scanf("%d %d",&n,&m);

    printf("Enter allocation matrix:\n");
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter max matrix:\n");
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    calculateNeed();

    do
    {
        printf("1. Accept Available\n");
        printf("2. Display Allocation and Max\n");
        printf("3. Display Need Matrix\n");
        printf("4. Display Available\n");
        printf("5. Find Safe Sequence\n");
        printf("Enter your choice: ");
        scanf("%d",&c);

        switch(c)
        {
            case 1: acceptAvailable(); break;
            case 2: displayAllocationMax(); break;
            case 3: displayNeed(); break;
            case 4: displayAvailable(); break;
            case 5: 
                if (isSafe())
                    printf("System is in a safe state\n");
                else
                    printf("System is in an unsafe state\n");
                break;
            default: printf("Invalid choice!\n");
        }
    }while(c<6);
}


/*
┌──(ammu㉿kali)-[~/OS/OS 2]
└─$ ./a.out
Enter number of processes and resources: 5 4
Enter allocation matrix:
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
Enter max matrix:
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
1. Accept Available
2. Display Allocation and Max
3. Display Need Matrix
4. Display Available
5. Find Safe Sequence
Enter your choice: 1
Enter available resources:
1 5 2 0
1. Accept Available
2. Display Allocation and Max
3. Display Need Matrix
4. Display Available
5. Find Safe Sequence
Enter your choice: 2

Allocation Matrix:
0 0 1 2 
1 0 0 0 
1 3 5 4 
0 6 3 2 
0 0 1 4 

Max Matrix:
0 0 1 2 
1 7 5 0 
2 3 5 6 
0 6 5 2 
0 6 5 6 
1. Accept Available
2. Display Allocation and Max
3. Display Need Matrix
4. Display Available
5. Find Safe Sequence
Enter your choice: 3

Need Matrix:
0 0 0 0 
0 7 5 0 
1 0 0 2 
0 0 2 0 
0 6 4 2 
1. Accept Available
2. Display Allocation and Max
3. Display Need Matrix
4. Display Available
5. Find Safe Sequence
Enter your choice: 4

Available Resources:
1 5 2 0 
1. Accept Available
2. Display Allocation and Max
3. Display Need Matrix
4. Display Available
5. Find Safe Sequence
Enter your choice: 5

System is in a safe state
Safe sequence: 0 2 3 4 1 
System is in a safe state
1. Accept Available
2. Display Allocation and Max
3. Display Need Matrix
4. Display Available
5. Find Safe Sequence
Enter your choice: 7
Invalid choice!
              
*/
