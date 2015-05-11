cmake_minimum_required(VERSION 3.1)
project(irc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(irc ${SOURCE_FILES} tranmission/TransmissionInitializer.cpp tranmission/TransmissionInitializer.h tranmission/CommunicationService.cpp tranmission/CommunicationService.h tranmission/threads/Listener.cpp tranmission/threads/Listener.h tranmission/TransmissionStatus.cpp tranmission/TransmissionStatus.h tranmission/threads/CycleWriter.cpp tranmission/threads/CycleWriter.h)