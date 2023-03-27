 #include<stdio.h>
#define MAX 100

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, i, j, t = 0, completed = 0, current_process = -1;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    struct Process p[MAX];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the arrival time, burst time and priority of process %d: ", i+1);
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].remaining_time = p[i].burst_time;
        p[i].pid = i+1;
    }
    while(completed < n) {
        // Find the highest priority process that has arrived
        int highest_priority = 1000000;
        for(i = 0; i < n; i++) {
            if(p[i].remaining_time > 0 && p[i].priority < highest_priority && p[i].arrival_time <= t) {
                highest_priority = p[i].priority;
                current_process = p[i].pid;
            }
        }
        if(current_process == -1) {
            t++;
            continue;
        }
        // Execute the process for 1 unit of time
        p[current_process-1].remaining_time--;
        if(p[current_process-1].remaining_time == 0) {
            completed++;
            // Calculate waiting and turnaround time for the completed process
            p[current_process-1].turnaround_time = t + 1 - p[current_process-1].arrival_time;
            p[current_process-1].waiting_time = p[current_process-1].turnaround_time - p[current_process-1].burst_time;
            // Update the average waiting and turnaround time
            avg_waiting_time += p[current_process-1].waiting_time;
            avg_turnaround_time += p[current_process-1].turnaround_time;
            current_process = -1;
        }
        // Increment time
        t++;
    }
    // Print the results
    printf("\nPID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time/n);
    return 0;
}

