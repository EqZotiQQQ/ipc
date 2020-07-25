#include <iostream>

#include "ipc_half_duplex.h"
#include "ipc_fifo.h"

int main(int argc, char *argv[]) {
    //std::cout << "main begin" << std::endl;
    //halfDuplexCommunication();
    ipcFifoCommunication();
    //std::cout << "main end" << std::endl;
    return 0;
}
