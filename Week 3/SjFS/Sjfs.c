#include <stdio.h>
#define Max 100

struct process {
    int pid;                // process ID
    int arrival_time;       // arrival time of the process
    int burst_time;         // burst time of the process
    int remaining_time;     // remaining time to complete the process
    int waiting_time;       // waiting time of the process
    int turnaround_time;    // turnaround time of the process
};

int main()
{
    int n;
    printf("Enter the number of processes\n");
    scanf("%d",&n);

    struct process p[Max];
    printf("Enter the arrival time and burst time of each process\n");

    // read input for each process
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        scanf("%d %d",&p[i].arrival_time,&p[i].burst_time);
        p[i].remaining_time=p[i].burst_time;
    }

    int t=0;            // current time
    int completed =0;   // number of processes completed

    // run the scheduling algorithm until all processes are completed
    while(completed < n)
    {
        int shortest=-1;    // to store index of process with shortest remaining time

        // finding process with shortest remaining time
        for (int i=0;i<n;i++)
        {
            // check if process is ready to execute
            if (p[i].arrival_time <= t && p[i].remaining_time > 0)
            {
                // check if current process has shorter remaining time than shortest process so far
                if (shortest == -1 || p[i].remaining_time < p[shortest].remaining_time)
                {
                    shortest=i;
                }
            }
        }

        // if there are no process ready to execute
        if (shortest == -1)
        {
            t++;
            continue;   // preventing execution of the remaining codes
        }

        // execute the process with shortest remaining time
        p[shortest].remaining_time--;

        // if the process is completed
        if (p[shortest].remaining_time == 0)
        {
            completed++;

            // calculate waiting time and turnaround time
            p[shortest].turnaround_time=(t+1)-p[shortest].arrival_time;
            p[shortest].waiting_time=p[shortest].turnaround_time-p[shortest].burst_time;
        }

        t++;
    }

    float avg_wt=0;         // average waiting time
    float avg_tat=0;        // average turnaround time

    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");

    // print details of each process
    for (int i=0; i<n; i++) 
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].turnaround_time, p[i].waiting_time);
        
        // calculate total waiting time and turnaround time
        avg_wt += p[i].waiting_time;
        avg_tat += p[i].turnaround_time;
    }

    // calculate and print average waiting time and average turnaround time
    printf("Average waiting time: %.2f\n", avg_wt/n);
    printf("Average turnaround time: %.2f\n", avg_tat/n);

    return 0;
}

