#include <stdio.h>

int main() {
    int pages[]={7,0,1,2,0,3,0,4};
    int frame[3]={-1,-1,-1};
    int recent[3]={0};
    int fault=0,time=0;

    for(int i=0;i<8;i++) {
        int found=0;

        for(int j=0;j<3;j++)
            if(frame[j]==pages[i]) {
                recent[j]=++time;
                found=1;
            }

        if(!found) {
            int pos=0;

            for(int j=1;j<3;j++)
                if(recent[j]<recent[pos])
                    pos=j;

            frame[pos]=pages[i];
            recent[pos]=++time;
            fault++;
        }
    }

    printf("Page Faults=%d",fault);
    return 0;
}
