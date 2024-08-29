/* To copy one string to another using Recursion. */

#include <stdio.h>
void copyString(char str1[],char str2[],int i){
	if(str1[i] == '\0'){
		return;
	}
	str2[i] = str1[i];
	copyString(str1,str2,++i);
}
int main(){
	char str1[100],str2[100];
	printf("Enter String :-");
	scanf("%s",str1);
	copyString(str1,str2,0);
	printf("str2 is %s \n",str2);
	return 0;
}