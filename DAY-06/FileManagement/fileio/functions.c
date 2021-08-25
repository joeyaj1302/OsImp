/* 
	filename: functions.c
	this file contains definitions of fileio functions
----------------------------------------------------------*/

#include<stdio.h>
#include"functions.h"
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

void write_record(emp_t *pe)
{
	//to open a file or to create a new file
	int fd = open("empdb.db", O_CREAT|O_RDWR|O_APPEND, 0644);
	if( fd == -1 )
	{
		perror("open() failed !!!\n");
		_exit(1);
	}

	//write a record into the file
	write(fd, pe, sizeof(emp_t));
	printf("record inserted into the file successfully....\n");

	//close the file
	close(fd);
}

void read_records(void)
{
	emp_t e;
	//open a file for read only purpose
	int fd = open("empdb.db", O_RDONLY);
	if( fd == -1 )
	{
		perror("open() failed !!!\n");
		_exit(1);
	}

	//read all records from file one by one and display
	while( read(fd, &e, sizeof(emp_t)) > 0 )
	{
		display_employee_record(&e);
	}

	//close the file
	close(fd);
}

int update_record(void)
{
	int id;
	int fd;
	emp_t e;
	int flag = 0;
	long int offset = sizeof(emp_t);


	//accept an empid of an employee which is to be updated
	printf("enter an id: ");
	scanf("%d", &id);

	//open a file for read as well a write purpose
	fd = open("empdb.db", O_RDWR);
	if( fd == -1 )
	{
		perror("open() failed !!!\n");
		_exit(1);
	}

	//search a record - read all the records one by one sequentially
	while( read(fd, &e, sizeof(emp_t) ) > 0 )
	{
		//if record is found
		if( id == e.empid )
		{
			flag = 1;
			display_employee_record(&e);
			accept_employee_record(&e);
			//reposition the file offset by -40 bytes
			lseek(fd, -offset, SEEK_CUR);
			//overwrite updated record into the file
			write(fd, &e, sizeof(emp_t));
			break;
		}
	}
	//close a file
	close(fd);

	return flag;
}

void delete_record(void)
{
	int fd;
	int fs;
	int id;
	emp_t e;

	printf("enter an empid of an employee which is to be deleted: ");
	scanf("%d", &id);

	//open a src file for read only and create a temp new file for write only
	fd = open("tempdb.db", O_CREAT|O_WRONLY, 0644);
	fs = open("empdb.db", O_RDONLY);
	if( fd == -1 || fs == -1 )
	{
		perror("open() failed !!!\n");
		_exit(1);
	}

	/* read all the records one by one from src file and copy them into dest
	file except record to be deleted */
	while( read(fs, &e, sizeof(emp_t)) > 0 )
	{
		if( e.empid != id )
			write(fd, &e, sizeof(emp_t) );
	}

	//close both the files
	close(fd);
	close(fs);
	//delete src file
	unlink("empdb.db");
	//rename temp file by original filename
	rename("tempdb.db", "empdb.db");
}

