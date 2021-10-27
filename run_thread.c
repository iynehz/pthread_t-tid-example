#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

#define gettid() ((pid_t)syscall(SYS_gettid))

void *printHello(void *threadid) {
    pid_t tid = gettid();
    pid_t pid = getpid();
    pthread_t p = pthread_self();
    printf("pid tid pthread_t\n");
    printf("%d %d %ld\n", pid, tid, p);

    while(1) {
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(int argc, char *const argv[]) {
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, printHello, (void *)0);
    if (rc) {
        printf("Error\n");
        exit(1);
    }

    while(1) {
        sleep(1);
    }
    pthread_exit(NULL);
}

