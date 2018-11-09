#include<stdio.h>
#define LIM 10

main (){
	
	int i, c, s[LIM];
	
	for (i=0; i< LIM -1;++i)
		s[i]='\0';

	for (i=0; (c=getchar()) != EOF;++i) {
		if (i<LIM-1){
			if (c!='\n')
				s[i]=c;	
		}
	}
	
	for (i=0; i< LIM -1;++i){
		//if (s[i]!='\0')
		putchar(s[i]);
	}
	
}