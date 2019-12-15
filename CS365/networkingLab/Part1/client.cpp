#include <stdlib.h>
#include <string>
#include "client_socket.h"

using std::stoi;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char **argv)
{
    const static string kIPAddress = "127.0.0.1";

    cout << "Enter a number in binary to be squared: ";
    string user_input;
    cin >> user_input;

    Client_socket* client = new Client_socket();
    client->Connect(kIPAddress);
    client->Send(user_input);
    string receieved = client->Receive();
    client->CloseConnection();
    cout << "Server: "
         << receieved 
         << endl;
    return 0;
}