#include <stdio.h>

int main() {

    int block[5] = {100, 500, 200, 300, 600};
    int process[4] = {212, 417, 112, 426};

    int allocation[4];

    for(int i = 0; i < 4; i++)
        allocation[i] = -1;

    for(int i = 0; i < 4; i++) {

        int worst = -1;

        for(int j = 0; j < 5; j++) {

            if(block[j] >= process[i]) {

                if(worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }

        if(worst != -1) {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("Process\tBlock\n");

    for(int i = 0; i < 4; i++)
        printf("P%d\t%d\n", i+1, allocation[i]+1);

    return 0;
}
