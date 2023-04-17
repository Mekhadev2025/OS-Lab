#include <stdio.h>

void implementBestFit(int blockSize[], int blocks, int processSize[], int processes)
{
    // This will store the block id of the allocated block to a process
    int allocation[processes];
    
    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    for(int i = 0; i < processes; i++){
        allocation[i] = -1;
    }
 
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i=0; i < processes; i++)
    {
        
        int indexPlaced = -1;
        for (int j=0; j < blocks; j++) 
        { 
            if (blockSize[j] >= processSize[i])
            {
                // place it at the first block fit to accomodate process
                if (indexPlaced == -1)
                    indexPlaced = j;
                    
                // if any future block is better that is 
                // any future block with smaller size encountered
                // that can accomodate the given process
                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }
 
        // If we were successfully able to find block for the process
        if (indexPlaced != -1)
        {
            // allocate this block j to process p[i]
            allocation[i] = indexPlaced;
 
            // Reduce available memory for the block
            blockSize[indexPlaced] -= processSize[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
 
// Driver code
int main()
{
    int blocks, processes;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &blocks);
    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    int blockSize[blocks], processSize[processes];
    printf("\nEnter the sizes of the memory blocks:\n");
    for (int i = 0; i < blocks; i++)
    {
        printf("Block %d: ", i+1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter the sizes of the processes:\n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d: ", i+1);
        scanf("%d", &processSize[i]);
    }

    implementBestFit(blockSize, blocks, processSize, processes);

    return 0;
}

