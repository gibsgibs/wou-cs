#include <stdlib.h>
#include <string>
#include "server_socket.h"
#include "number.h"

using std::stoi;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    Server_socket* server = new Server_socket();
    server->AcceptConnection();
    string received = server->Receive();
    cout << "Client: "
         << received
         << endl;
    Number myNum(received);
    myNum.Square();
    server->Send(myNum.ConvertToBinaryString());
    server->CloseConnection();
    return 0;
}