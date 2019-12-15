#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using std::string;

class Client_socket
{
    public:
        Client_socket();
        int Connect(const string& address) const;
        int Send(const string& message) const;
        string Receive() const;
        void CloseConnection();
    private:
        int client_socket_ {0};
};

#endif