#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

class TodoElement{
private:
    std::string timeStamp;
    std::string todoText;

public:
    std::string getTimeStamp();
    std::string getTodoText();

    void setTodoText(std::string todoText);
    void setTimeStamp(std::string timeStamp);
    
    TodoElement(std::string timeStamp, std::string todoText);
    TodoElement();
    ~TodoElement();
};

typedef enum {
    TIMESTAMP,
    PRIORITY
} Sort_TypeDef;