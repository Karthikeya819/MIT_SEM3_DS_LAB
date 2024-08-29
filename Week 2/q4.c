#include <stdio.h>

void selectionSort(int total,int arr[],int i){
	if(total-1 == i){
		return;
	}
	int si = i;
	for(int j = i;j<total;j++){
		if(arr[j] < arr[si])si=j;
	}
	int temp = arr[si];
	arr[si] = arr[i];
	arr[i] = temp;
	selectionSort(total,arr,++i);
}

int main(){
	int arr[] = {4,3,2,1};
	selectionSort(4,arr,0);
	for (int i = 0; i < 4; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}