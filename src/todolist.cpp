#include "todolist.h"

int TodoElement::noOfElements = 0;
TodoElement *TodoElement::latestElem = nullptr; 

TodoElement::TodoElement(string timeStamp, string todoText, TodoElement* ptr)
{
    if(noOfElements == 0)
    {
        latestElem = ptr;
        this->setPrevElement(nullptr);
        this->setNextElement(nullptr);
    }
    else
    {
       latestElem->setNextElement(ptr);
       this->setPrevElement(latestElem);
       this->setNextElement(nullptr);
       latestElem = ptr;
   }

   this->timeStamp = timeStamp;
   this->todoText = todoText;

   noOfElements++;
}

TodoElement::TodoElement()
{
    cout << "TodoElement initialized with null everything" <<endl;
}

TodoElement::~TodoElement()
{
    cout << "TodoElement destroyed" <<endl;
}

string TodoElement::getTodoText()
{
    return todoText;
}

void TodoElement::setTodoText(string todoText)
{
    this->todoText = todoText;
}

string TodoElement::getTimeStamp()
{
    return timeStamp;
}

void TodoElement::setTimeStamp(string timeStamp)
{
    this->timeStamp = timeStamp;
}

TodoElement *TodoElement::getNextElement()
{
    return nextElem;
}

void TodoElement::setNextElement(TodoElement *nextElem)
{
    this->nextElem = nextElem;
}

TodoElement *TodoElement::getPrevElement()
{
    return prevElem;
}

void TodoElement::setPrevElement(TodoElement *prevElem)
{
    this->prevElem = prevElem;
}