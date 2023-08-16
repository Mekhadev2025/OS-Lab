#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){

    int n ;int head;int size;int arr[300];int p=0;
    int direction;
    printf("Enter the request queue size\n");
    scanf("%d",&n);
    int rq[300];
    printf("Enter the request queue :\n ");
    for(int i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }

       printf("Enter the current head position: ");
    scanf("%d",&head);

   printf("Enter the disk size ");
    scanf("%d",&size);

      printf("Enter the direction of traversal  [left:0 and right:1]");
      scanf("%d",&direction);
    
     int totalMovement=0;
    rq[n+2]=size-1;
    rq[n+1]=0;
    rq[n]=head;
    n=n+3;
    
       //sorting all
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(rq[j]>rq[j+1])
                {
                    int temp=rq[j];
                    rq[j]=rq[j+1];
                    rq[j+1]=temp;
                }
            }
        }
 
int index;
    //finding index of head 
    for(int i=0;i<n;i++)
    {
        if(rq[i]==head)
        {
            index=i;
            break;
        }
    }

//move    
if(direction==1)
{
    for(int i=index;i<n;i++,p++)
    {
        arr[p]=rq[i];
    }
    for(int i=0;i<index;i++,p++)
    {
        arr[p]=rq[i];
    }
}
else{
    for(int i=index;i>=0;i--,p++)
    {
        arr[p]=rq[i];
    }
    for(int i=n-1;i>index;i--,p++)
    {
        arr[p]=rq[i];
    }

} 

for(int i=0;i<p-1;i++)
{    
  
    totalMovement+=abs(arr[i]-arr[i+1]);
 printf("%d-%d =%d\n",arr[i],arr[i+1],totalMovement);
}


printf("\n\n\nTotal Movement:%d\n",totalMovement);
}


