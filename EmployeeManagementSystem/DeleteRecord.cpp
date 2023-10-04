#include <iostream>
#include <memory> 
#include <stdexcept>
#include "EmployeeClass.h"
#include "ActualHeader.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void deleteRecord(std::unique_ptr<Employee* []>& record, int& number_of_objects) {
	
	system("cls");
	cout << "Enter the id of the employee's record in order to delete it\n";
	int deleteThisID = 0, record_num = 0;
	cin >> deleteThisID;

	//searching for the record by using the ID, if the record does not exist say that to user
	for (auto i = 0; i < number_of_objects; i++) {
		if (deleteThisID == record[i]->getID()) {
			record_num = i;
			break;
		}
		if (i == number_of_objects - 1) {  //if the record was not found
			cout << "Record not found!\n";
			cout << "Try again later";
			exit(0);
		}
	}

	//delete the record and make our record[] pointer point to the next record, therefore
	//updating the arrays of pointers
	for (auto i = record_num; i < number_of_objects - 1; i++) {
		if (i == record_num)
			delete record[record_num];  //deleting the memory allocated for record ptr( or the record)
		record[i] = record[i + 1];  //giving the record pointer, the address of
		                     //the next record pointer so that no record pointer points to null
	}

	number_of_objects = number_of_objects - 1;  //decreasing the number of objects by 1 after deletion
	system("cls");
	cout << "The record with the ID: " << deleteThisID << " was successfully deleted!\n";

	//resetting our variables so that we can use this function again to delete another record
	deleteThisID = 0, record_num = 0;
	
}

