#include <stdio.h>
#include <string.h>
#define text(message) printf("%d",message)

int strend(char *s,char *t);

void main(){
	char *mess="12345";
	char *mess2="4";	
	text(strend(mess,mess2));
}


int strend(char *s,char *t) {
	int i;
	for (i=strlen(s)-strlen(t); *(s+i) == *(t++); i++)
		;
	if (*(s+i-1) == '\0')
		return 1;
	else 
		return 0;
}
