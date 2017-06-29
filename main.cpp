#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animals
{
private:
    int height;
    int weight;
    string Name;

    static int noOfAnimals;

public:
    int getHeight(){ return height; }
    int getWeight(){ return weight; }
    string getName(){ return Name; }

    void setHeight(int height) 
    {
        this->height = height;
    }

    void setWeight(int weight)
    {
        this->weight = weight;
    }

    void setName(string Name)
    {
        this->Name = Name;
    }

    Animals(int, int, string);
    Animals();

    ~Animals();

    static int returnNo(){ return noOfAnimals; }
};

int Animals::noOfAnimals = 0;

Animals::Animals(int height, int weight, string Name)
{
    this->height = height;
    this->weight = weight;
    this->Name = Name;
    Animals::noOfAnimals++;
}

Animals::Animals()
{
    this->height = 0;
    this->weight = 0;
    this->Name = "";
}

Animals::~Animals()
{
    cout << "Animal " << (this->Name) << " has been destroyed" << endl;
}

int main(void)
{
    Animals fred;

    fred.setHeight(30);
    fred.setWeight(45);
    fred.setName("Fred");

    cout << fred.getName() << " is " << fred.getWeight() << "kg heavy and " << fred.getHeight() << "cm tall." << endl;

}