#include <stdio.h>
#define LEN 10

void reverse(char[],int);

void main(){
	
	int i;
	char string1[LEN] = {'a','b','c','d','e','5','3','z','2','!'};
	
	reverse(string1,LEN-1);
	
	for (i=0; i<LEN; i++)
		putchar(string1[i]);
	
}

void reverse(char s[],int len){
	
	static int i=0;
	int temp;
	
	temp=s[i];
	s[i++] = s[len];
	s[len] = temp;
	
	if (i<len)
		reverse(s, (len-1));	
}