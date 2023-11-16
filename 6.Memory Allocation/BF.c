
#include <stdio.h>
int main()
{

    int b, p;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &b);
    printf("Enter the number of processes: ");
    scanf("%d", &p);
 int blocks[b],processes[p];
    printf("\nEnter the sizes of the memory blocks:\n");
    for (int i = 0; i < b; i++)
    {
        printf("Block %d: ", i+1);
        scanf("%d", &blocks[i]);
    }

    printf("\nEnter the sizes of the processes:\n");
    for (int i = 0; i < p; i++)
    {
        printf("Process %d: ", i+1);
        scanf("%d", &processes[i]);
    }

   int allocation[p];


  for(int i=0;i<p;i++)
  {
    allocation[i]=-1;
  }
 int index;
   for(int i =0;i<p;i++)
   {

    index=-1;
    for(int j=0;j<b;j++)
    {

        if(blocks[j]>=processes[i])
        {
            if(index==-1)
            {
                index=j;
            }
            else{
                if(blocks[j]<blocks[index])
                {
                    index=j;
                }
            }
        }

    }
    if(index!=-1)
    {
        allocation[i]=index;
        blocks[index]-=processes[i];
    }
   }

   printf("Process number \t Process size \t Allocation\n");
   for(int i=0;i<p;i++)
   {
    printf("%d\t%d\t",i+1,processes[i]);
    if(allocation[i]!=-1)
    {
         printf("%d \n",allocation[i]+1);

    }
    else
     printf("Not allocated");
   }


}
