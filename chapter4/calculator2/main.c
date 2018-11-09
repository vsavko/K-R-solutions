#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#define MAXOP 100
#define MAXLINE 1000

void main() {
	
	extern double val[];
	extern double variables[];
	extern int sp;
	extern int curloc;
	
	
	int type, i;
	double op2, op3;
	char s[MAXOP], string[MAXLINE];
	
	for (i=0; i<26; i++)
		variables[i]='\0'; 
	
	//double fmod; //% for doubles using math.h
	while (getline(string,MAXLINE)>0) {		
		while ((type = getop (s, string)) != '\0') {
			switch (type) {
				case NUMBER:
					push (atof(s));
					break;
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '/':
					op2 = pop();
					if (op2 != 0.0)
						push(pop() / op2);
					else
						printf("error: division by zero\n");
					break;
				case VARIB:
					break; //присвоили 
				case '%':
					op2 = pop();
					push(fmod(pop(),op2));
					break;
				case OUT: //print out upper stack element
					printf("\tupper stack element:%.8g\n", op2=pop());
					push (op2);
					break;
				case DUB: //dublicate top element
					push(op2=pop());
					push(op2);
					break;
				case SWH: //switch top 2 elements
					op3=pop();
					op2=pop();
					push(op3);
					push(op2);
					break;
				case CLS: //clear stack
					for (i=0; i<sp; i++)
						val[i]='\0';
					sp=0;
					break;
				case SIN: //clear stack
					push(sin(pop()));
					break;
				case COS: //clear stack
					push(cos(pop()));
					break;
				case EXP: //clear stack
					push(exp(pop()));
					break;
				case POW: //clear stack
					op2=pop();
					push(pow(pop(),op2));
					break;
				case '\n':
					printf("\tanswer:%.8g\n", pop()); //ответ
					printf("stack[0]:%g stack[1]:%g stack[2]:%g sp: %d\n", val[0], val[1], val[2], sp); //ответ
					break;
				default:
					printf("error: unknown operation %s\n", s);
				break;
			}
		}
		curloc=0;
	}
}