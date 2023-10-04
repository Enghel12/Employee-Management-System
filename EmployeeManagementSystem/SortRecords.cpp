#include <iostream>
#include <memory> 
#include <stdexcept> 
#include "EmployeeClass.h"
#include "ActualHeader.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void SortBySalary(std::unique_ptr<Employee* []>& record, bool& is_ascending, int& number_of_objects) {
	//implementing selection sort algorithm to sort records in ascending or descending order
	bool correct_order = false;

	do {
		correct_order = true;
		
		//the the help of startIndex we will keep moving the largest or smallest elements
		//to the first, second,third position and so on
		for (auto startIndex = 0; startIndex < number_of_objects; startIndex++) {
			auto smallestFound = startIndex, greatestFound = startIndex;

			//comparing the smallest element found with elements from the right 
			for (auto newNum = startIndex + 1; newNum < number_of_objects; newNum++) {
				if (is_ascending == true) {
					if(record[smallestFound]->GetSalary() > record[newNum]->GetSalary())
						smallestFound = newNum;		
				}
				else { //comparing the greatest element found with elements from the right 
					if (record[greatestFound]->GetSalary() < record[newNum]->GetSalary())
						greatestFound = newNum;
				}
			}          
			(is_ascending == true) ? std::swap(record[startIndex], record[smallestFound])
				: std::swap(record[startIndex], record[greatestFound]);
			//swapping the elements/records 
		}

	} while (correct_order == false);
}

void sortID(std::unique_ptr<Employee* []>& record, bool &is_ascending, int& number_of_objects) {
	//implementing Bubblesort algorithm to sort the records in ascending/descending order

	//sorting an array of pointers that point to unique objects of class employee
	//two optimizations were made : i < number_of_objects - i - 1 and correctOrder
	bool correctOrder = false;
	do {
		correctOrder = true;  //if this boolean remains true, we will exit the do while loop
		for (auto i = 0; i < number_of_objects - i; i++) {
			Employee* temp = nullptr;  //creating a temporary ptr to help us swap the records

			if (is_ascending == true) {
				if (record[i]->getID() > record[i + 1]->getID()) {                     
					temp = record[i + 1];  //swapping the records by using the temp ptr
					record[i + 1] = record[i];
					record[i] = temp;
					correctOrder = false;  //I could have used swap function, but I wanted
					                       //to do the swapping with pointers
				}
			}
			else {
				if (record[i]->getID() < record[i + 1]->getID()) {
					temp = record[i + 1]; 
					record[i + 1] = record[i];
					record[i] = temp;
					correctOrder = false;
				}
			}
		}


	} while (correctOrder == false);

}

void printRecords(std::unique_ptr<Employee* []>& record, int& number_of_objects) {
	for (auto i = 0; i < number_of_objects; i++) {
		record[i]->printContent();  //printing all the records
		cout << "\n";
	}
}

void sortByIDSalary(std::unique_ptr<Employee* []>& record, int& number_of_objects){
	system("cls");
	cout << "You have two options, you can sort the records through the ID's\n";
	cout << "Or you can choose to sort them by using the salaries of the employees\n";
	cout << "1.Use the ID's 2.Use the salaries\n";
	int user_choice = 0;
	CheckIfInputInteger(user_choice);  //checking again to see if input is integer
	bool is_ascending = true;
	int choose_Id_order = 0, correct_input = true, choose_salary_order = 0;

	//depending on the user input, one of this cases will execute
	switch (user_choice) {
	case 1:  //sorting by id
		system("cls");
		cout << "This is the list with all the records: \n";
		printRecords(record, number_of_objects);
		cout << "\nThese records can be sorted in ascending or descending order, order determined\n";
		cout << "by the ID number\n";
		
		do {
			cout << "1.Ascending order 2.Descending order\n";
			cin >> choose_Id_order;

			if (choose_Id_order == 1) {  //if input is 1, execute first case
				sortID(record, is_ascending, number_of_objects);
				correct_input = true;
			}
			else if (choose_Id_order == 2) { //if input is 2, execute second case
				is_ascending = false;
				sortID(record, is_ascending, number_of_objects);
				correct_input = true;
			}
			else { //if wrong input, prompt the user to input again
				system("cls");
				cout << "Wrong input try again!";
				correct_input = false;
			}
		} while (!correct_input);
			break;
	case 2: //sorting by salary
		system("cls");
		cout << "This is the list with all the records: \n";
		printRecords(record, number_of_objects);
		cout << "\nThese records can be sorted in ascending or descending order, order determined\n";
		cout << "by how high the salary is\n";

		do {
			cout << "1.Ascending order 2.Descending order\n";
			cin >> choose_salary_order;
			
			if (choose_salary_order == 1) {
				SortBySalary(record, is_ascending, number_of_objects);
				correct_input = true;
			}
			else if (choose_salary_order == 2) {
				is_ascending = false;
				SortBySalary(record, is_ascending, number_of_objects);
				correct_input = true;
			}
			else {
				//if wrong input, prompt the user to input again
				system("cls");
				cout << "Wrong input try again!";
				correct_input = false;
			}
			
		} while (!correct_input);
		break;
	default:
		cout << "Could not sort the records, wrong input"; 
		exit(0);
	}

	system("cls");
	cout << "Here is the record list after the modifications: \n";
	printRecords(record, number_of_objects);

}