#include <stdio.h>

int main() {
    int referenceString[25], frames[10];
    int refLen, numFrames;
    int i, j, k, pageFaults = 0;
    int nextToReplace = 0;

    // Input length of reference string
    printf("Enter the length of reference string: ");
    scanf("%d", &refLen);

    // Input reference string
    printf("Enter the reference string: ");
    for(i = 0; i < refLen; i++)
        scanf("%d", &referenceString[i]);

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &numFrames);

    // Initialize all frames to empty (-1)
    for(i = 0; i < numFrames; i++)
        frames[i] = -1;

    printf("\nThe Page Replacement Process is:\n");

    // FIFO Logic
    for(i = 0; i < refLen; i++) {

        // Check if page already exists in frames
        int found = 0;
        for(k = 0; k < numFrames; k++) {
            if(frames[k] == referenceString[i]) {
                found = 1;
                break;
            }
        }

        // If page not found => page fault
        if(found == 0) {
            frames[nextToReplace] = referenceString[i];
            nextToReplace = (nextToReplace + 1) % numFrames;
            pageFaults++;

            // Print frames after replacement
            for(j = 0; j < numFrames; j++)
                printf("%d ", frames[j]);

            printf("   PF No. %d", pageFaults);
            printf("\n");
        }
        else {
            // Print frames without page fault
            for(j = 0; j < numFrames; j++)
                printf("%d ", frames[j]);
            printf("\n");
        }
    }

    printf("\nThe number of Page Faults using FIFO = %d\n", pageFaults);

    return 0;
}
