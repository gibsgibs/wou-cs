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
    if(usedLinks > 0)
    {
        int random = rand() % usedLinks;
        return links[random];
    }
        return nullptr;
}
void Page::addLink(Page* other)
{
    if(usedLinks < 3)
    {
        links[usedLinks] = other;
        usedLinks++;
    }
}
void Page::visit()
{
   visits++;
}
int Page::getNumVisits()
{
   return visits;
}
