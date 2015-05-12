cmake_minimum_required(VERSION 3.1)
project(irc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

file( GLOB LIB_HEADERS libs/*.h )

set(SOURCE_FILES main.cpp)
add_executable(irc ${SOURCE_FILES} config/AppConfig.h config/AppConfig.cpp ${LIB_HEADERS} config/ConfigParser.cpp config/ConfigParser.h config/Command.cpp config/Command.h)