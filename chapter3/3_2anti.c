#include <stdio.h>
#define TEXT_SIZE 10000

int antiescape(int s[], int t[]);

void main(){
	int text[TEXT_SIZE], out[TEXT_SIZE],i,c;
	
	for (i=0;i<TEXT_SIZE;++i){
		text[i]='\0';
		out[i]='\0';
	}
	
	for (i=0; (c=getchar()) != EOF; ++i){
		text[i]=c;
	}
	
	antiescape(out,text);
	
	/*for (i=0; text[i] != '\0'; ++i)
		putchar(text[i]);*/
	
	for (i=0; out[i] != '\0'; ++i)
		putchar(out[i]);
}

int antiescape(int s[], int t[]) {
	int prev=0, i=0,j=0;
	for (i=0;i<TEXT_SIZE;++i){
		switch(t[i]){
			case('\\'):
				prev=1;
				break;
			case('t'):
				if (prev==1)
					s[j++]='\t';
				prev=0;
				break;
			case('n'):
				if (prev==1)
					s[j++]='\n';
				prev=0;
				break;
			default:
				if (prev==1)
					s[j++]='\'';
				s[j++]=t[i];
				prev=0;
				break;	
		}
	}
}