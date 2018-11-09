#include <stdio.h>

int escape(int s[],int t);

void main(){
	int out [2],c;
	while ((c=getchar())!= EOF){
		out[1]=0; 		
		escape(out,c);
		putchar(out[0]);
		if (out[1] != 0)
			putchar(out[1]);
		if (c=='\n')
			putchar(c);
	}	
}

int escape(int s[], int t) {
	switch(t) {
		case '\t':
			s[0]='\\';
			s[1]='t';
			break;
		case '\n':
			s[0]='\\';
			s[1]='n';
			break;
		default:
			s[0]=t;
			s[1]='\0';
	}	
}
