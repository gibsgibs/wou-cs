/**
  * @brief Assignment 5
  * @authors Gabriel Brehm
  */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    //get the file
    ifstream assign5;

    //check if the file exists
        if(assign5.fail())
        {
            cout << "File does not exist." << endl;
            cout << "Exit program." << endl;
            return 0;
        }

    //print out the header row
    cout << left << setw(30) << "Name"
         << "Type" << "\t"
         << "Width" << "\t"
         << "Height" << "\t"
         << "Size" << endl;

    //open the file
    assign5.open("images.txt");

    //setup a variable for the total size in kb
    double total = 0;

    //make a while loop that goes until it reaches the end of the file
    while(!assign5.eof())
    {
        //set the parts of the file as image, trash, and size
        string image;
        string trash;
        double size;

        //call in the infromation from the file
        assign5 >> image >> trash >> size;

        //set up a bunch of variables that will help find the specific parts of the image
        int questionMarkPos = image.find("?");
        int forthSlashPos = image.rfind("/");
        int xPos = image.find("x", questionMarkPos);
        int firstSpacePos = image.find(" ", questionMarkPos);

        //set the parts of the image as name, type, width, height and size
        string width = image.substr((questionMarkPos + 1), (xPos - questionMarkPos - 1));
        string height = image.substr((xPos + 1), (firstSpacePos - xPos - 1));
        string name = image.substr((forthSlashPos + 1), (questionMarkPos - forthSlashPos - 1));
             int nameDot = name.find(".");
        string type = name.substr(nameDot + 1);
        double sizeKilo = size / 1024;

        //printing out the table
        cout << fixed << setprecision(1)
             << left << setw(30) << name
             << type << "\t"
             << width << "\t"
             << height << "\t"
             << sizeKilo << endl;
        total += sizeKilo;
    }
    //output the total size in kb after the table
    cout << "\n\t\t\t\t\t\t"
         << "Total Size: "
         << total << endl;

    //close the file
    assign5.close();

    return 0;
}
