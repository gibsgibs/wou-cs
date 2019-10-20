#include <DLList.h>
#include <stdexcept>

void printList(const DLList<string>& list)
{
    cout << "Printing the list of size "
         << list.getSize()
         << endl;
    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list.get(i) << " ";
    }
        cout << "\n\n";
    }

int main()
{
    DLList<string> myList;

    cout << "Adding the strings 1, 2, 3 and 4 to the list:\n";
    myList.add("1");
    myList.add("2");
    myList.add("3");
    myList.add("4");
    printList(myList);

    cout << "Adding the strings a, b, c, and d to the list:\n";
    myList.add(4, "a");
    myList.add(5, "b");
    myList.add(6, "c");
    myList.add(7, "d");
    printList(myList);

    cout << "Removing the even numbers from the list:\n";
    myList.remove("2");
    myList.remove("4");
    printList(myList);

    cout << "Removing the 'even' letters from the list:\n";
    string temp1 = myList.removeAt(3);
    string temp2 = myList.removeAt(4);
    cout << "We removed "
         << temp1
         << " and "
         << temp2
         << " fromt the list.\n";
    printList(myList);




return 0;
}
