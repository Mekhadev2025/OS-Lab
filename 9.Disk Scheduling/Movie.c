#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, head, size, totalSwitchingTime = 0;
    
    printf("Enter the number of movies: ");
    scanf("%d", &n);
    
    int movieLengths[300];
    
    printf("Enter the movie lengths (in minutes):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &movieLengths[i]);
    }
    
    printf("Enter the current movie position: ");
    scanf("%d", &head);

    printf("Enter the total time (disk size) available: ");
    scanf("%d", &size);

    int sortedMovieLengths[300];
    for (int i = 0; i < n; i++) {
        sortedMovieLengths[i] = movieLengths[i];
    }

    // Sorting the movie lengths
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (sortedMovieLengths[j] > sortedMovieLengths[j + 1]) {
                int temp = sortedMovieLengths[j];
                sortedMovieLengths[j] = sortedMovieLengths[j + 1];
                sortedMovieLengths[j + 1] = temp;
            }
        }
    }

    int index;
    // Finding index of head
    for (int i = 0; i < n; i++) {
        if (sortedMovieLengths[i] == movieLengths[head]) {
            index = i;
            break;
        }
    }

    for (int k = index; k >= 0; k--) {
        totalSwitchingTime += movieLengths[head] - sortedMovieLengths[k];
        head = (head - 1 + n) % n;
    }

    for (int k = n - 1; k > index; k--) {
        totalSwitchingTime += movieLengths[head] - sortedMovieLengths[k];
        head = (head - 1 + n) % n;
    }

    printf("Optimal movie watching order:\n");
    for (int i = 0; i < n; i++) {
        printf("Movie %d (%d minutes)\n", (head + i) % n, movieLengths[(head + i) % n]);
    }

    printf("Total switching time: %d minutes\n", totalSwitchingTime);

    return 0;
}
