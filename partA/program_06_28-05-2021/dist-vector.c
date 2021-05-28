#include<stdio.h>

struct node {
    unsigned cost[50];
    unsigned from[50];
}route[10];

int main(void) {
    int costmat[50][50];
    int i, j, k, n, count = 0;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n;j++) {
            scanf("%d",&costmat[i][j]);
            costmat[i][i] = 0;
            route[i].cost[j] = costmat[i][j];
            route[i].from[j] = j;
        }
    }
    do {
        count = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                for(k = 0; k < n; k++) {
                    if(route[i].cost[j] > costmat[i][k] + route[k].cost[j]) {
                        route[i].cost[j] = route[i].cost[k] + route[k].cost[j];
                        route[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    }while(count != 0);

    printf("\nRouting Cost for Each Router is as below\n");
    for(i = 0; i < n; i++) {
        printf("\nRouting Cost for Router %d is",i+1);
        printf("\nNode \t From \t Cost");
        for(j = 0; j < n; j++) {
            printf("\n%d \t %d \t %d ",j+1,route[i].from[j]+1,route[i].cost[j]);
        }
        printf("\n");
    }
    printf("\n\n");
}