#include <iostream>
#include <memory>
#include "ActualHeader.h"
#include "EmployeeClass.h"
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void saveToFile(std::unique_ptr<Employee* []>& records, int& number_of_objects) {

	//Creating a vector of objects that we will use to store the content of our objects
	//to the notepad file
	std::vector<Employee> objects;

	//storing the content of our objects of class Employee to our vector
	for (auto i = 0; i < number_of_objects; i++) {
		Employee emp( //creating a temporary placeholder for the content of each object
			records[i]->getID(), //accessing all the attributes of an object
			records[i]->getName(),
			records[i]->getAge(),
			records[i]->GetSalary(),
			records[i]->GetPosition()
		);
		objects.push_back(emp);  //storing that placeholder/object to our vector
	}

	//Creating a file called Records.txt
	std::fstream myFile;
	myFile.open("Records.txt", std::ios::out);
	if (!(myFile.is_open())) {  //if my file is not open/doesn't exist
		cout << "Error, cannot open file!";
		exit(0);
	}
	else {
		myFile << "This is the final list of records, after all modifications: \n";
		//storing the content of each object to our file
		for (Employee& emp : objects) {  //using a range based loop to store the objects
			myFile << "ID: " << emp.getID();
			myFile << "\nName: " << emp.getName();
			myFile << "\nAge: " << emp.getAge();
			myFile << "\nSalary: " << emp.GetSalary();
			myFile << "\nCurrent position: " << emp.GetPosition();
			myFile << "\n\n";
		}
	}

	myFile.close(); //closing the file

	//displaying the content of our notepad if the user wants to
	system("cls");
	cout << "Records stored successfully!\n";
	cout << "Would you like to see the record list ?\n";
	int choice = 0;
	cin >> choice;
	system("cls");
	
	if (choice == 1) {
		myFile.open("Records.txt", std::ios::in);  //opening the file again

		if (!(myFile.is_open())) {  //if my file is not open/doesn't exist
			cout << "Error, cannot open file!";
			exit(0); //exit the program
		}
		else {
		   //printing the records stored in the notepad file
			string line = "";  //storing each line of notepad to this string
			while (getline(myFile, line)) {
				cout << line << "\n";  //printing each line
			}
		}
		myFile.close(); //closing the file one last time
	}

}