/* 
	filename: emp.h 
	this file contains definition of an employee structure and
	declaration of employee functionalities
-----------------------------------------------------------------------*/

#ifndef __EMP_H
#define __EMP_H

//employee structure definition
typedef struct employee
{
	int empid;
	char name[32];
	float salary;
}emp_t;

//declaration of employee functionalities
void accept_employee_record(emp_t *pe);
void display_employee_record(emp_t *pe);


#endif

