#include <stdio.h>

int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int frame[3]={-1,-1,-1};
    int i,j,k=0,fault=0,found;

    for(i=0;i<12;i++) {
        found=0;

        for(j=0;j<3;j++)
            if(frame[j]==pages[i])
                found=1;

        if(!found) {
            frame[k]=pages[i];
            k=(k+1)%3;
            fault++;
        }
    }

    printf("Page Faults=%d",fault);
    return 0;
}
