#include <stdio.h>
#include<time.h>
#define TAB_LEN 500004

int binsearch(int x, int v[], int n);


void main(){
	

	
	int table[TAB_LEN],i,x=TAB_LEN/2,n=TAB_LEN;
	for (i=0;i<TAB_LEN;i++)
		table[i]=i*2;
	
	time_t start,end;
	start=time(NULL);
	
	x=binsearch(x,table,n);
	
	end=time(NULL);
	printf("%f",difftime(end, start));
	
	printf("%d",x);
}

int binsearch(int x, int v[], int n){
	int low, high, mid;
	low = 0;
	high = n-1;
	
	while ( x>=v[low]) {
		mid = (low + high) / 2;
		
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid+1;
	}
	
	printf("%d %d %d\n",high,low,mid);

	if (x==v[mid]) 
		return mid;
	else
		return -1; /* совпадения нет */
}
