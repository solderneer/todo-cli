#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "todolist.h"

using namespace std;


int main(void)
{
    TodoElement firstElem = TodoElement("00:00:00", "do my laundy");
    TodoElement secondElem = TodoElement("00:00:01", "do my homework");
    TodoElement thirdElem = TodoElement("00:00:01", "do my work");


    cout << "The first todo is to " << firstElem.getTodoText() << " at " << firstElem.getTimeStamp() << endl;
    cout << "The next todo element is at address " << firstElem.getNextElement() << endl;

    TodoElement *nextptr = firstElem.getNextElement();

    cout << "The second todo is to " << secondElem.getTodoText() << " at " << secondElem.getTimeStamp() << endl;
    cout << "The next todo element is at address " << secondElem.getNextElement() << endl;
}