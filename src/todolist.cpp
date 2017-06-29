#include "todolist.h"

TodoElement::TodoElement(string timeStamp, string todoText)
{
    
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