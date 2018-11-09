//переносит текст на новую строку после n позиций
#include <stdio.h>
#define N 10
#define TABSTOP 8

main(){
	int table[1000];
	int tableout[N];
	int i,j,k,z,c,charpass,totab,counter=0,totalch,stopchar;
	
	for (i=0;i<1000;++i){ //таблица хранящая строки
		table[i]='\0';
	}
	
	for (i=0;i<N;++i){ //таблица хранящая строки
		tableout[i]='\0';
	}
	
	i=1; //записываем в таблицу с 1го значения
	charpass=0;
	
	while ((c=getchar())!=EOF){
		
		totab=TABSTOP-charpass;
		
		if (totab==0){
			totab=TABSTOP;
			charpass=0;
		}
		
		if (c != '\t'){
			table[i]=c;
			//printf("test %d, %d, %d",c,i,table[i]);
			++i;
			++charpass;
		}
		else {
			for (j=0;j<totab;++j){
				table[i]=' ';
				++i;
				++charpass;
			}
		}	
	}
	
	totalch=i;
	
	/*	for (i=0;i<20;++i) //таблица хранящая строки
		printf("%d %d\n",i,table[i]);*/
		
	//printf("%d \n",totalch);
	
	for (j=1;j<=totalch;++j){
		counter=counter+1;
		tableout[counter]=table[j];
		
		//printf(" counter: %d\n",counter);
		
		if (table[j]=='\n')
		{
			for (i=1; i <= counter; ++i){
				putchar(tableout[i]);
			}
			counter=0;
			//printf("test");
		}
				
		if (counter==N)
		{
			if 	(tableout[counter]==' ')	{	
				for (i=1; i <= counter; ++i){
					putchar(tableout[i]);
				}
				counter=0;
				//printf("test3");
			}	
			else{
				for (k=N; (k>=1) && (tableout[k] != ' ');--k);
				
				//printf("%d\n",k);
				
				if (k==0){ //строка из сплошных знаков без пробелов
					for (i=1; i <= counter; ++i){
					putchar(tableout[i]);
					}
					counter=0;
					//printf("test2");
				}
				else{
					for (i=1; i <= k; ++i){
						putchar(tableout[i]);
					}
					//printf("test %d, %d",k,i);
					z=1;
					for (i=k+1;i<=N;++i){
						tableout[z]=tableout[i];
						++z;
					}
					counter=N-k;
				}
			}
			putchar('|');			
			putchar('\n');
		}

	}
	
	/*for (i=1; i <= counter; ++i)
				putchar(tableout[i]);*/
	
	//printf("\n counter: %d",counter);
	/*for (i=1;i<20;++i) //таблица хранящая строки
		printf("%d %d\n",i,tableout[i]);*/
}