//
// Created by miko on 11.05.15.
//

#include <string.h>
#include <unistd.h>
#include <iostream>
#include "ClientConnectionManager.h"
#include "NoReadersException.h"

void ClientConnectionManager::openConnection() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("opening stream socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    hp = gethostbyname(ip.c_str());

    if (hp == (struct hostent *) 0)
    {
        fprintf(stderr, "%s: unknown host\n", ip.c_str());
        exit(2);
    }

    memcpy((char *) &server.sin_addr, (char *) hp->h_addr, hp->h_length);
    server.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &server, sizeof server) == -1)
    {
        perror("connecting stream socket");
        exit(1);
    }
}

void ClientConnectionManager::closeConnection()
{
    close(sock);
}

void ClientConnectionManager::writeMessage(std::string message)
{
    char messageChar[1024];
    strcpy(messageChar, message.c_str());
    mtx.lock();
    if (send( sock, messageChar, sizeof messageChar, MSG_NOSIGNAL) == -1)
        perror("writing on stream socket");
    mtx.unlock();
}

std::string ClientConnectionManager::readMessage()
{
    if (sock == -1 )
        perror("accept");
    else
    {
        int bufSize = sizeof buf;
        char *tmpBufAddr = buf;
        int bytesRead = 0;
        int rval;
        memset(buf, 0, bufSize);

        while (bytesRead < bufSize)
        {
            if ((rval = read(sock, tmpBufAddr + bytesRead, bufSize - bytesRead)) == -1)
                perror("reading stream message");
            else if (rval == 0)
                throw NoReadersException();

            bytesRead += rval;
        }
        return buf;
    }
}
