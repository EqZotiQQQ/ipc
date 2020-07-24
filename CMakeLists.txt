cmake_minimum_required(VERSION 3.16)
project(ipc)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES_DIR
        src
        )

set(HEADERS_DIR
        headers
        )

set(SOURCES
        main.cpp
        ${SOURCES_DIR}/ipc_half_duplex.cpp
        ${SOURCES_DIR}/ipc_fifo.cpp
        )

set(HEADERS
        ${HEADERS_DIR}/ipc_half_duplex.h
        ${HEADERS_DIR}/ipc_fifo.h
        )

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/${HEADERS_DIR}
)

add_executable(ipc ${SOURCES} ${HEADERS})