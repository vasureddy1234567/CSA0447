#include <stdio.h>

int main() {
    int n, i, time = 0, remain;
    int burst[20], rem_bt[20], waiting[20], turnaround[20];
    int quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
        rem_bt[i] = burst[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                if(rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    waiting[i] = time - burst[i];
                    turnaround[i] = time;
                    rem_bt[i] = 0;
                    remain--;
                }
            }
        }
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, burst[i], waiting[i], turnaround[i]);
    }

    return 0;
}
