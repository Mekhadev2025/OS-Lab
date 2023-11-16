// fcfs
#include <stdio.h>
int main()
{
    typedef struct
    {
        int pid;
        int at;
        int wt;
        int bt;
        int ct;
        int tat;
    } process;
    int n;
    printf("Enter the number of processes");
    scanf("%d", &n);
    process a[n];

    printf("Enter the arrival and burst time of each process:");
    for (int i = 0; i < n; i++)
    {
        a[i].pid = i + 1;
        scanf("%d %d", &a[i].at, &a[i].bt);
    }
}