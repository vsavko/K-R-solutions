#include <stdio.h>
#include <ctype.h>
#include "calc.h"

double variables[26];
int get(int c);
static int unget;
	
/* getop: получает следующий оператор или операнд */
int getop(char s[])
{
	int i=0, c, sum, j;
	
	while ((s[0] = c = get(unget)) == ' ' || c == '\t')
		;
	s[1] = '\0';
	
	//((unget != 0) ? unget: getar());
	
	if (!isdigit(c) && c!= '.'){
		if (c == '-'){
			s[0] = '-';
		}
		else if (c == '='){
			if (islower(j = get(unget)))	{	
				variables[j-'a']=pop();
				push(variables[j-'a']);
				return VARIB;
			}
			else
				unget =j;
		}
		
		else if (islower(c)){
			sum = c;
			while (islower(j = get(unget)))
				sum += j;
			unget =j;
			
			if (sum == c && variables[c -'a'] != '\0') {
				push(variables[c -'a']);
				return VARIB; //выдаем переменную
			}
			
			switch (sum){
				case ('o'+'u'+'t'): //команда output
					return OUT;	
				case ('d'+'u'+'b'): //команда dublicate
					return DUB;
				case ('s'+'w'+'h'): //команда switch
					return SWH;
				case ('c'+'l'+'s'): //команда clear stack
					return CLS;
				case ('s'+'i'+'n'): //команда sin
					return SIN;
				case ('c'+'o'+'s'): //команда cos
					return COS;
				case ('e'+'x'+'p'): //команда cos
					return EXP;
				case ('p'+'o'+'w'): //команда pow
					return POW;
				default:
					 return c;/* не число */
			}
		}
		else 
			return c;
	}
	
	/* накапливаем целую часть */
	while (isdigit(s[++i] = c = get(unget)))
		;
	
	if (c == '.') /* накапливаем дробную часть */
		while (isdigit(s[++i] = c = get(unget)))
		;

	s[i] = '\0';
	
	if (c != EOF)
		unget =c;
	
	if (i == 1 && s[0] == '-') //числа после знака не было
		return '-';
		
	return NUMBER;
}


int get(int c) /* взять (возможно возвращенный) символ */
{
	if (c != 0){
		unget = 0;
		return c;
	}
	else 
		return getchar();
}