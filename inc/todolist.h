#include <iostream>
#include <string>

using namespace std;

class TodoElement{
private:
    string timeStamp;
    string todoText;
    TodoElement *nextElem;
public:
    string getTimeStamp();
    string getTodoText();
    TodoElement *getNextElement();

    void setTodoText(string todoText);
    void setTimeStamp(string timeStamp);

    
    TodoElement(string timeStamp, string todoText);
    TodoElement();
    ~TodoElement();
};