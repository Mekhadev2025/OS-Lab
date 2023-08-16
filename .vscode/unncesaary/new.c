#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PERSONS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char ticket_class;
    int age;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Person;
 void fcfs_scheduling(Person persons[], int n) {
    persons[0].waiting_time = 0;
    persons[0].turnaround_time = persons[0].burst_time;

    for (int i = 1; i < n; i++) {
        if (persons[i].ticket_class != persons[i - 1].ticket_class) {
            persons[i].waiting_time = 0;
        } else if (persons[i].ticket_class == 'A' && persons[i - 1].ticket_class == 'A') {
            int nameComparison = strcmp(persons[i].name, persons[i - 1].name);
            if (nameComparison < 0) {
                persons[i].waiting_time = persons[i - 1].turnaround_time + persons[i - 1].burst_time - persons[i].arrival_time;
            } else {
                persons[i].waiting_time = persons[i - 1].waiting_time + persons[i - 1].burst_time - persons[i].arrival_time;
            }
        } else if (persons[i].ticket_class == 'B' && persons[i - 1].ticket_class == 'B') {
            if (persons[i].age < persons[i - 1].age) {
                persons[i].waiting_time = persons[i - 1].turnaround_time + persons[i - 1].burst_time - persons[i].arrival_time;
            } else {
                persons[i].waiting_time = persons[i - 1].waiting_time + persons[i - 1].burst_time - persons[i].arrival_time;
            }
        } else {
            persons[i].waiting_time = persons[i - 1].waiting_time + persons[i - 1].burst_time - persons[i].arrival_time;
        }

        if (persons[i].waiting_time < 0) {
            persons[i].waiting_time = 0;
        }

        persons[i].turnaround_time = persons[i].waiting_time + persons[i].burst_time;
    }
}

int main() {
    int n;
    printf("Enter the number of persons: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PERSONS) {
        printf("Invalid number of persons. Exiting...\n");
        return 1;
    }

    Person persons[MAX_PERSONS];
    float total_waiting_time = 0.0;
    float total_turnaround_time = 0.0;

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Person %d:\n", i + 1);
        printf("Name: ");
        getchar();  // Consume the newline character
        fgets(persons[i].name, MAX_NAME_LENGTH, stdin);
        persons[i].name[strlen(persons[i].name) - 1] = '\0';  // Remove newline character
        printf("Ticket Class (A/B): ");
        scanf(" %c", &persons[i].ticket_class);
        printf("Age: ");
        scanf("%d", &persons[i].age);
        printf("Arrival Time: ");
        scanf("%d", &persons[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &persons[i].burst_time);
    }

    printf("\nTicket verification result:\n");
    fcfs_scheduling(persons, n);

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_waiting_time += persons[i].waiting_time;
        total_turnaround_time += persons[i].turnaround_time;
    }

    float average_waiting_time = total_waiting_time / n;
    float average_turnaround_time = total_turnaround_time / n;

    printf("\n\nTicket Verification Table:\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("|   Name   | Ticket Class | Age | Arrival Time | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("|%-10s|      %c      | %3d |     %4d     |    %3d     |     %3d     |       %3d       |\n",
               persons[i].name, persons[i].ticket_class, persons[i].age, persons[i].arrival_time, persons[i].burst_time,
               persons[i].waiting_time, persons[i].turnaround_time);
    }
    printf("------------------------------------------------------------------------------------------------------------\n");

    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}
