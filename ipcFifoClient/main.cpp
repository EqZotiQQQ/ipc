#include <iostream>
#include <filesystem>
#include <fstream>
#include <sys/stat.h>

int ipcFifoClient(std::string fPath);

int main() {

    std::filesystem::path filePath = "../../fifo"; /*Just test of std::filesystem, biggest part of it were removed*/
    if (!std::filesystem::exists(filePath)) {
        std::unique_ptr<std::ofstream> file{new std::ofstream()};
    }
    ipcFifoClient(filePath);
    return 0;
}


int ipcFifoClient(std::string fPath) {
    std::cout << "Pipe Client" << std::endl;
    FILE *fp;
    char readbuf[80];
    umask(0);
    mknod(fPath.c_str(), S_IFIFO|0666, 0);
    while(1) {
        fp = fopen(fPath.c_str(), "r");
        fgets(readbuf, 80, fp);
        printf("Received string: %s\n", readbuf);
        fclose(fp);
        std::string exitCheck(readbuf);
        if(exitCheck == "exit") break;
    }
    return 0;
}