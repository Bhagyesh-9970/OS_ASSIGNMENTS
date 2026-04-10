#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if(pid > 0) {
        // Parent process
        printf("Parent Process (PID: %d) exiting...\n", getpid());
    }
    else {
        // Child process
        sleep(5);  // wait so parent exits first
        printf("Child Process (PID: %d)\n", getpid());
        printf("New Parent Process ID: %d\n", getppid());
    }

    return 0;
}
