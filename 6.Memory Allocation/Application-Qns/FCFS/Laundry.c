// Imagine you live in an apartment building with a shared laundry room. 
// The laundry room has multiple washing machines, and residents need to schedule their laundry cycles.
//  Each washing machine has a number corresponding to its position, and residents submit laundry requests for specific machines.

// Problem:
//  Develop a program using the SCAN algorithm to efficiently schedule residents' laundry requests for the washing machines, minimizing 
//  the time it takes to complete all laundry cycles.





 void scan(int head, int machines[], int num_machines) {
    int direction = 1; // 1 for moving towards higher machine numbers, -1 for lower
    int current_position = head;
    
    printf("Scheduling order for laundry:\n");
    
    while (1) {
        int found = 0;
        
        for (int i = 0; i < num_machines; i++) {
            if (machines[i] == current_position) {
                printf("Use machine %d\n", current_position);
                machines[i] = -1; // Mark the machine as used
                found = 1;
                break;
            }
        }
        
        if (current_position == 1 || current_position == num_machines) {
            direction = -direction; // Change direction at the end points
        }
        
        if (direction == 1) {
            current_position++;
        } else {
            current_position--;
        }
        
        if (!found) {
            int all_used = 1;
            for (int i = 0; i < num_machines; i++) {
                if (machines[i] != -1) {
                    all_used = 0;
                    break;
                }
            }
            if (all_used) {
                printf("\nAll laundry cycles completed.\n");
                break;
            }
        }
    }
}
