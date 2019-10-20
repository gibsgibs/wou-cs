#ifndef PAGE_H
#define PAGE_H
#include <iostream>

using namespace std;
class Page
{
private:
    string url;
    int visits;
    Page* links[3];
    int usedLinks;
public:
    Page();
    Page(string urlValue);
    string getURL();
    int getNumLinks();
    Page* getRandomLink();
    void addLink(Page* other);
    void visit();
    int getNumVisits();
};

#endif // PAGE_H
