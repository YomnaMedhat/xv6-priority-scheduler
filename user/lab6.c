#include "kernel/types.h"
#include "user/user.h"

int main() {
    int n;
    int fds[2];
    char buf[100];
    char msg[] = "HELLO";

    pipe(fds);

    int pid = fork();

    if(pid == 0){
        close(fds[0]);
        write(fds[1], msg, strlen(msg));
        close(fds[1]);
        exit(0);
    }
    else {
        close(fds[1]);

        n = read(fds[0], buf, sizeof(buf));

        write(1, "Received ", 10);
        write(1, buf, n);

        close(fds[0]);

        wait(0);
    }

    exit(0);
}
