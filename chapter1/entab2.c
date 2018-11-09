#include <stdio.h>
#define TABSTOP 8

int cursorcnt(int cursor1);

void main(){
	
int cursor,totab,c,i,j,tabcount,spaces,z,zz,t,spacenr;
int table[1000];
int table2[1000];
int table3[1000];
int out[1000];

for (i=0;i<1000;++i){
	table[i]=0;
	table2[i]=0;
	table3[i]=0;
	out[i]=0;
}

cursor=0;
i=0;
z=0;
t=1;
spacenr=0;

while ((c=getchar()) != '\n') {
	
	if (c!=' '){
		
		if (spacenr>0){ //если вышли из пробелов и они были до этого
		
		//заменяем пробелы на табы+пробелы
			/*for (i=0;i<spacenr;++i)
				putchar(' ');*/
			
			if (spacenr<totab)
				for (i=0;i<spacenr;++i)
				putchar(' ');
			else if (spacenr==totab)
				putchar('\t');
			else{
				putchar('\t');
				tabcount=(spacenr-totab)/TABSTOP;
				
				for (i=0;i<tabcount;++i)
				putchar('\t');	
			
				spaces=(spacenr-totab)-tabcount*TABSTOP;
				
				for (i=0;i<spaces;++i)
				putchar(' ');	
			}
			
		//считаем положение курсора и totab
			if (c=='\t')	
				cursor= ((cursor+spacenr)/TABSTOP)*TABSTOP+TABSTOP;
			else
				cursor=cursor+spacenr+1;
			totab=TABSTOP-(cursor-(cursor/TABSTOP)*TABSTOP);
			
			table[t]=cursor;
			table2[t]=c; 
			table3[t]=totab;
			++t;
			
			putchar(c);
			spacenr=0;
		}
		else { //если пробелов не было
			if (c=='\t')	
				cursor= ((cursor)/TABSTOP)*TABSTOP+TABSTOP;
			else
				++cursor;
			totab=TABSTOP-(cursor-(cursor/TABSTOP)*TABSTOP);
			table[t]=cursor;
			table2[t]=c; 
			table3[t]=totab;
			++t;
			
			putchar(c);
		}
	}
	else
		++spacenr;		
}

printf("\n");

for (t=1;t<20;++t){
	printf("%2d %2d %2d %2d\n",t,table[t],table2[t],table3[t]);
}


}