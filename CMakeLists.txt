cmake_minimum_required(VERSION 3.1)
project(irc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(irc ${SOURCE_FILES} connection/ConnectionProvider.cpp connection/ConnectionProvider.h connection/ConnectionType.h connection/IConnectionManager.cpp connection/IConnectionManager.h connection/ClientConnectionManager.cpp connection/ClientConnectionManager.h connection/ServerConnectionManager.cpp connection/ServerConnectionManager.h)