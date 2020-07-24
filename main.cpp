#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>


int main() {
    std::cout << "begin" << std::endl;
    int         fd[2];
    int         nBytes;
    pid_t       childPid;
    char output_msg[] = "Hello World!\n";
    char input_msg[256];
    pipe(fd);
    if((childPid = fork()) == -1) {
        perror("pipe error");
        return 1;
    }
    std::cout << "childPid = " << childPid << std::endl;
    if(childPid == 0) {
        close(fd[0]);
        std::cout << "slave proc" << std::endl;
        write(fd[1], output_msg, sizeof(output_msg));
    } else {
        close(fd[1]);
        std::cout << "master proc" << std::endl;
        nBytes = read(fd[0], input_msg, sizeof(input_msg));
        printf("%s, %d",input_msg, nBytes);
    }
    std::cout << "end" << std::endl;
    return 0;
}
