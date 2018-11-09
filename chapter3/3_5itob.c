//переводит целое n в строку s, представляющую число по основанию b
#include <stdio.h>
#include <string.h>
#include <math.h>

int itob(int n, char s[], int b);
void reverse(char s[]);

void main(){
	int n=-10,i,b=16;
	char s[100];
	
	for (i=0; i<100; ++i)
		s[i]='\0';
	
	printf("Base conversion of whole numbers.\nEnter a dec number:");
	scanf("%d",&n);
	printf("Enter base (from 2 to 35):");
	scanf("%d",&b);
	
	itob(n,s,b);
	
	for (i=0; s[i] != '\0' ; ++i)
		putchar(s[i]);
		//printf("%d ",s[i]);
	
}

int itob(int n, char s[], int b){ 
	//base from 2 to 35
if (b>1 && b<36){
	
	int remainder, delimoe=n, i;
	
	for (i=0; delimoe!=0; ++i){
		remainder=fabs(delimoe%b);
		if (remainder>9)
			remainder += 55; //присваеваем букву
		else
			remainder += 48; //присваеваем цифру
		delimoe=delimoe/b;
		s[i]=remainder;
	}
	
	if (n<0)
		s[i]=45;
	
	reverse(s);
}

else
	return ('\0');
}

void reverse(char s[])
{
	int c,i,j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}