#include <stdio.h>

int main() {
    int pages[]={7,0,1,2,0,3,0,4};
    int frame[3]={-1,-1,-1};
    int fault=0;

    for(int i=0;i<8;i++) {
        int found=0;

        for(int j=0;j<3;j++)
            if(frame[j]==pages[i])
                found=1;

        if(!found) {
            frame[fault%3]=pages[i];
            fault++;
        }
    }

    printf("Page Faults=%d",fault);
    return 0;
}
