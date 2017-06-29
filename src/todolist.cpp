#include "todolist.h"

TodoElement::TodoElement(string timeStamp, string todoText, TodoElement* ptr)
{
    latestElem->setNextElement(ptr);
    this->setPrevElement(latestElem);
    latestElem = ptr;

    this->timeStamp = timeStamp;
    this->todoText = todoText;
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