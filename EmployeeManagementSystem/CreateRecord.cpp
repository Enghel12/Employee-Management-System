#include <iostream>
#include <memory> 
#include <stdexcept> 

using std::cout;
using std::endl;
using std::cin;
using std::string;

//this function helps us create a new record using pointers
void CreateRecord(int* ptrID, string* ptrEmployeeName, int* ptrAge, int* ptrSalary, string* ptrPosition) {
	//here we dereference pointers to modify the values stored at the addresses they are pointing to
	cout << "Enter ID: \n";
	cin >> *(ptrID);

	cout << "Enter Employee Name: \n";
	cin >> *(ptrEmployeeName);

	cout << "Enter his/her age: \n";
	cin >> *(ptrAge);

	cout << "Enter Salary: \n";
	cin >> *(ptrSalary);

	cout << "Enter it's current position: \n";
	cin >> *(ptrPosition);
	system("cls");

}
