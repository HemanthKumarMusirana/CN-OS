#include <stdio.h>

int main() {
    int i, j, n, bu[20], wu[20], tat[20], c[20], t, max, temp = 0;
    float att = 0, aut = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bu[i]);
        c[i] = bu[i];   // original burst time copy
    }

    printf("Enter Time Slice: ");
    scanf("%d", &t);

    // Find max burst time
    max = bu[0];
    for(i = 1; i < n; i++)
        if(max < bu[i])
            max = bu[i];

    // Round Robin Logic
    while(1) {
        int done = 1;
        for(i = 0; i < n; i++) {
            if(bu[i] > 0) {
                done = 0;

                if(bu[i] >= t) {
                    temp += t;
                    bu[i] -= t;
                } else {
                    temp += bu[i];
                    bu[i] = 0;
                }

                tat[i] = temp;  // completion time (temp acts as timeline)
            }
        }
        if(done == 1)
            break;
    }

    // Calculate waiting & turnaround times
    for(i = 0; i < n; i++) {
        wu[i] = tat[i] - c[i];
        att += tat[i];
        aut += wu[i];
    }

    // Output section
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, c[i], wu[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", aut / n);
    printf("\nAverage Turnaround Time = %.2f\n", att / n);

    return 0;
}
