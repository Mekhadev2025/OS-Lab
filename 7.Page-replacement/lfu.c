#include <stdio.h>

int main()
{
  int pno, fno;

  printf("Enter number of pages and frames\n");
  scanf("%d%d", &pno, &fno);

  int count[fno];
  int ref_str[pno];
  int frames[fno];
  printf("Enter the reference string \n ");
  for (int i = 0; i < pno; i++)
  {
    scanf("%d", &ref_str[i]);
  }

  for (int i = 0; i < fno; i++)
  {
    frames[i] = -1;
    count[i] = 0;
  }
  int avail;
  int miss = 0, hit = 0;

  printf("\nPage \t Frames \t\t Hit/Miss \n");
  for (int i = 0; i < pno; i++)
  {
    printf("%d\t", ref_str[i]);
    avail = 0;
    for (int j = 0; j < fno; j++)
    {
      if (frames[j] == ref_str[i])
      {
        avail = 1;
        hit++;
        count[j]++;
        break;
      }
    }

    for (int k = 0; k < fno; k++)
    {
      printf("%d ", frames[k]);
    }

    if (avail == 0)
    {
      int min = count[0];
      int index = 0;

      for (int k = 1; k < fno; k++)
      {
        if (count[k] < min)
        {
          min = count[k];
          index = k;
        }
      }
      frames[min] = ref_str[i];
      count[min] = 1;
      miss++;
      printf("\t\t F");
    }
    else
    {
      printf("\t\t H");
    }

    printf("\n");
  }
  printf("\n%d", miss);

  return 0;
}