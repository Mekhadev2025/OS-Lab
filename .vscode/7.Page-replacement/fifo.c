#include <stdio.h>
int main(){
      int pno,fno;
      printf("Enter number of pages and frames\n");
          scanf("%d%d",&pno,&fno);

  int ref_str[pno];
  int frames[fno];
  printf("Enter the reference string \n ");
  for(int i=0;i<pno;i++)
  {
      scanf("%d",&ref_str[i]);
  }
  

  for(int i=0;i<fno;i++)
  {
    frames[i]=-1;
  }


 int j=0;
 int miss=0,hit=0;
 int avail=0;


    printf("\nPage \t Frames \t\t Hit/Miss \n");
    for(int i=0;i<pno;i++)

     {
        printf("%d\t",ref_str[i]);
        avail=0;
        for(int k=0;k<fno;k++)

          {

        if(frames[k]==ref_str[i])
        {
            avail=1;
            hit++;
            break;
        }
          }
    for(int m=0;m<fno;m++)
     printf("%d  ",frames[m]);
    
    if(avail==1)

    {
        printf("\t H");

    }
  else{
    miss++;
    frames[j]=ref_str[i];
    j=(j+1)%fno;
    printf("\t F");
    

  }

 
printf("\n");

     }


printf("%d",miss);

return 0;

}




