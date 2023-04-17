#include <stdio.h>

void implementFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    // This will store the block id of the allocated block to a process
    int allocate[processes];
    
    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    for(int i = 0; i < processes; i++)
    {
		allocate[i] = -1;
    }
	
    // take each process one by one and find
    // first block that can accomodate it
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++) { 
            if (blockSize[j] >= processSize[i])
            {
                // allocate block j to p[i] process
                allocate[i] = j;
 
                // Reduce size of block j as it has accomodated p[i]
                blockSize[j] -= processSize[i];
 
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int blocks, processes;
    printf("Enter the number of blocks: ");
    scanf("%d", &blocks);

    int blockSize[blocks];
    printf("Enter the size of each block:\n");
    for (int i = 0; i < blocks; i++)
    {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    int processSize[processes];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < processes; i++)
    {
        scanf("%d", &processSize[i]);
    }

    implementFirstFit(blockSize, blocks, processSize, processes);

    return 0;
}

