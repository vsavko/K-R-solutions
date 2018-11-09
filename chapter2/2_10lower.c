#include <stdio.h>

int lower(int x);

void main() {
	int c;
	while ((c=getchar())!= EOF){
		c=lower(c);
		putchar(c);
	}
}

int lower(int x){	
	return (x>64 && x< 91) ? x+=32 : x;
}