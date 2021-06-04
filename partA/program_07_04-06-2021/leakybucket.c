#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

int min(int x, int y) {
    return (x>y)?y:x;
}

int main() {
    int oprate, drop = 0, cap, x, count = 0, inp[10] = {0}, i = 0, numsecs, ch;
    printf("Bucket Size : ");
    scanf("%d",&cap);
    printf("Output Rate :");
    scanf("%d",&oprate);

    do {
        printf("\nEnter packet which arrives at second %d: ", i+1);
        scanf("%d", &inp[i]);
        if(inp[i] > cap) {
            printf("Bucket Overflowed\n");
            printf("Packet Discarded\n");
            exit(0);
        }
        i++;
        printf("Continue?(1) or Exit?(0): ");
        scanf("%d", &ch);
    }while(ch);

    numsecs=i;
    printf("\nSnd\tRcvd\tSent\tDropped\t Remaining\n");
    for(i = 0; count || i < numsecs; i++) {
        printf("%d",i+1);
        printf("\t%d",inp[i]);
        printf("\t%d", min((inp[i]+count),oprate));
        if((x = inp[i] + count - oprate) > 0) {
            if(x > cap) {
                count=cap;
                drop=x-cap;
            }
            else {
                count=x;
                drop=0;
            }
        }
        else {
            drop=0;
            count=0;
        }
        printf("\t%d\t %d\n", drop, count);
    }
    return 0;
}
