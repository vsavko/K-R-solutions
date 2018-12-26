#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main(int argc, char * argv[])
{
	char c;

	if (strcmp(argv[0],"upper.exe") == 0){
		while ((c=getchar()) != EOF)
			putchar(toupper(c));
	}

	else if(strcmp(argv[0],"lower.exe") == 0)
		while ((c=getchar()) != EOF)
			putchar(tolower(c));	
	else
		printf("invalid file name, use either upper.exe or lower.exe");

}