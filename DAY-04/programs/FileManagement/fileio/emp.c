/* 
	filename: emp.c
	this file contains definitions of employee functionalities
----------------------------------------------------------------------*/

#include"emp.h"
#include<stdio.h>

void accept_employee_record(emp_t *pe)
{
	printf("enter empid, name & salary: ");
	scanf("%d %s %f", &pe->empid, pe->name, &pe->salary);
}

void display_employee_record(emp_t *pe)
{
	printf("%-10d %-20s %-10.2f\n", pe->empid, pe->name, pe->salary);
}

