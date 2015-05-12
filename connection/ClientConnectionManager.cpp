//
// Created by miko on 11.05.15.
//

#include <string.h>
#include <unistd.h>
#include "ClientConnectionManager.h"

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
    if (write( sock, messageChar, sizeof messageChar) == -1)
        perror("writing on stream socket");
}

std::string ClientConnectionManager::readMessage()
{
    if (sock == -1 )
        perror("accept");
    else
    {
        memset(buf, 0, sizeof buf);
        if ((read(sock,buf, 1024)) == -1)
            perror("reading stream message");
        else
            return buf;
    }
}
