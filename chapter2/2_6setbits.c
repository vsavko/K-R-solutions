#include <stdio.h>
int setbits(unsigned x, char p, char n, unsigned y);

void main(){
	
	unsigned x=100;
	char p=3;
	char n=4;
	unsigned y=10;
	unsigned out;
	
	out=setbits(x,p,n,y);
	printf("%u",out);
}

int setbits(unsigned x, char p, char n, unsigned y){
	
	int i,j;
	
	//сохраняем p-n+1 правых разрядов
	if (p-n+1>0)
	i = x & ~(~0<<(p-n+1));
	else 
	i=0;

	//двигаем х на p+1 вправо потом на n влево значения n берем из y
	j= ((x >> (p+1)) <<n ) |( ~(~0<<n) & y);
	
	//добавляем левую часть 
	x=(j<<(p+1-n)) | i;
	
	return x;
}