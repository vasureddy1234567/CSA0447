#include <stdio.h>

int main() {

    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 417, 112, 426};

    int allocation[4];

    for(int i = 0; i < 4; i++)
        allocation[i] = -1;

    for(int i = 0; i < 4; i++) {

        int best = -1;

        for(int j = 0; j < 5; j++) {

            if(block[j] >= process[i]) {

                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if(best != -1) {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("Process\tBlock\n");

    for(int i = 0; i < 4; i++)
        printf("P%d\t%d\n", i+1, allocation[i]+1);

    return 0;
}
