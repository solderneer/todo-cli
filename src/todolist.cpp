#include "todolist.h"

int TodoElement::noOfElements = 0;
TodoElement *TodoElement::latestElem = nullptr;
static TodoElement firstElem;

TodoElement::TodoElement(string timeStamp, string todoText)
{
  if(noOfElements == 0)
  {
    latestElem = this;
    this->setPrevElement(nullptr);
    this->setNextElement(nullptr);
  }
  else
  {
   latestElem->setNextElement(this);
   this->setPrevElement(latestElem);
   this->setNextElement(nullptr);
   latestElem = this;
 }

 this->timeStamp = timeStamp;
 this->todoText = todoText;

 noOfElements++;
}

TodoElement::TodoElement()
{
  cout << "TodoElement initialized with null everything" <<endl;
  this->timeStamp = "";
  this->todoText = "";
  this->setPrevElement(nullptr);
  this->setNextElement(nullptr);
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