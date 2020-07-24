#include <iostream>

#include "ipc_half_duplex.h"

int main() {
    std::cout << "main begin" << std::endl;
    halfDuplexCommunication();
    std::cout << "main end" << std::endl;
    return 0;
}
