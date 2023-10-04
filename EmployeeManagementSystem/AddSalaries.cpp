#include <iostream> 
#include <memory> 
#include <stdexcept>
#include "ActualHeader.h"
#include "EmployeeClass.h"

int addSalaries(std::unique_ptr<Employee* []>& record, int& number_of_objects) {
	int sum = 0;
	for (auto i = 0; i < number_of_objects; i++) {
		sum += record[i]->GetSalary();  //adding the salaries of the employees
	}

	return sum;
}