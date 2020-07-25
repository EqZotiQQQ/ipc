//
// Created by michael on 25.07.2020.
//

#ifndef IPC_IPC_FIFO_H
#define IPC_IPC_FIFO_H


int ipcFifoCommunication();
void ipcFifoClient(std::string fPath);
void ipcFifoServer(std::string fPath, std::string msg);


#endif //IPC_IPC_FIFO_H
