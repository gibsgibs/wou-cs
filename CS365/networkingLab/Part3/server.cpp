#include <stdlib.h>
#include <string>
#include "server_socket.h"
#include "number.h"
#include <sstream>
#include <vector>
#include <iterator>
#include <bitset>

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
    if (args.size() < 3)
    {
        cerr << "Server: Invalid arguments.\n";
        exit(EXIT_FAILURE);
    }
    else if (args.size() == 3 && args[0] == "110" && args[1] == "negate")
    {
        Number myNum(args[2]);
        server->Send(myNum.Negate());
    }
    else
    {
        Number myNum(args[2], args[3]);
        if(stoi(args[0], 0, 2) == args[1].length())
        {
            if(args[1] == "sum")
            {
                myNum.Sum();
            }
            else if(args[1] == "product")
            {
                myNum.Product();
            }
            else
            {
                cerr << "Server: Invalid arguments." << endl;
                exit(EXIT_FAILURE);
            }
            server->Send(myNum.ConvertToBinaryString());
        }
        else
        {
            cerr << "Server: Invalid arguments." << endl;
            exit(EXIT_FAILURE);
        }
    }
    server->CloseConnection();
    return 0;
}