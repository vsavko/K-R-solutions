#include <stdio.h>
/* печать таблицы температур по Фаренгейту и Цельсию */

#define IN 1 /* внутри слова */
#define OUT 0 /* вне слова */
/* подсчет строк, слов и символов */
main()
{
int c,state;
state=IN;
while ((c=getchar())!=EOF){
	if (c==' ' || c=='\t')
		state=OUT;
	else if (state==OUT){
		state=IN;
		putchar('\n');
		putchar(c);
		}
	else 
		putchar(c);
	}	

}
