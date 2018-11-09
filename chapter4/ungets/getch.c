#include <stdio.h>
#include "gets.h"

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
