#include <stdio.h>

void firstCapital(char str[],int i){
	printf("%d",i);
	if(str[i] == '\n'){
		printf("No capital Letter found!");
		return;
	}
	if(str[i] < 60){
		printf("Found First Capital%c",str[i]);
		return;
	}
	firstCapital(str,++i);
}

int main(){
	char str[100];
	printf("Enter Word:- ");
	fgets(str,sizeof(str),stdin);
	firstCapital(str,0);

	
	return 0;
}