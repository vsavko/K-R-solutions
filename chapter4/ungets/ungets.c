#include <stdio.h>
#include <string.h>
#include "gets.h"

extern int bufp;

void ungets (char s[]){
	int i, len;
	len = strlen(s);
	
	if (len > BUFSIZE-bufp)
		printf("%d string character(s) didn't fit\n",len-(BUFSIZE-bufp));
	
	for (i=0; i<len && bufp<BUFSIZE; i++){
		ungetch(s[i]);
	}

	
}

