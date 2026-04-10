#include <stdio.h>

int main() {
    int n, i, j;
    int at[10], bt[10], wt[10], tat[10], temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time:\n");
    for(i = 0; i < n; i++)
        scanf("%d%d", &at[i], &bt[i]);

    // Sort based on burst time
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);

    return 0;
}
