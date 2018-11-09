#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFLEN 10000
#define NUMOFSTRINGS 1000

int tail(char *[], int);
int getnumber(char [], int);

void main(int argc, char *argv[])
{	
	int n=3;
	int x, numb_line=0,i;
	char *ptr[NUMOFSTRINGS];
	
	for (i=0; argc-->0; i++)
		if (strcmp(argv[i],"tail") == 0){
			if (*argv[i+1]=='-'){
				n = getnumber(++argv[i+1],NUMOFSTRINGS);	
				break;
			}
		}
	
	while ((x = tail(ptr,NUMOFSTRINGS)) != 0)
		++numb_line;
	
	if (numb_line>0)
		for (i=numb_line-n; i <= numb_line-1; ++i)
			if (i >= 0)
				printf("line: %d %s\n",i,ptr[i]);
	
}

int tail (char *ptr[], int numofstrings)
{
	static int number_chars=0, i=0;
	char c;
	static char buffer[BUFLEN];
	
	if (i<numofstrings)
		ptr[i++] = &buffer[number_chars];
	else
		return '\0';
	
	while ((c=getchar()) != '\n' && c != EOF &&  number_chars < BUFLEN )
		buffer[number_chars++] = c;
	
	if (c == EOF)
		return '\0';
	else
		buffer[number_chars++]='\0';
	
	return number_chars; //возвращает количество элементов в массиве символов
}

int getnumber(char c[], int maxbuffer)
{
	char text[maxbuffer];
	int i=0, j=0;
	
	while (isdigit(c[j]))
	{
		i = (i*10 +c[j]-'0');
		++j;	
	}	
	return i;
}