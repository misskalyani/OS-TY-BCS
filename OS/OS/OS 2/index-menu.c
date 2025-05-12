#include<stdio.h>
#include<stdlib.h>

int f[50], indexBlock[50], fileCount = 0;

void showBitVector()
{
    int i,k=0;
    printf("\nBit Vector:\n");
    for (i=0;i<50;i++)
    {
        printf("%d ",f[i]);
        k++;
        if(k%5==0)
        printf("\n");
    }
        printf("\n");
}

void showDirectory()
{
    int i;
    if (fileCount == 0)
    {
        printf("\nNo Files Allocated!\n");
        return;
    }

    printf("\nDirectory:\n");
    printf("Index Block -> Data Blocks\n");
    for (i=0;i<fileCount;i++)
    {
        printf("%d -> %d\n", indexBlock[0], indexBlock[i + 1]);
    }
}

void deleteFile()
{
    if (fileCount == 0)
    {
        printf("\nNo Files to Delete!\n");
        return;
    }

    int i;
    printf("\nDeleting file at Index Block: %d\n", indexBlock[0]);

    for (i=0;i<fileCount;i++)
    {
        f[indexBlock[i + 1]] = 0;
    }

    f[indexBlock[0]] = 0;
    fileCount = 0;
    printf("File Deleted Successfully!\n");
}

void createFile()
{
    int i, n, count = 0, ind;

    printf("Enter the Index Block: ");
    scanf("%d", &ind);

    if (f[ind] != 0)
    {
        printf("Index Block %d is already allocated!\n", ind);
        return;
    }

    printf("Enter the number of blocks needed for the file: ");
    scanf("%d", &n);

    printf("Enter the block numbers:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d", &indexBlock[i + 1]);
        if (f[indexBlock[i + 1]] == 0)
            count++;
    }

    if (count == n)
    {
        f[ind] = 1;
        indexBlock[0] = ind;
        for (i=0;i<n;i++)
        {
            f[indexBlock[i + 1]] = 1;
        }

        fileCount = n;
        printf("File Allocated Successfully!\n");

        printf("File Indexed:\n");
        for (i=0;i<n;i++)
        {
            printf("%d ---> %d\n", ind, indexBlock[i + 1]);
        }
    }
    else
    {
        printf("Some blocks are already allocated. Try again!\n");
    }
}

int main()
{
    int i, choice;

    for (i=0;i<50;i++)
        f[i] = 0; 

    while (1)
    {
        printf("1. Create File\n");
        printf("2. Show Bit Vector\n");
        printf("3. Show Directory\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: createFile(); break;
            case 2: showBitVector(); break;
            case 3: showDirectory(); break;
            case 4: deleteFile(); break;
            case 5: exit(0);
            default: printf("Invalid Choice! Try Again.\n");
        }
    }
}
