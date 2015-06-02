//
// Created by miko on 11.05.15.
//

#include <string.h>
#include <iostream>
#include "ServerConnectionManager.h"
#include "NoReadersException.h"

void ServerConnectionManager::openConnection()
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("opening stream socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *) &server, sizeof server) == -1)
    {
        perror("binding stream socket");
        exit(1);
    }

    length = sizeof server;
    if (getsockname(sock,(struct sockaddr *) &server,&length) == -1) {
        perror("getting socket name");
        exit(1);
    }

    printf("Socket port #%d\n", ntohs(server.sin_port));

    listen(sock, 1);

    msgsock = accept(sock,(struct sockaddr *) 0,(socklen_t *) 0);
}

void ServerConnectionManager::closeConnection()
{
    close (msgsock);
}

void ServerConnectionManager::writeMessage(std::string message)
{
    char messageChar[1024];
    strcpy(messageChar, message.c_str());
    mtx.lock();
    try {
        if (send(msgsock, messageChar, sizeof messageChar, MSG_NOSIGNAL) == -1)
            std::cout << "Klient jest odlaczony";
    } catch (std::exception e) {
        //nie wysylaj
    }
    mtx.unlock();

}

std::string ServerConnectionManager::readMessage()
{
    if (msgsock == -1 )
        perror("accept");
    else
    {
        memset(buf, 0, sizeof buf);
        if ((rval = read(msgsock,buf, 1024)) == -1)
                std::cout<<"Klient jest odlaczony";
//                perror("reading stream message");
        else if (rval == 0)
        {
            throw NoReadersException();
        }
        else
            return buf;
    }
}
