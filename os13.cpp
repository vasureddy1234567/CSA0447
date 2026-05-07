#include <stdio.h>

void firstFit(int blocks[], int m, int process[], int n) {
    int allocation[n];
    for(int i = 0; i < n; i++) allocation[i] = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(blocks[j] >= process[i]) {
                allocation[i] = j;
                blocks[j] -= process[i];
                break;
            }
        }
    }

    printf("\nFirst Fit:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d -> Block %d\n", i+1, allocation[i]+1);
    }
}

void bestFit(int blocks[], int m, int process[], int n) {
    int allocation[n];
    for(int i = 0; i < n; i++) allocation[i] = -1;

    for(int i = 0; i < n; i++) {
        int best = -1;
        for(int j = 0; j < m; j++) {
            if(blocks[j] >= process[i]) {
                if(best == -1 || blocks[j] < blocks[best])
                    best = j;
            }
        }
        if(best != -1) {
            allocation[i] = best;
            blocks[best] -= process[i];
        }
    }

    printf("\nBest Fit:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d -> Block %d\n", i+1, allocation[i]+1);
    }
}

void worstFit(int blocks[], int m, int process[], int n) {
    int allocation[n];
    for(int i = 0; i < n; i++) allocation[i] = -1;

    for(int i = 0; i < n; i++) {
        int worst = -1;
        for(int j = 0; j < m; j++) {
            if(blocks[j] >= process[i]) {
                if(worst == -1 || blocks[j] > blocks[worst])
                    worst = j;
            }
        }
        if(worst != -1) {
            allocation[i] = worst;
            blocks[worst] -= process[i];
        }
    }

    printf("\nWorst Fit:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d -> Block %d\n", i+1, allocation[i]+1);
    }
}

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int m = 5, n = 4;

    firstFit(blocks, m, process, n);

    int blocks2[] = {100, 500, 200, 300, 600};
    bestFit(blocks2, m, process, n);

    int blocks3[] = {100, 500, 200, 300, 600};
    worstFit(blocks3, m, process, n);

    return 0;
}
