#include <iostream>
#include <memory> 
#include <stdexcept> 

using std::cout;
using std::endl;
using std::cin;
using std::string;

//this function checks if the user enters characters to an integer, catches and exception in that
//case and stops the program
int CheckIfInputInteger(int& user_input) {
	try { //in the try block, we check to see if input is not an int
		if (!(std::cin >> user_input)) { //if input is not an integer, throw an exception 
			throw std::invalid_argument("Invalid input");
		}
	}
	catch (const std::exception& e) { //here if an exception was thrown, it will be caught in this block
		std::cerr << "Error: " << e.what() << endl;  //using e.what to print the caught exception
		exit(0);  //exiting the program
	}
	system("cls");
	return 0; //if input is integer, return 0
}