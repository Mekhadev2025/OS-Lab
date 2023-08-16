 #include <stdio.h>

int main() {
    int i, j, n, ref_str[50], frame[10], num_frames, k, m, fcount = 0;

    printf("Enter the number of pages:\n");
    scanf("%d", &n);

    printf("Enter the page numbers:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &ref_str[i]);

    printf("Enter the number of frames:\n");
    scanf("%d", &num_frames);

    for (i = 0; i < num_frames; i++)
        frame[i] = -1;

    j = 0;

    printf("Ref String\tPage Frames\tHit/Fault\n");

    for (i = 1; i <= n; i++)
     {
        printf("%d\t\t", ref_str[i]);
        int avail = 0;


        
        for (m = 0; m < num_frames; m++)
         {
            if (frame[m] == ref_str[i]) {
                avail = 1;
                break;
            }
        }

        for (k = 0; k < num_frames; k++)
            printf("%d\t", frame[k]);

        if (avail) {
            printf("H\n");
        } 
        else {
            frame[j] = ref_str[i];
            j = (j + 1) % num_frames;
            fcount++;
            printf("F\n");
        }
    }

    printf("Page Faults: %d\n", fcount);

    return 0;
}
