#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using std::string;

class Server_socket
{
    public:
        Server_socket();
        void AcceptConnection() noexcept(false);
        void Send(const string& message);
        string Receive();
        void CloseConnection();
    private:
        int client_socket_ {0};
        int server_socket_ {0};
};

#endif