/*
Samuel wants to store the data of his employees, which includes the following fields:
(i) Name of the employee 
(ii) Date of birth which is a collection of {day, month, year}
(iii) Address which is a collection of {house number, zip code and state}. Write a 'C'
program to read and display the data of N employees using pointers to array of
structures.
*/
#include <stdio.h>
#include <string.h>

typedef struct{
	int Dday;
	int Dmonth;
	int Dyear;
}Date;

typedef struct{
	char AHno[10];
	int Azipcode;
	char AState[20];
}Address;

typedef struct{
	char Ename[20];
	Date Edob;
	Address Eaddress;
}Employee;

int main(){
	int N;
	printf("Enter No of Employee's: ");
	scanf("%d",&N);
	Employee employees[N];
	char Ename[20],Hno[10],State[20];
	int day,month,year,zipcode;
	Address add;
	Date date;
	for(int i=0;i<N;i++){
		printf("Enter Employee Name: ");
		scanf("%s",Ename);
		printf("Enter Employee DOB (Day,Month,Year): ");
		scanf("%d,%d,%d",&day,&month,&year);
		printf("Enter Employee Address: \n");
		printf("	Enter House Number: ");
		scanf("%s",Hno);
		printf("	Enter Zipcode: ");
		scanf("%d",&zipcode);
		printf("	Enter State: ");
		scanf("%s",State);
		strcpy(add.AHno , Hno);
		add.Azipcode = zipcode;
		strcpy(add.AState , State);
		date.Dday = day;
		date.Dmonth = month;
		date.Dyear = year;
		strcpy(employees[i].Ename , Ename);
		employees[i].Edob = date;
		employees[i].Eaddress = add;
	}
	for(int i=0;i<N;i++){
		printf("Employee Name: %s \n",employees[i].Ename);
		printf("Employee DOB (Day,Month,Year): (%d,%d,%d) \n",employees[i].Edob.Dday,employees[i].Edob.Dmonth,employees[i].Edob.Dyear);
		printf("Employee Address: %s,%d,%s \n",employees[i].Eaddress.AHno,employees[i].Eaddress.Azipcode,employees[i].Eaddress.AState);	
	}

	return 0;
}