#include <stdio.h>
#include "gets.h"

void main(){
	char string[MAXLINE];
	getline(string, MAXLINE);
	ungets(string);
	printf("%c",getch());
	printf("%c",getch());
}