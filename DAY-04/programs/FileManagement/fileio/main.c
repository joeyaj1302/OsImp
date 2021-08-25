/* 
	filename: main.c
	this file contains main() function
----------------------------------------------*/

/* file inclusion section */
#include<stdio.h>
#include<unistd.h>
#include"emp.h"
#include"functions.h"

/* global declaration section */
enum menu_options{ 	EXIT, ACCEPT_RECORD, DISPLAY_RECORD, WRITE_RECORD,
					READ_RECORDS, UPDATE_RECORD, DELETE_RECORD };

int menu(void)
{
	int choice;

	printf("fileio operations\n");
	printf("0. exit\n");
	printf("1. accept employee record\n");
	printf("2. display employee record\n");
	printf("3. write employee record into the file\n");
	printf("4. read all employee records from the file\n");
	printf("5. update employee record\n");
	printf("6. delete employee record\n");

	printf("enter the choice: ");
	scanf("%d", &choice);

	return choice;
}

int main(void)
{
	int choice;
	emp_t emp;

	while(1)
	{
		choice = menu();
		switch(choice)
		{
			case EXIT: _exit(0);
			case ACCEPT_RECORD: 
				accept_employee_record(&emp);
				break;
				
			case DISPLAY_RECORD:
				printf("%-10s %-20s %-10s\n", "empid", "name", "salary");
				display_employee_record(&emp);
				break;
				
			case WRITE_RECORD:
				write_record(&emp);
				break;
				
			case READ_RECORDS:
				read_records();
				break;
				
			case UPDATE_RECORD:
				if( update_record() )
					printf("record updated successfully...\n!!!");
				else
					printf("record not found !!!\n");
				break;

			case DELETE_RECORD:
				delete_record();
				break;
		}//end of switch control block

	}//end of while loop

	return 0;
}

/* global declaration section */
