#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "todolist.h"

using namespace std;

int main(void)
{
    TodoElement firstElement = TodoElement("00:00:00", "do my laundry");
    TodoElement secondElement = TodoElement("00:00:01", "do my laundry");
    TodoElement thirdElement = TodoElement("00:00:02", "do my laundry");
    TodoElement fourthElement = TodoElement("00:00:03", "do my laundry");

    TodoElement* nextptr = (&firstElement);

    for(int i = 0; i < nextptr->getElementCount(); i++)
    {
        cout << nextptr -> getTimeStamp() << endl;
        nextptr = nextptr -> getNextElement();
    }

    fourthElement.DeleteElement();
    nextptr = (&firstElement);

    for(int i = 0; i < nextptr->getElementCount(); i++)
    {
        cout << nextptr -> getTimeStamp() << endl;
        nextptr = nextptr -> getNextElement();
    }
}