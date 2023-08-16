 #include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main() {
    int available[MAX_RESOURCES];
    int maximum[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};

    int numProcesses, numResources;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    // Input the available resources
    printf("Enter the available resources:\n");
    for (int i = 0; i < numResources; i++) {
        printf("Resource %d: ", i);
        scanf("%d", &available[i]);
    }

    // Input the maximum resource allocation for each process
    printf("Enter the maximum resource allocation for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d:\n", i);
        for (int j = 0; j < numResources; j++) {
            printf("Resource %d: ", j);
            scanf("%d", &maximum[i][j]);
        }
    }

    // Input the current resource allocation for each process
    printf("Enter the current resource allocation for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d:\n", i);
        for (int j = 0; j < numResources; j++) {
            printf("Resource %d: ", j);
            scanf("%d", &allocation[i][j]);

            // Calculate the need matrix
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    // Initialize work and finish arrays
    for (int i = 0; i < numResources; i++) {
        work[i] = available[i];
    }

    // Perform the Banker's Algorithm
    int count = 0;
    while (count < numProcesses) {
        int found = 0;
        for (int i = 0; i < numProcesses; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < numResources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == numResources) {
                    for (int k = 0; k < numResources; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (found == 0) {
            break;  // System is in an unsafe state
        }
    }

    // Check if the system is in a safe state
    if (count == numProcesses) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is in an unsafe state.\n");
    }

    return 0;
}
