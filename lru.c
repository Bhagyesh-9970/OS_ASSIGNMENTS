#include <stdio.h>

int main() {
    int n, frames = 3, i, j, k, fault = 0;
    int ref[50], f[3], time[3], counter = 0, min, flag;

    printf("Enter number of pages (>=15): ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    // Initialize frames
    for(i = 0; i < frames; i++) {
        f[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        flag = 0;

        // Check if page already present
        for(j = 0; j < frames; j++) {
            if(f[j] == ref[i]) {
                counter++;
                time[j] = counter;
                flag = 1;
                break;
            }
        }

        // Page fault
        if(flag == 0) {
            min = 0;
            for(j = 1; j < frames; j++) {
                if(time[j] < time[min])
                    min = j;
            }

            f[min] = ref[i];
            counter++;
            time[min] = counter;
            fault++;
        }

        // Display frames
        printf("%d\t", ref[i]);
        for(j = 0; j < frames; j++)
            printf("%d ", f[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}
