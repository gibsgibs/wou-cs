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
    /**
     * @brief Page - the no arg constructor that
     *               makes a blank page.
     */
    Page();
    /**
     * @brief Page - the single argument constuctor
     *               that makes the page url whatever
     *               the parameter is.
     * @param urlValue - the URL value
     */
    Page(string urlValue);
    /**
     * @brief getURL - getter that gets the URL
     * @return - returns the URL
     */
    string getURL();
    /**
     * @brief getNumLinks - returns the number of used
     *                      links.
     * @return - retuns usedLinks.
     */
    int getNumLinks();
    /**
     * @brief getRandomLink - selects a random address
     *                        from the links the page
     *                        has and returns it
     * @return - retuns a random position in the array
     */
    Page* getRandomLink();
    /**
     * @brief addLink - should store the given pointer
     *                  into the links array at the next
     *                  available location and increment
     *                  the number of usedLinks.
     * @param other - a pointer to next location
     */
    void addLink(Page* other);
    /**
     * @brief visit - adds one to the visits
     */
    void visit();
    /**
     * @brief getNumVisits - returns the number of
     *                       visits.
     *
     * @return - visits
     */
    int getNumVisits();
};

#endif // PAGE_H
