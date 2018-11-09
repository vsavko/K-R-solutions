#include <stdio.h>
#include <limits.h>
#include <float.h>

#define test 2444444444u

main(){
	
	printf("%f\n",test);

	printf("Signed\n");
	printf("Range of signed char: from %d to %.0f\n",SCHAR_MIN, (double) SCHAR_MAX);
	printf("Range of signed int: from %d to %.0f\n",INT_MIN, (double) INT_MAX);
	printf("Range of signed short: from %d to %.0f\n",SHRT_MIN,(double) SHRT_MAX);
	printf("Range of signed long: from %d to %.0f\n",LONG_MIN, (double) LONG_MAX);
	printf("Range of signed double: from %f \n",sizeof(double));
	printf("Unsigned\n");
	printf("Range of unsigned char: from %d to %.0f\n",0, (double) UCHAR_MAX);
	printf("Range of unsigned int: from %d to %.0f\n",0, (double) UINT_MAX);
	printf("Range of unsigned short: from %d to %.0f\n",0, (double) USHRT_MAX);
	printf("Range of unsigned long: from %d to %.0f\n",0, (double) ULONG_MAX);
		
	
		
	
	
	
}