#include <stdio.h>

int main() {
    int p[20], bt[20], pr[20], wt[20], tat[20];
    int i, j, n, temp;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        p[i] = i + 1;

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", p[i]);
        scanf("%d", &bt[i]);
        printf("Enter Priority for Process %d: ", p[i]);
        scanf("%d", &pr[i]);
    }

    // Sorting according to Priority (lower number = higher priority)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(pr[i] > pr[j]) {

                // Swap priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Waiting Time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = 0;
        for(j = 0; j < i; j++)
            wt[i] += bt[j];

        avgwt += wt[i];
    }

    // Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgtat += tat[i];
    }

    // Output Table
    printf("\nProcess\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}
