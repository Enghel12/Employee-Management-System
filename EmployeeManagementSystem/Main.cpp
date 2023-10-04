#include <iostream> //library that enables us to use cout, cin, endl..
#include <memory> //for the smart pointers
#include <stdexcept>//library that allows us to use expections
#include "ActualHeader.h"
#include "EmployeeClass.h"
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;

//declaration of an abstract class
class AbstractPromotion {
	virtual void PromotionMessage() = 0;
};

//Child class of class Employee
class PromoteEmployees : Employee, AbstractPromotion{
public:
	PromoteEmployees(int ID, std::string name, int age, int salary, std::string position)
		:Employee(ID, name, age, salary, position)  //using our parent class constructor
	{}

	bool Promote(int employee_age, int employee_salary) {
		//determining if the employee will be promoted
		if (employee_age < 25) {
			cout << "Employee cannot be promoted\n";
			return false;
		}
		else if (employee_age > 25 && employee_salary < 3000) { 
			cout << "Promoting the employee...\n";
			return true;
		}
		else if (employee_age > 30 && employee_salary < 4000) { 
			cout << "Promoting the employee...\n";
			return true;
		}
		else if (employee_age > 40) {
			cout << "Why does this employee still work at the same company after so many years!\n";
			cout << "Promoting him/her right now...\n";
			cout << "\nPress anything to continue\n";
			string continueIt = "";
			cin >> continueIt;
			return true;
		}
	 return false;
	}

	//implementing the definition of the virtual function
	void PromotionMessage() {
		system("cls");
		cout << "The employee has been promoted successfully!\n";
		cout << "Press anything to continue: \n";
		std::cin.get();
	}
};



//Second project
int main()
{

	//variables that we neeed for each record/unique object
	int ID = 0, age = 0, salary = 0;
	string employee_name = "", company_position = "";
	int user_input = 0, array_position = -1, number_of_objects = 0;
	char which_type = ' ';
	bool found = false;
	
	cout << "Welcome to the beta version of Employee Management System\n";
	cout << "To store a new record/employee in the data base press 1, or any other number to exit\n";

	//calling this function to check if input is integer
	CheckIfInputInteger(user_input);
	
	if (user_input != 1) return 1;
	system("cls");

	//Creating an unique pointer Records that that now owns the array of our employee pointers
	std::unique_ptr<Employee* []> Records = std::make_unique<Employee*[]>(100);
	
	
	//using a do while loop to keep storing new records until the user decides to stop
	do {
		array_position++;
		number_of_objects++;
		//passing arguments by refference to avoid copying
		CreateRecord(&ID, &employee_name, &age, &salary, &company_position);

		//Here we use each pointer of our array of pointers and give them the addresses of the
		//objects of class employee
		Records[array_position] = new Employee(ID, employee_name, age, salary, company_position);
		
		cout << "Would you like to store a different record? 1.For yes 2.For no \n";
		
		//checking again to see if input is integer
		CheckIfInputInteger(user_input);
		

	} while(user_input != 2);
	
	//2.Using the function ReadContent to pass in the addres of an unique_ptr stored in our unique
	//ptr Records
	ReadContent(Records, number_of_objects);	

	//3.this block of code will give the user the choice to update the records
	cout << "Would you like to update a record ? 1.Yes 2.No\n";
	int justUserInput = 0;
	CheckIfInputInteger(justUserInput);

	if(justUserInput == 1)
	UpdateRecord(Records, number_of_objects);

	//4.this part is responsible for deleting an employee record
	cout << "Would you like to delete a record? 1.Yes 2.No\n";
	int choose = 0;
	cin >> choose;

	while(choose == 1 && number_of_objects > 0) {
		system("cls");

		deleteRecord(Records, number_of_objects); //calling the function if we can delete records
		cout << "\nWould you like to delete another record ? 0.No 1.Yes\n";
		cin >> choose;

		//checking to see if we have any records left by trying to catch an exception
		try {
			if (number_of_objects == 0)
				throw std::runtime_error("Cannot delete an empty record list!");
			//here we use this in case there are no records left to be deleted
		}
		catch (const std::exception& e) {
			system("cls");
			std::cerr << "Error : " << e.what() << "\n"; //using e.what to print the exception caught
			choose = 1; //variables becomes 1 so that we exit the loop because we can't delete
			//records anymore
		}
	}

	//5.Sorting the records of the employees
	cout << "Would you like to sort the records? 1.Yes 2.No\n";
	int chooseToSort = 0;
	CheckIfInputInteger(chooseToSort);

	if (chooseToSort == 1) {
		sortByIDSalary(Records, number_of_objects);
	}

	//After the record of employees has been modified for the last time, we will use
	//the function SaveToFile to store the record of the employees to a notepad file
	system("cls");
	cout << "Press 1 if you want to save the record of the employees or anything else if not\n";
	int save = 0;
	cin >> save;
	if (save == 1) {
		system("cls");
		saveToFile(Records, number_of_objects);  //saving the records to a notepad file
	}

	//6.Giving the user the possibility to promote an employee
	cout << "Would you like to promote an employee? 1.Yes 2.No\n";
	int chooseToPromote = 0;
	CheckIfInputInteger(chooseToPromote);

	if (chooseToPromote == 1) {  //if input = yes check to see if an employee is promoted
		system("cls");
		int id_number = 0;
		cout << "Enter the ID to find the employee that you want to promote: \n";
		cin >> id_number;

		system("cls");
		//searching for the id
		for (auto i = 0; i < number_of_objects; i++) {
			if (id_number == Records[i]->getID()) {
				cout << "\nEmployee found \n\n";
				cout << "Press anything to see the employee\n";
				string continueIt = "";  //name: continueIt bacause it prompts the user
				cin >> continueIt;       //to just continue with the input

				system("cls");
				found = true;
				Records[i]->printContent();  //printing that record
				cout << "Press anything to continue\n";
				string continueAgain = "";
				cin >> continueAgain;
				
			//creating a pointer of child class so that we can use a method of that class
				PromoteEmployees* CheckForPromotion = new PromoteEmployees(0,"",0,0,"");
				//accessing that method via pointer
				bool outcome = CheckForPromotion->Promote(Records[i]->getAge(), Records[i]->GetSalary());

				if (outcome == true) { //if the employee got promoted
					CheckForPromotion->PromotionMessage();  //accesing the virtual function
					delete CheckForPromotion; //feering the memory occupied by the pointer
					string continueIt = "";
					cin >> continueIt;
					break;
				}                     
				else if(outcome == false) {
					cout << "\nThis employee was not promoted :[\n";
					cout << "Press anything to continue : \n";
					string continueIt = "";
					cin >> continueIt;
					break;
				}
			}
		}
		if(!found) {
			cout << "The employee does not exist, try again later!";
			exit(0);
		}
	}
	system("cls");

	//7.Adding the salaries of all the employees
	cout << "Would you like to see how much money does the company have to invest\n";
	cout << "So that every single employee is paid(the sum of all salaries of employees\n";
	cout << "1.Yes 2.No\n";

	int choose_to_see = 0;
	cin >> choose_to_see;
	addSalaries(Records, number_of_objects);
	cout << "Press any number to continue\n";
	cin >> choose_to_see;

	system("cls");

	cout << "\n\nThank you for using this program!\n";
	cout << "Press anything to exit: \n";
	std::cin.get();
	system("cls");
	for(auto i =0; i < 1000; i++)
		cout << "\n         Exitting....       ";


	//end of program

	return 0;
}