#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, min, index, total_seek = 0;
    int req[50], visited[50];

    printf("Enter number of requests (>=15): ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of servicing:\n");

    for(i = 0; i < n; i++) {
        min = 10000;

        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(head - req[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        printf("%d -> ", req[index]);
        total_seek += abs(head - req[index]);
        head = req[index];
        visited[index] = 1;
    }

    printf("\n\nTotal Seek Time = %d\n", total_seek);

    return 0;
}
