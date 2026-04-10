#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if(pid == 0) {
        printf("\nChild Process ID: %d\n", getpid());
        sort(arr, n);

        printf("Sorted by Child: ");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else {
        wait(NULL);
        printf("\nParent Process ID: %d\n", getpid());
        sort(arr, n);

        printf("Sorted by Parent: ");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}
