
#include<stdio.h>
void main()
{
    int i,j,k,min,ref_str[25],frame[10],count[10],n,f,pf=0,next=0;

    printf("Enter the length of the reference string --");
    scanf("%d",&n);
    printf("Enter the reference string -- ");
    for(i=0;i<n;i++)
    {
       scanf("%d",&ref_str[i]);
    }
    printf("Enter the number of frames -- ");
    scanf("%d",&f);


    for(i=0;i<f;i++)
    {
        count[i]=0;
        frame[i]=-1;
    }


printf("\nThe Page Replacement process is -- \n");
int avail;

for(i=0;i<n;i++)
{
   printf("%d \t",ref_str[i]);
   avail=0;
    for(j=0;j<f;j++)
    {
        if(frame[j]==ref_str[i])
        {
            avail=1;
            count[j]=next;
            next++;
        }
    }
    if(avail==0)
    {
        if(i<f)
        {
            frame[i]=ref_str[i];
            count[i]=next;
            next++;
        }
        else
        {
            min=0;
            for(j=0;j<f;j++)
            {
            if(count[min] > count[j])
                min=j;
            }
            frame[min]=ref_str[i];
            count[min]=next;
            next++;
        }
        pf++;
    }

    for(j=0;j<f;j++)
    {
        printf("%d  ",frame[j]);
    }
  
    if(avail==0)
    printf("\t F");
    else{
         printf("\t H");
    }
    printf("\n");
}
printf("\nThe number of page faults using LRU are %d",pf);
}

// 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3 