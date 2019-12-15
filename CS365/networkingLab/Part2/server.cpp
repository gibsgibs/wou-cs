#include <stdlib.h>
#include <string>
#include "server_socket.h"
#include "number.h"
#include <sstream>
#include <vector>
#include <iterator>

using std::vector;
using std::istringstream;
using std::istream_iterator;
using std::stoi;
using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    Server_socket* server = new Server_socket();
    server->AcceptConnection();
    string received = server->Receive();
    istringstream iss(received);
    vector<string> args((istream_iterator<string>(iss)), istream_iterator<string>());
    Number myNum(args[2]);
    if(stoi(args[0], 0, 2) == args[1].length())
    {
        if(args[1] == "square")
        {
            myNum.Square();
        }
        else if(args[1] == "cube")
        {
            myNum.Cube();
        }
        else
        {
            cerr << "Server: Invalid arguments." << endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        cerr << "Server: Invalid arguments." << endl;
        exit(EXIT_FAILURE);
    }
    server->Send(myNum.ConvertToBinaryString());
    server->CloseConnection();
    return 0;
}