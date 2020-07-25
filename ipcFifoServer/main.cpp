#include <iostream>
#include <filesystem>
#include <memory>
#include <fstream>

int ipcFifoServer(std::string fPath, std::string msg);


int main() {
    std::filesystem::path filePath = "../../fifo"; /*Just test of std::filesystem, biggest part of it were removed*/
    if (!std::filesystem::exists(filePath)) {
        std::cout << "file doesn't exist" << std::endl;
        std::unique_ptr<std::ofstream> file{new std::ofstream{filePath}};
    }
    std::string msg;
    std::cin >> msg;
    while(1) {
        ipcFifoServer(filePath, msg);
        if(msg == "exit") break;
        std::cin >> msg;
    }
    return 0;
}


int ipcFifoServer(std::string fPath, std::string msg) {
    FILE *fp;
    if ((fp = fopen(fPath.c_str(), "w")) == NULL)
    {
        perror("fopen");
        std::cout << "not okay?" << std::endl;
        return 1;
    }
    fputs( msg.c_str(), fp);
    fclose(fp);
    return 0;
}