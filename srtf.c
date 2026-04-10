#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0, min;
    int at[10], bt[10], rt[10], wt[10], tat[10], finish;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while(count != n) {
        min = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(min == -1 || rt[i] < rt[min])
                    min = i;
            }
        }

        if(min == -1) {
            time++;
            continue;
        }

        rt[min]--;
        time++;

        if(rt[min] == 0) {
            count++;
            finish = time;
            wt[min] = finish - bt[min] - at[min];
            tat[min] = wt[min] + bt[min];
        }
    }

    printf("\nProcess\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);

    return 0;
}
