#include <stdio.h>

void itoa(int, char []);
char string [100];
	
void main(){

	int num = 234345235,i;
	itoa(num, string);
	
	for (i=0; string[i] != 0; i++){
		putchar(string[i]);
	}	
}

void itoa(int number, char string[]){
	
	static int i=0;
	
	if (number/10>0)
		itoa(number/10,string);
	
	string[i++]= number % 10+'0';	
}