#include <iostream>
#include <memory> 
#include <stdexcept> 
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;


//my class declaration
class Employee{  //inheriting an abstract class called Promotion
protected:
    int ID;
    std::string name;
    int age;
    int salary;
    std::string position;

public:
    Employee(int ID, std::string name, int age, int salary, std::string position);

    void printContent();
    int getID();
    int getAge();
    int GetSalary();
    std::string getName();
    void newID();
    void newName();
    void newAge();
    void newSalary();
    void newPos();
    string GetPosition();

};

