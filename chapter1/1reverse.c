#include <stdio.h>

void reverse(char to[], char from[]);

main()
{
	
char table1[4]={'a','b','c','\0'};
char table2[4]={'1','2','3','\0'};

reverse(table2, table1);

printf("%s\n",table1);
printf("%s\n",table2);

}

void reverse(char to[], char from[])
{
	int i,j;
	for (i=0; to[i] !=  '\0'; ++i);

	j=i;
	i=0;
	
	for (j; j>=0; --j){
		to[i]	= from[j];
		++i;
	}
}