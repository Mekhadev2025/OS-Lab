#include <stdio.h>
#include <stdlib.h>
int main(){

int i,j,k,m;
int page[25],frame[25];
int n;//page-number
int f_no;//frame number

int fcount=0;

printf("Enter the number of pages");
scanf("%d",&n);


printf("Enter the page numbers");
for(i=0;i<n;i++)
{
    scanf("%d",&page[i]);

}
printf("Enter the number of frames");
scanf("%d",&f_no);


for( i=0;i<f_no;i++)
{
    frame[i]=-1;    //initailized alll frames to -1
}

j=0;//initializing pointer
//checking fifo
 printf("Ref String\tPage Frames\tHit/Fault\n");
for(i=0;i<n;i++)
{
     printf("%d\t\t",page[i]);
    int avail=0;
   
    for(k=0;k<f_no;k++)
    {
        if(frame[k]==page[i])
        {
            avail=1;
             break;

        }
    }

    
        for(int m=0;m<f_no;m++)
        {
           printf("%d \t ",frame[m]);
        }

        if(avail)
        {
            printf("H\n");

        }

        else{

            frame[j]=page[i];
            j=(j+1)%f_no;
            fcount++;
            printf("F\n");
        }
        
    }
  


printf("\n\nNumber of page faults %d \n",fcount);

return 0;
}

// 0 2 5 6 4 5 2 1 3 2 