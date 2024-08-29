/*
Write a function Reverse to reverse the elements of an integer array using pointer.
Access the elements of the array using dereference operator. Read the values from
the keyboard in main function. Display the result in the main function.
*/
#include <stdio.h>

void Reverse(int Arr[],int N){
	for(int i = 0;i<(N/2);i++){
		int temp = *(Arr+i);
		*(Arr+i) = *(Arr+(N-i-1));
		*(Arr+(N-i-1)) = temp;
	}
}

int main(){
	int N;
	printf("Enter No of Elements:");
	scanf("%d",&N);
	int Arr[N];
	for(int i=0;i<N;i++){
		printf("Enter %d Element: ",(i+1));
		scanf("%d",&Arr[i]);
	}
	Reverse(Arr,N);
	for(int i=0;i<N;i++){
		if(i == N-1)printf("%d \n",Arr[i]);
		else printf("%d,",Arr[i]);
	}

	return 0;
}