#include <stdlib.h>
#include <string>
#include <iostream>
#include "client_socket.h"

using std::getline;
using std::stoi;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char **argv)
{
    const static string kIPAddress = "127.0.0.1";

    cout << "Enter the length of the command (110 or 100),\nthe name of the command (\"square\" or \"cube\"),\nand the operand in binary: ";
    string user_input;
    getline(cin, user_input);

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