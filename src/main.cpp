#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "todolist.h"

using namespace std;


int main(void)
{
    TodoElement *ptr = (TodoElement *)malloc(sizeof(TodoElement));
    TodoElement *ptr1 = (TodoElement *)malloc(sizeof(TodoElement));
    TodoElement firstElem = TodoElement("00:00:00", "do my laundy", ptr);
    TodoElement secondElem = TodoElement("00:00:01", "do my homework", ptr1);

    cout << "The first todo is to " << firstElem.getTodoText() << " at " << firstElem.getTimeStamp() << endl;
    cout << "The next todo element is at address " << firstElem.getNextElement() << endl;

    TodoElement *nextptr = firstElem.getNextElement();

    cout << "The second todo is to " << nextptr->getTodoText() << " at " << nextptr->getTimeStamp() << endl;
    cout << "The next todo element is at address " << firstElem.getNextElement() << endl;
}