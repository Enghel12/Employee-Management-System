#include <iostream>
#include <memory> 
#include <stdexcept>
#include "EmployeeClass.h"
#include "ActualHeader.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;


//this function lets the user to change the content of a record(of an employee object)
void UpdateRecord(std::unique_ptr<Employee* []>& record, int& number_of_objects) {

	//step 1: prompting the user to give us the id of the employee record 
	int user_id = 0;
	cout << "Choose the record that you want to update by entering the employee's ID: \n";
	CheckIfInputInteger(user_id);

	//step 2: using a for loop to traverse the array of pointers and find that specific record
	auto i = 0;
	for (i; i < number_of_objects; i++) {
		if (user_id == record[i]->getID()) {
			break;
		}
	}

	int execute_again = 0;
	do {
		//using the pointer that corresponds to the specific record(object) to modify its content
		record[i]->newID();
		record[i]->newName();
		record[i]->newAge();
		record[i]->newSalary();
		record[i]->newPos();

		cout << "The employee record after modifications: \n";
		record[i]->printContent();
		cout << "If you want to modify it again, press 1\n";
		cout << "\nPress 0 to finish updating or 1 to update again the same record\n";
		cin >> execute_again;

	} while (execute_again == 1);  //if the user input is not 1, do not repeat the process
	//else, access again the same object by using our pointer record[position] and modify it
}