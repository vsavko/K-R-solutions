#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define TABSTOP 8
#define MAXBUFFER 100

void entab(int[]);
int getnumber(char[], int);
int getch1(int *);
int spacestotab(int [], int);
int stop_tab[MAXBUFFER];

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void main(int argc, char *argv[])
{
	int i, j, m=0, n=0, z=0;
	j=argc;

	for (i=0; j-- > 0; ++i){
		if (isdigit(*argv[i])){
			stop_tab[z]=getnumber(argv[i],MAXBUFFER);
			++z;
		}
		else if (strcmp(argv[i],"entab") == 0){
			if (*argv[i+1]=='-' && *argv[i+2]=='+'){
				m = getnumber(++argv[i+1],MAXBUFFER);
				n = getnumber(++argv[i+2],MAXBUFFER);	
					i += 2;
					j -= 2;
			}	
		}
	}
	
	if (m >= 0 && n>0){
		for (j=1; z < MAXBUFFER; ++j, ++z){
			stop_tab[z] = m + n*j;	
		}
		qsort(stop_tab,MAXBUFFER-1,sizeof(int),cmpfunc);
	}
	
	/*for (i=0; i<MAXBUFFER; ++i)
		printf("%d ",stop_tab[i]);*/
	
		//printf("\n");
		
	stop_tab[MAXBUFFER-1]='\0';	
	entab(stop_tab);
}

void entab(int stop_tab[])
{
	int static out[1000];
	int cursor=0, totab, c, i=0 ,j,tabcount,spaces,z=0, zz, t=1 ,spacenr=0 ,spcnt1, *spcnt;
	int count2=0;
	
	spcnt=&spcnt1;
	*spcnt=0;
	
	while ((c=getch1(spcnt)) != '\n') {
				
		if (c=='\t' && (stop_tab[0] != '\0') ){
			*spcnt=spacestotab(stop_tab, count2);
			c=getch1(spcnt);
		}
		
		++count2;
		
		if (c!=' '){
			
			if (spacenr>0){ //если вышли из пробелов и они были до этого
			
				if (spacenr<totab)
					for (i=0;i<spacenr;++i)
					putchar(' ');
				else if (spacenr==totab)
					putchar('\t');
				else{
					putchar('\t');
					tabcount=(spacenr-totab)/TABSTOP;
					
					for (i=0;i<tabcount;++i)
					putchar('\t');	
				
					spaces=(spacenr-totab)-tabcount*TABSTOP;
					
					for (i=0;i<spaces;++i)
					putchar(' ');	
				}
				
			//считаем положение курсора и totab
				if (c=='\t')	
					cursor= ((cursor+spacenr)/TABSTOP)*TABSTOP+TABSTOP;
				else
					cursor=cursor+spacenr+1;
				totab=TABSTOP-(cursor-(cursor/TABSTOP)*TABSTOP);
				
				putchar(c);
				spacenr=0;
			}
			else { //если пробелов не было
				if (c=='\t')	
					cursor= ((cursor)/TABSTOP)*TABSTOP+TABSTOP;
				else
					++cursor;
				totab=TABSTOP-(cursor-(cursor/TABSTOP)*TABSTOP);
			
				putchar(c);
			}
		}
		else
			++spacenr;		
	}
	printf("\n");
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

int getch1(int *spcnt)
{
	if (*spcnt>0){
		--*spcnt;
		return ' ';
	}
	else
		return getchar();
}

int spacestotab(int stop_tab[], int cursor)
{
	int i;
	for (i=0; stop_tab[i] != '\0'; ++i)
		if (cursor < stop_tab[i])
			return stop_tab[i]-cursor;
	return 0;
}