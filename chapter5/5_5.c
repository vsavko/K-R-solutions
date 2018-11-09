#include <stdio.h>
#include <string.h>
#include <windows.h>

void strncat1(char *t, char *s, int n)
{
	int i;
	for (i = strlen(s); n-- != 0 && (*(s+i) = *t++) != '\0'; i++);
	*(s+i) = '\0';
}

void strncpy1(char *t, char *s, int n)
{
	int i,counter;
	for (counter=0; *(t+counter) != 0; counter++);
	for (i = 0; n-- != 0; i++)
		*(s+i) = ((*t) != '\0') ? *t++ : *t;
	if (n>counter) 
		*(s+i)= '\0';
}

int strncmp1(char *t, char *s, int n)
{
	for (;*t && n-1 && *s; *t++, n--, *s++);
	
	printf("%c %c %d ", *t, *s, n);
	
		if ((*t == '\0' && *s == '\0') || (*t != '\0' && *s != '\0'))
			return 0;
		else if(*t == '\0' && *s != '\0')
			return -1;
		else
			return 1;	
}

void main(){
	int i;
	char mess1[10] = "bgf";
	char mess2[10] = "11546456";
	
	printf("%d",strncmp1(mess1,mess2,3));
}