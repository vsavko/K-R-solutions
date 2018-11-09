#include <stdio.h>

void squeeze(int y[],int x[]);

void main(){
	
	int i;
	int s1[10]={'a','b','1','2','3','\n'};
	int s2[10]={'a','\n'};

	squeeze(s1,s2);


	for (i=0;s1[i]!='\n';i++)
		putchar(s1[i]);
		
	
}

void squeeze(int y[],int x[]){ //x - таблица со знаками которые удаляем из таблицы y
	int temp[128];
	int i,j=0;
	
	for (i=0;i<128;i++)
		temp[i]='\0';
	
	i=0;
	while (x[i]!='\n'){
		if (temp[x[i]]==0)
			temp[x[i]]=1;
		++i;
	}
	
	i=0;
	while (y[i]!='\n'){
		if (temp[y[i]]==0){
			y[j++]=y[i];
		}
		++i;
	}
	
	y[j++]='\n';
	
}