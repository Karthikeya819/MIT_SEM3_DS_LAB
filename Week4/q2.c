/*
Write a C program to implement the following functions. Use pointers and
dynamic memory management functions.
i. To read one Student object where Student is a structure with name, roll
number and CGPA as the data members
ii. To display one Student object
iii. To sort an array of Student structures according to the roll number.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char Name[20];
	int RollNumber;
	float Cgpa;
}Student;

void ReadData(Student *c){
	printf("Enter Student Name: ");
	scanf("%s",c->Name);
	printf("Enter Student Roll Number: ");
	scanf("%d",&c->RollNumber);
	printf("Enter Student Cgpa: ");
	scanf("%f",&c->Cgpa);
}
void DisplayData(Student *c){
	printf("Student Name: %s \n",c->Name);
	printf("Student RollNumber: %d \n",c->RollNumber);
	printf("Student Cgpa: %f \n",c->Cgpa);
}

void SortData(Student* c[],int N){
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(c[i]->RollNumber > c[j]->RollNumber){
				Student temp = *c[j];
				*c[j] = *c[i];
				*c[i] = temp;
			}
		}
	}

}

int main(){
	int N;
	printf("Enter No of Students: ");
	scanf("%d",&N);

	Student** students = (Student**)calloc(N,sizeof(Student));

	for(int i =0;i<N;i++){
		students[i] = (Student*)malloc(sizeof(Student));
		ReadData(students[i]);
	}
	SortData(students,N);
	printf("Sorted Data: \n");
	for(int i =0;i<N;i++){
		DisplayData(students[i]);
	}

	return 0;
}