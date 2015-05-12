cmake_minimum_required(VERSION 3.1)
project(irc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES main.cpp)
add_executable(irc ${SOURCE_FILES} 
tranmission/transmission-initializers/TransmissionInitializer.cpp 
tranmission/transmission-initializers/TransmissionInitializer.h 
tranmission/communication-service/CommunicationServiceStandard.cpp 
tranmission/communication-service/CommunicationServiceStandard.h 
tranmission/threads/Listener.cpp 
tranmission/threads/Listener.h 
tranmission/TransmissionStatus.cpp 
tranmission/TransmissionStatus.h 
tranmission/threads/CycleWriter.cpp 
tranmission/threads/CycleWriter.h 
mock/ConnectionManagerMock.cpp 
mock/ConnectionManagerMock.h 
tranmission/threads/ThreadItem.h 
tranmission/communication-service/CommunicationServiceFactory.cpp 
tranmission/communication-service/CommunicationServiceFactory.h 
tranmission/ICommunicationService.h 
tranmission/communication-service/CommunicationServiceAsync.cpp 
tranmission/communication-service/CommunicationServiceAsync.h 
tranmission/ITransmissionInitializer.cpp 
tranmission/ITransmissionInitializer.h 
tranmission/threads/AsyncRewriter.cpp 
tranmission/threads/AsyncRewriter.h 
tranmission/transmission-initializers/AsyncTransmissionInitializer.cpp 
tranmission/transmission-initializers/AsyncTransmissionInitializer.h
config/AppConfig.h
config/AppConfig.cpp ${LIB_HEADERS}
config/ConfigParser.cpp
config/ConfigParser.h
config/Command.cpp
config/Command.h
connection/ConnectionProvider.cpp
connection/ConnectionProvider.h
connection/ConnectionType.h
connection/IConnectionManager.cpp
connection/IConnectionManager.h
connection/ClientConnectionManager.cpp
connection/ClientConnectionManager.h
connection/ServerConnectionManager.cpp
connection/ServerConnectionManager.h)