//
// Created by michael on 25.07.2020.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include <thread>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/stat.h>
#include <vector>

#include "ipc_fifo.h"

/*
 * This might be not threads but separate processes.
 * I wanted to test it in single solution.
 * Maybe I will test it later.
 * */
int ipcFifoCommunication() {
    int ret {0};
    std::filesystem::path filePath = std::filesystem::current_path() += "/fifo"; /*Just test of std::filesystem, biggest part of it were removed*/
    if (!std::filesystem::exists(filePath)) {
        std::unique_ptr<std::ofstream> file{new std::ofstream{filePath}};
    }
    std::string msg;
    std::cin >> msg;

    std::thread server {ipcFifoServer, filePath, msg};
    server.join();
    std::thread client {ipcFifoClient, filePath};
    client.join();

    return ret;
}

void ipcFifoServer(std::string fPath, std::string msg) {
    std::cout << "server thread" << std::endl;
    FILE *fp;
    if ((fp = fopen(fPath.c_str(), "w")) == NULL)
    {
        perror("fopen");
        exit(1);
    }
    fputs( msg.c_str(), fp);
    fclose(fp);

}

void ipcFifoClient(std::string fPath) {
    std::cout << "Client thread" << std::endl;
    FILE *fp;
    char readbuf[80];
    umask(0);
    mknod(fPath.c_str(), S_IFIFO|0666, 0);
    /*
     * its gonna be smarter if u will read file after it update
     * with smth like poll, epoll etc. Need to read about it.
     */
    while(1)
    {
        fp = fopen(fPath.c_str(), "r");
        fgets(readbuf, 80, fp);
        printf("Received string: %s\n", readbuf);
        fclose(fp);
        return;
    }

}
