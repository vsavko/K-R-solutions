# include <stdio.h>

int rightrot(unsigned int x, char n);

void main(){
	unsigned int x;
	x=rightrot(2147483648,1);
	printf("%u",x);
}

int rightrot(unsigned int x, char n){
	unsigned int mask,x1,x2;	
	mask = ~(~0<<n);
	x1 = (x & mask) << (sizeof(x)*8-n);
	x2 = (x & ~mask) >> n;
	x= x1|x2;
	return x;
}