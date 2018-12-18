/*
Reads text from console and sorts alphabetically groups of words
with the same first n-number of characters,
then prints them all out. 
First (optional) console parameter sets the n-number of charcters, default is 6.
Second (optional) console parameter -n, changes the sort by the ammount of words, 
alphabetical sort by default.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 100

struct tree{char *word; int count; struct tree *left; struct tree *right; char **fullword;};
char *getword();
struct tree *rootcreate();
struct tree *addtree(struct tree *, char *, char *);
void treeprint(struct tree *,struct tree *tmp_table[]);
int wordcount = 0;
int compare(const void *, const void *);
int a_compare(const void *, const void *);
int word_num;
int memsize = 8*sizeof(char *);

	
void main(int argc, char *argv[])
{
	int i, numeric=0, j;
	char *p;
	struct tree *root;
	char *tmp_word;
	char **x;
	int length;
	
	if (argc>0 && (word_num= atoi(argv[1]))>0 )
		;
	else
		word_num=6;
		
	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	
	root = NULL;

	while ((p = getword()) != NULL)
		if (isalpha(*p)){
			tmp_word = malloc(word_num+1);
			for (i=0; i<word_num; i++)
				*tmp_word++ = *p++;
			*tmp_word = '\0';
			tmp_word -= word_num;
			p -= word_num;
			root=addtree(root,tmp_word,p);
		}

	struct tree *tmp_table[wordcount];
	treeprint(root, tmp_table);	
	
	if (numeric == 1)
		qsort(tmp_table, wordcount, sizeof(struct tree *), compare);
	else
		qsort(tmp_table, wordcount, sizeof(struct tree *), a_compare);
		
	printf("\n");
	for (i=0;i<wordcount;++i){
		length = tmp_table[i]->count;
		printf("%d %s\n",length,tmp_table[i]->word);
		printf("__________________________\n");
		x = (tmp_table[i]->fullword);
		for (j=0; j<length && j<10; j++){
			printf("%s\n",*(x-length+1+j));
		}
		printf("\n");
	}

}

int compare(const void *x, const void *y){
	struct tree *xx = *(struct tree **) x;
	struct tree *yy = *(struct tree **) y;
	return (xx->count - yy->count);	
}

int a_compare(const void *x, const void *y){
	struct tree *xx = *(struct tree **) x;
	struct tree *yy = *(struct tree **) y;
	return (strcmp(xx->word,yy->word));	
}

void treeprint(struct tree *root, struct tree *tmp_table[])
{

	static int i=0;
	
	if (root!= NULL){
		treeprint(root->left,tmp_table);
		tmp_table[i++]=root;
		treeprint(root->right,tmp_table);
	}
}

struct tree *addtree(struct tree *r, char *w, char *full)
{
	int cond,i;
	
	if (r == NULL){
		r = rootcreate();
		r -> word = w;
		r -> count = 1;
		r -> left = NULL;
		r -> right = NULL;
		r -> fullword = malloc(memsize);
		*(r -> fullword) = full;
	}
	else if((cond=strcmp(w,r->word))==0){
		++r->count;
		if (r->count > 8){
			r -> fullword - 8;
			memsize *=2;
			realloc(r -> fullword, memsize);
			r -> fullword + 8;
		}
		++(r->fullword);
		*(r->fullword) = full;
	}
	else if(cond<0) //слово меньше левого корня поддерева
		r -> left = addtree(r -> left,w,full);
	else
		r -> right = addtree(r -> right,w,full);
	
	return r;
}

struct tree *rootcreate()

{
	++wordcount;
	return (struct tree *) malloc(sizeof(struct tree));
}

char *getword() 
{
	char c;
	int len = 0;
	char *p;
	char tmptbl[MAXLENGTH];
	
	while(isspace(c=getchar()));
	
	if (c == EOF)
		return NULL;
	else{
		while(isalpha(c) || isdigit(c))		{
			tmptbl[len]=c;
			len++;
			c=getchar();
		}
		tmptbl[len]='\0';
		p = (char *) malloc(len + 1);
		return strcpy(p,tmptbl);
	}
}