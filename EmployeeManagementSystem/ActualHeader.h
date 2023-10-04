#include <iostream> //library that enables us to use cout, cin, endl..
#include <memory> //for the smart pointers
#include <stdexcept> //library that allows us to use expections
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Employee;

void ReadContent(std::unique_ptr<Employee* []>& records, int& number_of_objects);
void CreateRecord(int* ptrID, string* ptrEmployeeName, int* ptrAge, int* ptrSalary, string* ptrPosition);
void UpdateRecord(std::unique_ptr<Employee* []>& record, int& number_of_objects);
int CheckIfInputInteger(int& user_input);
void deleteRecord(std::unique_ptr<Employee* []>& record, int& number_of_objects);
void sortByIDSalary(std::unique_ptr<Employee* []>& record, int& number_of_objects);
int addSalaries(std::unique_ptr<Employee* []>& record, int& number_of_objects);
void saveToFile(std::unique_ptr<Employee* []> &record, int &number_of_objects);
