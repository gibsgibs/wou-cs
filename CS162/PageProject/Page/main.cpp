#include <iostream>
#include "Page.h"
#include <ctime>
using namespace std;
int main()
{
    //Seed the rand
    srand(time(0));

    //Set up pages, visits automatically 0
    Page page1("http://page1");
    Page page2("http://page2");
    Page page3("http://page3");
    Page page4("http://page4");

    //Set up the links for the pages based on the UML diagram
    page1.addLink(&page2);
    page1.addLink(&page3);
    page2.addLink(&page3);
    page3.addLink(&page1);
    page4.addLink(&page1);
    page4.addLink(&page3);

    //Start on page 1 and change to random page
    Page* currentPage = &page1;
    for (int i = 0; i < 10000; i++)
    {
        //get a random number
        int j = rand() % 100;

        //if k is less than 15 select random page
        if (j <= 15)
        {
            int pageCounter = rand() % 4 + 1;
            if (pageCounter == 1)
            {
                currentPage = &page1;
            }
            else if(pageCounter == 2)
            {
                currentPage = &page2;
            }
            else if(pageCounter == 3)
            {
                currentPage = &page3;
            }
            else
            {
                currentPage = &page4;
            }
        }
        //if j is greater  less than 85 change current on visted link page
        if (j <= 100)
        {
            if (currentPage == &page1)
            {
                currentPage->visit();
                currentPage = page1.getRandomLink();
            }
            else if (currentPage == &page2)
            {
                currentPage->visit();
                currentPage = page2.getRandomLink();
            }
            else if (currentPage == &page3)
            {
                currentPage->visit();
                currentPage = page3.getRandomLink();

            }
            else if (currentPage == &page4)
            {
                currentPage->visit();
                currentPage = page4.getRandomLink();
            }
         }
    };
    cout << page1.getURL() << " has " << (page1.getNumVisits() / 100) << "% of the visits" << endl
         << page2.getURL() << " has " << (page2.getNumVisits() / 100) << "% of the visits" << endl
         << page3.getURL() << " has " << (page3.getNumVisits() / 100) << "% of the visits" << endl
         << page4.getURL() << " has " << (page4.getNumVisits() / 100) << "% of the visits" << endl;
}
