#include <stdio.h>

char any(int y[],int x[]);

void main(){
	
	int i,out;
	int s1[10]={'a','b','1','2','3','\n'};
	int s2[10]={'3','b','\n'};

	out=any(s1,s2);
	
	printf("%d",out);

	/*for (i=0;s1[i]!='\n';i++)
		putchar(s1[i]);*/
		
	
}

char any(int y[],int x[]){ //x - таблица со знаками которые находим в y
	int temp[128];
	int i=0;
	int out=-1;
	
	for (i=0;i<128;i++)
		temp[i]='\0';
	
	i=0;
	while (x[i]!='\n'){
		if (temp[x[i]]==0)
			temp[x[i]]=1;
		++i;
	}
	
	i=0;
	while (y[i] != '\n' && out == -1){
		if (temp[y[i]]!=0)
			out=i;
		++i;
	}
	return out;
}