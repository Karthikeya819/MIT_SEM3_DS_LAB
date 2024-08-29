/*
Write a C program to
a) Demonstrate passing pointers to a function.
b) Demonstrate Returning pointer from a function.
c) c) Using pointer to pointer.
*/

#include <stdio.h>

void RecivePointer(int* num){
	printf("Recived %d in Pointer Format! \n",*num);
}
int* SendmePointer(int* num){
	return num;
}

int main(){
	int a = 819;
	int *apoin = &a;
	RecivePointer(apoin);
	int* Reciv = SendmePointer(apoin);
	printf("Recived Pointer from Function %p ! \n",Reciv);
	int **p2p = &apoin;
	printf("Assigned Pointer to Pointer! %p \n",p2p);

	return 0;
}