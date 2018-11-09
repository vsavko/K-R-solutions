#include <stdio.h>
#include <ctype.h>
#define MAX_BUFFER 100

int push(int);
int pop(void);
int getnumber(char[], int);

void main(int argc, char *argv[])
{
	int i=0, j=0, x;
	char c;
	
	while( --argc > 0 )
	{	
		c=*argv[++i];
		if (isdigit(c)){
			x = getnumber(argv[i], MAX_BUFFER);
			push(x);
		}
		else {
			switch (c){
				case '-':
					x=pop();
					push(x-pop());
					break;
				
				case '+':
					push(pop()+pop());
					break;
					
				case '*':
					push(pop()+pop());
					break;
					
				case '/':
					x = pop();
					push(x / pop());
					break;
				
				case '%':
					x = pop();
					push(x % pop());
					break;
					
				default: 
					printf("wrong input: %c\n",c);
					break;
			}
		}
	}	
	
	printf("result is: %d\n", pop());

}

int stack[MAX_BUFFER];
static int buff=0;

int push(int x)
{
	if (buff<MAX_BUFFER)
		stack[buff++]=x;
	else
		return -1;
}

int pop(void)
{
	if (buff > 0)
		return stack[--buff];	
}

int getnumber(char c[], int maxbuffer)
{
	char text[maxbuffer];
	int i=0, j=0;
	
	while (isdigit(c[j]))
	{
		i = (i*10 +c[j]-'0');
		++j;	
	}	
	return i;
}