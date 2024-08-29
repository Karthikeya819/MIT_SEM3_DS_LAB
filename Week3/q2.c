/*
Write a function Smallest to find the smallest element in an array using pointer.
Create a dynamically allocated array and read the values from keyboard in main.
Display the result in the main function.
*/

#include <stdio.h>
#include <stdlib.h>

int smallest(int Arr[],int N){
	int small = 0;
	for(int i =1;i<N;i++){
		if(Arr[i] < Arr[small])small=i;
	}
	return Arr[small];
}

int main(){
	int N;
	printf("Enter No of Elements :");
	scanf("%d",&N);
	int* Arr = (int*) malloc(N*sizeof(int));
	for(int i =0;i<N;i++){
		printf("Enter %d Element :",(i+1));
		scanf("%d",&Arr[i]);
	}
	int small = smallest(Arr,N);
	printf("Smallest Element is %d \n",small);

	return 0;
}