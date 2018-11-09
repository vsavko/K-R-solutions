#include <stdio.h>
#include <ctype.h>
int getch (void);
void ungetch (int);
int getint(int *);

/* getint: читает следующее целое из ввода в *pn */

void main(){
	
	int lim = 1000, num, test;
	
	while( (test=getint(&num)) != EOF){
		if (test !=0)
			printf("%d %d\n",test,num);
	}

}

int getint(int *pn){
	int c, sign, sign2=0;
	while (isspace(c = getch()))
	; /* пропуск символов-разделителей */

	if (!isdigit(c) && c != EOF && c != '+'&& c != '-') {
		//ungetch (c); /* не число */
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1;
	
	if (c == '+' || c == '-'){
		sign2=c;
		c = getch();
	}
	
	if (isdigit(c)){
		for (*pn = 0; isdigit(c); c = getch())
			*pn = 10 * *pn + (c -'0');
		*pn *= sign;
	}
	else if (sign2 =='+' || sign2 =='-'){
		ungetch(sign2);
		return 0;	
	}
	
	if (c != EOF)
		ungetch(c);

	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) /* взять (возможно возвращенный) символ */
{
	return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c) /* вернуть символ на ввод */
{
if (bufp >= BUFSIZE)
	printf("ungetch: too many symbols\n");
else
	buf[bufp++] = c;
}