#include <stdio.h>
#include <ctype.h>

int getfloat(double *);

void main(){
	
	double num=0;
	int test;
	double *z;
	int *t;
	
	test= getfloat(&num);
	
	z= &num;
	t = &z;

	
	printf("%.30g %g %x",num, *z, z) ;
}

int getfloat(double *num){
	
	double tempnum=0;
	char c;
	static double sign = 1;
	double power = 1;
	
	while (isspace(c=getchar()))
		;
	
	if (!isdigit(c) && c != '-'){
		return 0;
	}
		
	if (c == '-')
		sign = -1;
		
	if (isdigit(c)){
		tempnum = c - '0';
		while (isdigit(c=getchar()))
			tempnum = tempnum*10 + (c-'0');
		if (c == '.'){
			while (isdigit(c=getchar())){
				power *= 10;
				tempnum = tempnum*10+(c-'0');
			}
			tempnum /= power;
		}
	}
	
	*num = tempnum * sign;
	
	if (c == '-')
		sign = -1;
	else 
		sign = 1;
	
	return 1;
}