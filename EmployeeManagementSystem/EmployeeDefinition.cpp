#include <iostream>
#include <memory> 
#include <stdexcept>
#include "EmployeeClass.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

//Definition of my class
Employee::Employee(int ID, std::string name, int age, int salary, std::string position)
    : ID(ID), name(name), age(age), salary(salary), position(position) {}

//Definitions of each functions of our class Employee
void Employee::printContent() {
    std::cout << "ID: " << ID << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Current Salary: " << salary << "\n";
    std::cout << "Current position: " << position << "\n";
}

int Employee::getID() {
    return ID;
}

int Employee::getAge() {
    return age;
}

int Employee::GetSalary() {
    return salary;
}

std::string Employee::getName() {
    return name;
}

string Employee::GetPosition() {
    return position;
}

void Employee::newID() {
    int skip = 0;
    std::cout << "Press 1 for a new ID or move to the next attribute\n";
    std::cin >> skip;

    if (skip == 1) {
        system("cls");
        std::cout << "Enter the new ID: \n";
        int user_choice;
        std::cin >> user_choice;
        ID = user_choice;
    }
    system("cls");
    if (skip == 1) std::cout << "Attribute updated successfully! \n";
}

void Employee::newName() {
    int skip = 0;
    std::cout << "Press 1 for a new name or move to the next attribute\n";
    std::cin >> skip;

    if (skip == 1) {
        system("cls");
        std::cout << "Enter the new name: \n";
        std::string new_name = "";
        std::cin >> new_name;
        name = new_name;
    }
    system("cls");
    if (skip == 1) std::cout << "Attribute updated successfully! \n";
}

void Employee::newAge() {
    int skip = 0;
    std::cout << "Press 1 for a new age or move to the next attribute\n";
    std::cin >> skip;

    if (skip == 1) {
        system("cls");
        std::cout << "Enter the new age: \n";
        int newAge;
        std::cin >> newAge;
        age = newAge;
    }
    system("cls");
    if (skip == 1) std::cout << "Attribute updated successfully! \n";
}

void Employee::newSalary() {
    int skip = 0;
    std::cout << "Press 1 for a new salary or move to the next attribute\n";
    std::cin >> skip;

    if (skip == 1) {
        system("cls");
        std::cout << "Enter the new salary: \n";
        int newSalary;
        std::cin >> newSalary;
        salary = newSalary;
    }
    system("cls");
    if (skip == 1) std::cout << "Attribute updated successfully! \n";
}

void Employee::newPos() {
    int skip = 0;
    std::cout << "Press 1 for a new position or move to the next attribute\n";
    std::cin >> skip;

    if (skip == 1) {
        system("cls");
        std::cout << "Enter new position: \n";
        std::string new_position = "";
        std::cin >> new_position;
        position = new_position;
    }
    system("cls");
    if (skip == 1) std::cout << "Attribute updated successfully! \n";
}
