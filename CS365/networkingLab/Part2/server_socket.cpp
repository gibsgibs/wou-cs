#include "server_socket.h"
#include <string.h>
#include <exception>

using std::exception;
using std::cout;
using std::cerr;
using std::endl;

Server_socket::Server_socket()
{
    server_socket_ = socket(PF_INET, SOCK_STREAM, 0);
    client_socket_ = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_family = PF_INET;
    server_address.sin_port = htons(2222);

    int error = bind(server_socket_, (struct sockaddr *)&server_address, sizeof(server_address));
    if (error == -1)
    {
        cerr << "Server: Failed to bind." << endl;
        throw exception();
    }

}
void Server_socket::AcceptConnection() noexcept(false)
{
    int error = listen(server_socket_, 10);
    if (error == -1)
    {
        cerr << "Server: Failed to listen." << endl;
        throw exception();
    }
    struct sockaddr_in client_address;
    socklen_t client_addr_len;
    error = client_socket_ = accept(server_socket_, (struct sockaddr *)&client_address, &client_addr_len);
    if (error == -1)
    {
        cerr << "Server: Failed to accept." << endl;
        throw exception();
    }
}
void Server_socket::Send(const string& message)
{
    int error = send(client_socket_, message.c_str(), strlen(message.c_str()), 0);
    if (error == -1)
    {
        cerr << "Server: Failed to send." << endl;
        throw exception();
    }
}

string Server_socket::Receive()
{
    char buffer[1024] { '\0' };
    read(client_socket_, buffer, 1024);
    return string(buffer);
}

void Server_socket::CloseConnection()
{
    close(client_socket_);
    close(server_socket_);
}