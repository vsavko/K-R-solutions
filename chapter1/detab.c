#include <stdio.h>
#define TABSTOP 8

main() {

int charpass,totab,c,i;
charpass=0;

	while ((c=getchar()) != '\n') {	
	
		totab=TABSTOP-charpass;
		
		if (totab==0){
			totab=TABSTOP;
			charpass=0;
		}
		
		if (c=='\t') {
			for (i=0;i<totab;++i){
				putchar(' ');
				++charpass;
			}
		}
		else{
			putchar(c);
			++charpass;
		}
	}
}