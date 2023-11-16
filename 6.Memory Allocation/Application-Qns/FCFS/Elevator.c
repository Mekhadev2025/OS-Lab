// Develop a C program that simulates an elevator system using the FCFS disk scheduling algorithm.
// Assume the elevator starts at a certain floor and receives floor requests in the order they are pressed.
//  Calculate and display the total floor-to-floor head movement required to serve all the requests.

#include <stdio.h>

int main()
{
    int head;
    int n;
    printf("Enter the total floors to be visted:");
    scanf("%d", &n);
    int floors[n];
    printf("Enter the Fllor to be visted ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &floors[i]);
    }
    int head;
    printf("Enter the initial floor");
    scanf("%d", &head);

    int n = 5;
    int totalMov = 0;
    int initial = head;
    for (int i = 0; i < n; i++)
    {

        totalMov = totalMov + abs(floors[i] - initial);
        initial = floors[i];
    }
    printf("\nTotal Movement =%d", totalMov);
    return 0;
}