#include <iostream>
#include <unistd.h>

int halfDuplexCommunication();


int main() {
    halfDuplexCommunication();
    return 0;
}


int halfDuplexCommunication() {
    int ret = 0;
    std::cout << "begin halfDuplexCommunication" << std::endl;
    int fd[2];
    int nBytes;
    pid_t pid;
    char output_msg[] = "Hello World!\n";
    char input_msg[256];
    pipe(fd);
    if ((pid = fork()) == -1) {
        perror("pipe error");
        return 1;
    }
    std::cout << "childPid = " << pid << std::endl;
    if (pid == 0) {
        close(fd[0]);
        std::cout << "slave proc" << std::endl;
        write(fd[1], output_msg, sizeof(output_msg));
    } else {
        close(fd[1]);
        std::cout << "master proc" << std::endl;
        nBytes = read(fd[0], input_msg, sizeof(input_msg));
        printf("%s", input_msg, nBytes);
    }
    std::cout << "end halfDuplexCommunication" << std::endl;
    return ret;
}