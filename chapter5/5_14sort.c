#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000 /* максимальное число строк */

char *lineptr[MAXLINES]; /* указатели на строки текста */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort1(void *lineptr[], int left, int right, int (*comp)(void *, void *), int ascending);
int numcmp(char *, char *);
/* сортировка строк */

main(int argc, char *argv[])
{
	int nlines; /* количество прочитанных строк */
	int numeric = 0; /* 1, если сорт. по числ. знач. */
	int sort2 = 1; 
	
	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	
	if (argc > 2 && strcmp(argv[2], "-r") == 0 )
		sort2 = 0;

	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
			qsort1((void **) lineptr, 0, nlines-1,(int (*)(void*,void*))(numeric ? numcmp : strcmp), sort2);
		
		writelines(lineptr, nlines);
		return 0;
	} 
	else {
		printf("Bведено слишком много строк\n");
		return 1;
	}
}

#define ALLOCSIZE 10000 /* размер доступного пространства */
static char allocbuf[ALLOCSIZE]; /* память для alloc */
static char *allocp = allocbuf; /* указатель на своб. место */
char *alloc(int n) /* возвращает указатель на n символов */

{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n; /* пространство есть */
		return allocp - n; /* старое p */
	} 
	else /* пространства нет */
		return 0;
}
void afree(char *p) /* освобождает память, на которую указывает p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

void qsort1(void *v[], int left, int right, int (*comp)(void *, void *), int ascending)
{
	int i, last;
	void swap(void *v[], int, int);
	
	if (left >= right) /* ничего не делается, если */
		return; /* в массиве менее двух элементов */
		
	swap(v, left, (left + right)/2);
	last = left;
	
	for (i = left+1; i <= right; i++)
		if (ascending == 1)
		{
			if ((*comp)(v[i], v[left]) < 0)
				swap(v, ++last, i);
		}
		else
		{
			if ((*comp)(v[i], v[left]) > 0)
				swap(v, ++last, i);
		}
		
	swap(v, left, last);
	
	qsort1(v, left, last-1, comp, ascending);
	qsort1(v, last+1, right, comp, ascending);
}

/* numcmp: сравнивает s1 и s2 как числа */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* getline: читает строку в s, возвращает длину */
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') /* I.B.: misprint washere -lim instead of --lim */
		s[i++] = c;
		
	if (c == '\n')
		s[i++] = c;
	
	s[i] = '\0';
	return i;
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLINES];
	nlines = 0;
	
	while ((len = getline(line, MAXLINES)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
		return -1;
	else {
		line[len-1] = '\0'; /* убираем символ \n */
		strcpy(p, line);
		lineptr[nlines++] = p;
	}
	return nlines;
}

/* writelines: печать строк */
void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}