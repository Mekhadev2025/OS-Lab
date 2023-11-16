#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n;
  int head;
  printf("Enter the request queue size:  ");
  scanf("%d", &n);
  printf("Enter the request queue: ");
  int rq[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &rq[i]);
  }
  printf("Enter the current head position: ");
  scanf("%d", &head);

  int totalMovement = 0;
  printf("Seek Squence : \n");
  for (int i = 0; i < n; i++)
  {
    totalMovement += abs(head - rq[i]);
    head = rq[i];
    printf("%d\n", head);
  }
  printf("Total head movement /Seek Sequence is %d\n", totalMovement);
}

// {176, 79, 34, 60, 92, 11, 41, 114}