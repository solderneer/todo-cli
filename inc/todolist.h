#include <iostream>
#include <string>

using namespace std;

class TodoElement{
private:
    string timeStamp;
    string todoText;

    TodoElement *nextElem;
    TodoElement *prevElem;

    static TodoElement *latestElem;
    static int noOfElements;
public:
    string getTimeStamp();
    string getTodoText();
    TodoElement *getNextElement();
    TodoElement *getPrevElement();
    int getElementCount();

    void setTodoText(string todoText);
    void setTimeStamp(string timeStamp);
    void setNextElement(TodoElement *nextElem);
    void setPrevElement(TodoElement *prevElem);
    void DeleteElement();

    
    TodoElement(string timeStamp, string todoText);
    TodoElement();
    ~TodoElement();
};

typedef enum {
    TIMESTAMP,
    PRIORITY
} Sort_TypeDef;
