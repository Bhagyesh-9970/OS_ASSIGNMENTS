#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if(pid > 0) {
        // Parent process
        printf("Parent Process (PID: %d)\n", getpid());
        sleep(20);  // Parent sleeps → child becomes zombie
    }
    else {
        // Child process
        printf("Child Process (PID: %d) exiting...\n", getpid());
    }

    return 0;
}
