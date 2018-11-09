#include <stdio.h>
#include <string.h>
#define BUFFLEN 10000
#define MAXLEN 1000
#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char [], char *[], int );
int getline(char[], int );

	
	
void main(){
	char *line[MAXLINES];
	char store[BUFFLEN];

	int i;
	
	//printf("%d",readlines(store, line, MAXLINES));
	
	for (i=0; line[i] != NULL; i++)
		printf("%d ",*line[i]);
	
}

int readlines(char buffer1[], char *lineptr[], int maxlines )
{
	int nlines=0, len;
	char line[MAXLEN];
	char *ptr;
	ptr=buffer1;
	
	while ((len = getline(line,MAXLEN))>0){
		if ( (nlines > maxlines) || strlen(buffer1) > BUFFLEN)
			return -1;
		line[len-1]='\0';
		strcpy(ptr,line);
		lineptr[nlines++]=ptr;
		ptr += len;
	}	
	return nlines;
}

int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}