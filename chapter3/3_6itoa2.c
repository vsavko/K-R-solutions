#include <stdio.h>
#include <string.h>
#include <math.h>
void itoa(int n, char s[], int size);
void reverse(char s[]);

void main(){
	
	int i,x=553648;
	char s[100];
	for (i=0;i<100;++i)
		s[i]=0;
	
	itoa(x,s,11);
	
	for (i=0; s[i]!='\0' ;++i)
		putchar(s[i]);
}

void itoa(int n, char s[], int size)
{
	int i,j, sign;
	
	sign = n;
	
	//if ((sign = n) < 0) /* сохраняем знак */
	//	n =-n; /* делаем n положительным */
		
	i = 0;
	
	do {/* генерируем цифры в обратном порядке */
		s[i++] = fabs(n %10)+ '0'; /* следующая цифра */
	} while (fabs(n /= 10) > 0); /* исключить ее */
	
	if (sign < 0)
		s[i++] = '-';
	
	for (j=i+1; j<=size;++j)
		s[i++] = ' ';
	
	s[i] = '\0';
	reverse(s);
}

/* reverse: переворачивает строку s (результат в s) */
void reverse(char s[])
{
	int c,i,j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}