#include <stdio.h>
#include <ctype.h>
#include "calc.h"

double variables[26];
int curloc=0;
	
/* getop: получает следующий оператор или операнд */
int getop(char s[], char string[])
{
	int i=0, c, sum, j;
	
	while ((s[0] = c = string[curloc++]) == ' ' || c == '\t')
		;
	
	s[1] = '\0';
	
	if (!isdigit(c) && c!= '.'){
		if (c == '-'){
			s[0] = '-';
		}
		else if (c == '='){
			if (islower(j = string[curloc++]))	{	
				variables[j-'a']=pop();
				push(variables[j-'a']);
				return VARIB;
			}
			else
				curloc--;
		}
		
		else if (islower(c)){
			sum = c;
			while (islower(j = string[curloc++]))
				sum += j;
			curloc--;
			
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
	while (isdigit(s[++i] = c = string[curloc++]))
		;
	
	if (c == '.') /* накапливаем дробную часть */
		while (isdigit(s[++i] = c = string[curloc++]))
		;

	s[i] = '\0';
	
	if (c != EOF)
		curloc--;
	
	if (i == 1 && s[0] == '-') //числа после знака не было
		return '-';
		
	return NUMBER;
}