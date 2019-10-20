#include "Page.h"
#include <iostream>
using namespace std;

Page::Page()
{
    url = "";
    visits = 0;
    links[3] = nullptr;
    usedLinks = 0;
}
Page::Page(string urlValue)
{
    url = urlValue;
    visits = 0;
    links[3] = nullptr;
    usedLinks = 0;
}
string Page::getURL()
{
    return url;
}
int Page::getNumLinks()
{
    return usedLinks;
}
Page* Page::getRandomLink()
{

}
void Page::addLink(Page* other)
{
    int i = 0;
    do
    {
        if(links[i] == nullptr)
        {
            links[i] = other;
        }
        else if(links[i] == other)
        {
            usedLinks++;
        }
        i++;
    }while(links[i] != other);
}
void Page::visit()
{
   visits++;
}
int Page::getNumVisits()
{
   return visits;
}
