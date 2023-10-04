#include <iostream>
#include <memory> 
#include <stdexcept> 
#include "EmployeeClass.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

// This function reads and displays employee records.
void ReadContent(std::unique_ptr<Employee* []>& records, int& number_of_objects) {
	//creating the variables that we need                 //storing the size of our array
	int user_input = 0, user_input2 = 0, ID = 0, end_of_array = number_of_objects;
	string Employee_Name = "";
	bool specific_record = false;
	cout << "Press 1 to display all the records of employees or 2.To display a specific record\n";
	cin >> user_input;
	system("cls");

	//if user input is 2, in this block of code we ask the user to try and find the employee
	//through its ID or name
	if (user_input == 2) {
		specific_record = true;
		system("cls");
		//taking the second input of our user
		cout << "\nPress 1 to find the employee through ID or 2. To use the name to find it\n";
		if (user_input2 == 1) {
			cout << "ID: ";
			cin >> ID;
		}
		else {
			//if user input is not equal to 2, we will search for the employee through his/her name
			cout << "Name: ";
			cin >> Employee_Name;
		}
	}

	//using a for loop to traverse the array of pointers that contain the addresses of each
	//unique object of our class employee and displaying the values stored at each of those addresses
	//by using the pointers records[0], records[1] and so on...
	int employee_number = 0;
	for (auto pos = 0; pos < end_of_array; pos++) {
		employee_number++;
		if (specific_record == false) {
			cout << "Employee " << employee_number << ":\n";
			records[pos]->printContent(); //accesing the values of unique objects by using the function
			cout << "\n";                 //printContent()
		}
		else {
			//if the user input corresponds to the value stored at the address of a specific object
			//we will find the object and by using again :printContent(), we will display the
			//object's attributes
			if (ID == records[pos]->getID())
				records[pos]->printContent();
			else if (Employee_Name == records[pos]->getName())
				records[pos]->printContent();

			cout << "Press anything to exit the record";
			std::cin.get(); //taking again user input
			system("cls"); //clearing our console
		}
	}
}