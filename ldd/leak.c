#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct

{
	char *name;
	int salary;

} Employee;

void print_employee(Employee *emp)
{

	printf("Employee Name: %s\n", emp->name);
	printf("Salary: %d\n", emp->salary);
}

int calculate_average(Employee *emp_list, int count)
{

	int i;
	int total = 0; // UNINITIALIZED VARIABLE
	for(i = 0; i < count; i++) // OFF BY ONE ERROR
	{
		total += emp_list[i].salary;
	}
	return (total/count);
}

int main()
{
	int n = 3;
	int i;
	Employee *employees;
	employees = (Employee *)malloc(sizeof(Employee) * n);
	if(employees == NULL)
	{
		printf("Memory allocation failed\n");
		return -1;
	}
	for(i = 0; i < n; i++)
	{
		employees[i].name = (char *)malloc(10);
		printf("Enter employee name: ");
		//scanf("%s", employees[i].name); // BUFFER OVERFLOW POSSIBLE
		fgets(employees[i].name , 10 , stdin);
		
		printf("Enter salary: ");
		scanf("%d", &employees[i].salary);
		char tmp;
		scanf("%c",&tmp);
	}
	//free(employees[1].name);
	// USE AFTER FREE
	//printf("\nFreed Employee Name: %s\n", employees[1].name);
	for(i = 0; i < n; i++)
	{
		print_employee(&employees[i]);
	}
	int avg = calculate_average(employees, n);
	printf("\nAverage Salary: %d\n", avg);

	// MEMORY LEAK:
	
	for(i = 0; i < n; i++)
        {
                free(employees[i].name);
        }


	// employees[i].name NOT FREED
	
	free(employees);
	return 0;
}

