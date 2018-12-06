#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000 /* максимальное число строк */

char *lineptr[MAXLINES]; /* указатели на строки текста */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort1(void *lineptr[], int left, int right, int (*comp)(void *, void *), int, int, int);
int numcmp(char *, char *);
int strcmp2(char *, char *);
/* сортировка строк */

main(int argc, char *argv[])
{
	int nlines; /* количество прочитанных строк */
	int numeric = 0; /* 1, если сорт. по числ. знач. */
	int sort2 = 1, registr = 1, limit = 0, num = -1 ; 
	
	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	
	if (argc > 2 && strcmp(argv[2], "-r") == 0 )
		sort2 = 0;
	
	if (argc > 3 && strcmp(argv[3], "-f") == 0 )
		registr = 0;
	
	if (argc > 4 && strcmp(argv[4], "-d") == 0 )
		limit = 1;
	
	if (argc > 6 && strcmp(argv[5], "-df") == 0 )
		num = atoi(argv[6]);
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

			//qsort1((void **) lineptr, 0, nlines-1,(int (*)(void*,void*))(numeric ? numcmp :(registr ? strcmp : strcmp2)), sort2, limit);
			qsort1((void **) lineptr, 0, nlines-1,(int (*)(void*,void*))(numeric ? numcmp : strcmp ), sort2, limit, num);
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

void qsort1(void *v[], int left, int right, int (*comp)(void *, void *), int ascending, int limit, int num)
{
	int i, last, j, z, k, kk;
	void swap(void *v[], int, int);
	char *tmp[MAXLINES];
	char tmpline[MAXLINES];
	char tmpline2[MAXLINES];
	char c, *p;
	
	if (left >= right) /* ничего не делается, если */
		return; /* в массиве менее двух элементов */
		
	swap(v, left, (left + right)/2);
	last = left;

	for (i=0; i<=right; i++){
		if (limit){
			for (j=0, z=0; (c = ((char*)v[i])[j]) != '\0'; j++)
				if ((c >= 'a' && c <= 'z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == ' '))
					tmpline[z++]=c;	
		}
		else{
			for (j=0, z=0; (c = ((char*)v[i])[j]) != '\0'; j++)
					tmpline[z++]=c;
		}
				
		tmpline[z]='\0';
		
		if (num >= 0){ //сортировка по определенному полю в строке
		tmpline2[0]='\0';
			for (j=0, kk =0 ; j <= num; ++j){
				for(k=0; tmpline[kk] != ' ' && tmpline[kk] != '\0'; ++k, ++kk)
					if (j == num)
						tmpline2[k]=tmpline[kk];	
				if (tmpline[kk] != '\0')
					while(tmpline[++kk] == ' ');
			}
			
			if (tmpline2[0] == '\0')
				goto error;
			else {
				tmpline2[++k]='\0'; 
				p = alloc(k+1);
				strcpy(p,tmpline2);
			}
		}
		else{
			error:
			p = alloc(z+1);
			strcpy(p,tmpline);
		}
		tmp[i] = p;
	}
	
	for (i = left+1; i <= right; i++)
		if (ascending == 1)
		{
			if ((*comp)(tmp[i], tmp[left]) < 0){
				swap(v, ++last, i);
			}
		}
		else
		{
			if ((*comp)(tmp[i], tmp[left]) > 0){
				swap(v, ++last, i);
			}
		}
		
	swap(v, left, last);
	
	qsort1(v, left, last-1, comp, ascending, limit, num);
	qsort1(v, last+1, right, comp, ascending, limit, num);
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

int strcmp2(char *str1, char *str2)
{
	char tmp1[100], tmp2[100], i=0;
	
	for (i=0 ; str1[i] != '\0'; i++) {
		if (str1[i] > 'Z')
			tmp1[i] = str1[i] - ('a' - 'A');
		else
			tmp1[i] = str1[i];
	}
	tmp1[i] = '\0';
	
	for (i=0 ; str2[i] != '\0'; i++) {
		if (str2[i] > 'Z')
			tmp2[i] = str2[i] - ('a' - 'A');
		else
			tmp2[i] = str2[i];
	}		
	tmp2[i] = '\0';
	
	//printf("%d %s %s %s %s %d %d\n",strcmp(tmp1,tmp2),tmp1,tmp2,str1,str2,tmp1[2],str1[2]);
	
	return strcmp(tmp1,tmp2);
}