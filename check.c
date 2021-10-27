#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>

ssize_t process_vm_readv(
    pid_t, const struct iovec *, unsigned long liovcnt,
    const struct iovec *remote_iov, unsigned long riovcnt, unsigned long flags
);

#define BUFFER_SIZE (300)

int main(int argc, char *const argv[]) {
    char* end;
    pid_t pid = strtol(argv[1], &end, 10);
    pid_t tid = strtol(argv[2], &end, 10);
    pthread_t p = strtol(argv[3], &end, 10);

    printf("pid = %d\n", pid);
    printf("tid = %d\n", tid);
    printf("pthread tid = %ld\n", p);

    void* buf[BUFFER_SIZE];
    struct iovec local[1];
    struct iovec remote[1];

    unsigned int len = BUFFER_SIZE * sizeof(void *);

    local[0].iov_base = buf;
    local[0].iov_len = len;
    remote[0].iov_base = (void *)p;
    remote[0].iov_len = len;

    ssize_t result = process_vm_readv(pid, local, 1, remote, 1, 0);
    printf("process_vm_readv result = %d\n", result);
    if (result == -1) {
        printf("errno = %d\n", errno);
    }

    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (tid == (uintptr_t) buf[i]) {
            printf("Found tid !!\n");
        }
    }
    return 0;
}

