#include "client_socket.h"
#include <string.h>

using std::cout;
using std::endl;

Client_socket::Client_socket()
{
    client_socket_ = socket(PF_INET, SOCK_STREAM, 0);
}
int Client_socket::Connect(const string& address) const
{
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_addr.s_addr = inet_addr(address.c_str());
    server_address.sin_family = PF_INET;
    server_address.sin_port = htons(2222);
    int error = connect(client_socket_, (struct sockaddr *)&server_address, sizeof(server_address));
    return error;
}
int Client_socket::Send(const string& message) const
{
    int error = send(client_socket_, message.c_str(), strlen(message.c_str()), 0);
    return error;
}
string Client_socket::Receive() const
{
    char buffer[1024] { '\0' };
    read(client_socket_, buffer, 1024);
    return string(buffer);
}
void Client_socket::CloseConnection()
{
    close(client_socket_);
}