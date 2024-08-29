/*
Implement Complex numbers using structures. Write functions to add, multiply,
subtract two complex numbers.
*/
#include <stdio.h>

typedef struct{
	float i;
	float j;
}Complex;

Complex AddComplex(Complex a,Complex b){
	Complex c;
	c.i = a.i + b.i;
	c.j = a.j + b.j;
	return c;
}
Complex SubstractComplex(Complex a,Complex b){
	Complex c;
	c.i = a.i - b.i;
	c.j = a.j - b.j;
	return c;
}
Complex MultiplyComplex(Complex a,Complex b){
	Complex c;
	c.i = (a.i*b.i) - (a.j*b.j);
	c.j = (a.i*b.j) + (a.j*b.i);
	return c;
}

int main(){
	Complex a,b,c;
	printf("Enter C1 i: ");
	scanf("%f",&a.i);
	printf("Enter C1 j: ");
	scanf("%f",&a.j);
	printf("Enter C2 i: ");
	scanf("%f",&b.i);
	printf("Enter C2 j: ");
	scanf("%f",&b.j);

	c = AddComplex(a,b);
	printf("Addition of C1,C2 is %f +i%f \n",c.i,c.j);
	c = SubstractComplex(a,b);
	printf("Substraction of C1,C2 is %f +i%f \n",c.i,c.j);
	c = MultiplyComplex(a,b);
	printf("Multiplication of C1,C2 is %f +i%f \n",c.i,c.j);

	return 0;
}