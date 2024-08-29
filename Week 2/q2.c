#include <stdio.h>
#include <string.h>

void isPalindrome(char word[],int i){
	int len = strlen(word);
	if(i == len-1){
		printf("It's a Palindrome");
		return;
	}
	if(word[i] != word[len-i-2]){
		printf("It's not a Palindrome");
		return;
	}
	isPalindrome(word,++i);
}
int main(){
	char word[100];
	printf("Enter a Word:- ");
	fgets(word,sizeof(word),stdin);
	isPalindrome(word,0);
	return 0;
}