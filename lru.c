#include <stdio.h>

int main() {
    int ref[25], frames[10], usedTime[10], flag[25];
    int n, f, i, j, k, pageFaults = 0, timer = 1;

    // Input reference string length
    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    // Input reference string
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &ref[i]);
        flag[i] = 0;
    }

    // Input number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize frames as empty
    for (i = 0; i < f; i++) {
        frames[i] = -1;
        usedTime[i] = 0;
    }

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < n; i++) {

        // Check if page already exists in frames
        for (j = 0; j < f; j++) {
            if (frames[j] == ref[i]) {
                flag[i] = 1;           // page found
                usedTime[j] = timer++; // update usage time
                break;
            }
        }

        // Page not found → Page Fault
        if (flag[i] == 0) {

            // If there is still empty space
            int placed = 0;
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    frames[j] = ref[i];
                    usedTime[j] = timer++;
                    pageFaults++;
                    placed = 1;
                    break;
                }
            }

            // If no empty frame → replace LRU
            if (!placed) {
                int lruIndex = 0;

                // Find least recently used (smallest usedTime)
                for (j = 1; j < f; j++) {
                    if (usedTime[j] < usedTime[lruIndex])
                        lruIndex = j;
                }

                // Replace LRU page
                frames[lruIndex] = ref[i];
                usedTime[lruIndex] = timer++;
                pageFaults++;
            }
        }

        // Print current frame contents
        for (k = 0; k < f; k++)
            printf("%d ", frames[k]);

        if (flag[i] == 0)
            printf("\tPF No. %d", pageFaults);

        printf("\n");
    }

    printf("\nThe number of page faults using LRU = %d\n", pageFaults);

    return 0;
}
