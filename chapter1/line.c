//delete excees tabs, spaces and empty lines
#include <stdio.h>

main()
{
	char c, table[1000];
	int i,state;
	
	for (i = 0; c != EOF; ++i)
	{
		c=getchar();
		if (c == '\t' || c == ' ')
		{
			table[i]=' ';
			++i;
			while ((c = getchar()) == ' ' || c == '\t' );
		}	
		if (c == '\n')
		{
			table[i]='\n';
			++i;
			while ((c=getchar())=='\n' && c!=EOF);
		}
		table[i] = c;
	}	
table[i+1]='\0';
printf("%s",table);
}