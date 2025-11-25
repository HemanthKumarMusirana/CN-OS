#include <stdio.h>

int main(void) {
    int n, i, j;
    int bt[50];      // burst times
    int wt[50];      // waiting times
    int tat[50];     // turnaround times
    float avg_wt = 0.0f, avg_tat = 0.0f;

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    printf("Enter burst times for each process (P1 ... P%d):\n", n);
    for (i = 0; i < n; ++i) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        if (bt[i] < 0) bt[i] = 0;
    }

    // FCFS waiting times
    wt[0] = 0;                         // first process waits 0
    for (i = 1; i < n; ++i) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Turnaround times and sums for averages
    for (i = 0; i < n; ++i) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Print table
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; ++i) {
        printf("P%-3d\t%-5d\t%-5d\t%-5d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Print averages
    printf("\nAverage Waiting Time   = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time= %.2f\n", avg_tat / n);

    return 0;
}
