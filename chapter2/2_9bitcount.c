#include <stdio.h>

int bitcount(unsigned x);

void main(){
	printf("%d",bitcount(5757));
}

int bitcount(unsigned x){
	int i;
	for (i=0;x!=0;++i)
		x &=(x-1);
	return i;
}