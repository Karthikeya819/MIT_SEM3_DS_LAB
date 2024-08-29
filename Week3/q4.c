/*
Implement a C program to read, display and to find the product of two matrices using
functions with suitable parameters. Note that the matrices should be created using
dynamic memory allocation functions and the elements are accessed using array
dereferencing.
*/
#include <stdio.h>
#include <stdlib.h>

void multiply(int m,int n,int **MatA,int m1,int n1,int **MatB){
	if(n!=m1){
		printf("Matrice's aren't compatible for Multiplication!");
		return;
	}
	int MatC[m][n1];
	for(int i=0;i<m;i++){
		for(int j=0;j<n1;j++){
			MatC[i][j] = 0;
			for(int k=0;k<n;k++){
				MatC[i][j] += MatA[i][k] * MatB[k][j];
			}
			printf("%d ",MatC[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int m,n,m1,n1;
	printf("Enter M :");
	scanf("%d",&m);
	printf("Enter N: ");
	scanf("%d",&n);
	int **MatA = (int**)malloc(m*sizeof(int));
	for(int i=0;i<m;i++){
		MatA[i] = (int*)malloc(n*sizeof(int));
		for(int j=0;j<n;j++){
			printf("Enter Element at (%d,%d) of MatA :",(i+1),(j+1));
			scanf("%d",&MatA[i][j]);
		}
	}
	printf("Enter M1 :");
	scanf("%d",&m1);
	printf("Enter N1: ");
	scanf("%d",&n1);
	int **MatB = (int**)malloc(m1*sizeof(int));
	for(int i=0;i<m1;i++){
		MatB[i] = (int*)malloc(n1*sizeof(int));
		for(int j=0;j<n1;j++){
			printf("Enter Element at (%d,%d) of MatB :",(i+1),(j+1));
			scanf("%d",&MatB[i][j]);
		}
	}
	multiply(m,n,MatA,m1,n1,MatB);
}