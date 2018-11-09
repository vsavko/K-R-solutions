#include <stdio.h>

#define num 5
#define OUT 0
#define IN 1

main(void) {

int c,i,j,lcount, state;
int chartable[num+1];

for (i=0;i<num;++i)
	chartable[i]=0;

lcount=0;
state=OUT;

while((c=getchar())!=EOF){
	//получить длину слова
	if (c==' ' || c=='\t' || c=='\n'){
		if (lcount>0){
			if (lcount>=num)
				++chartable[num];
			else
				++chartable[lcount];
		}
		lcount=0;
		state=OUT;
	}
	else if(state==OUT)
		state=IN;
		++lcount;
}

for (i=0;i<num+1;++i){	
		printf("%d ",i);
		for (j=0;j<chartable[i];++j)
			printf("x");
		printf("\n");
	}
}