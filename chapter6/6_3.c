/*
Prints reference links in alphabetical order of words found on specific lines
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 100
#define MAXLINELENGTH 1000

struct tree{char *word; int count; struct tree *left; struct tree *right; int *linenumber;};
char *getword();
struct tree *rootcreate();
struct tree *addtree(struct tree *, char *, int);
void treeprint(struct tree *,struct tree *tmp_table[]);
int wordcount = 0;
int compare(const void *, const void *);
int a_compare(const void *, const void *);
int word_num;
int memsize = 8*sizeof(char *);
char line[MAXLINELENGTH];
int readline();
char getcharacter(char []);
void ungetchar();

void main(int argc, char *argv[])
{
	int i, numeric=0, j;
	char *p;
	struct tree *root;
	int *x;
	int length, numofline=0;
	
	root = NULL;
	
	while (readline() > 0){
		while ((p = getword()) != NULL)
			if (isalpha(*p))
				root=addtree(root,p,numofline);
		++numofline;
	}

	struct tree *tmp_table[wordcount];
	treeprint(root, tmp_table);	
	qsort(tmp_table, wordcount, sizeof(struct tree *), a_compare);
		
	printf("\n");
	for (i=0;i<wordcount;++i){
		length = tmp_table[i]->count;
		printf("%s ",tmp_table[i]->word);
		x = (tmp_table[i]->linenumber);
		for (j=0; j<length; j++){
			printf("%d, ",*(x-length+1+j));
		}
		printf("\n");
	}
}

int readline()
{
	char c;
	int len=0;
	while ((c=getchar())!= 10 && c != EOF){
		line[len]=c;
		++len;
	}
	line[len]='\0';
	return len;
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

struct tree *addtree(struct tree *r, char *w, int linenum)
{
	int cond,i;
	
	if (r == NULL){
		r = rootcreate();
		r -> word = w;
		r -> count = 1;
		r -> left = NULL;
		r -> right = NULL;
		r -> linenumber = malloc(memsize);
		*(r -> linenumber) = linenum;
	}
	else if((cond=strcmp(w,r->word))==0){
		if (linenum != (r -> linenumber)[r -> count-1]){
			++r->count;
			if (r->count > 8){
				r -> linenumber - 8;
				memsize *=2;
				realloc(r -> linenumber, memsize);
				r -> linenumber + 8;
			}
			++(r->linenumber);
			*(r->linenumber) = linenum;
		}
	}
	else if(cond<0) //слово меньше левого корня поддерева
		r -> left = addtree(r -> left,w,linenum);
	else
		r -> right = addtree(r -> right,w,linenum);
	
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
	
	while(isspace(c=getcharacter(line)));
	
	if (c == '\0')
		return NULL;
	else{
		while(isalpha(c) || isdigit(c))		{
			tmptbl[len]=c;
			len++;
			c=getcharacter(line);
		}
		ungetchar();
		tmptbl[len]='\0';
		p = (char *) malloc(len + 1);
		return strcpy(p,tmptbl);
	}
}

static int charnum = 0;

char getcharacter(char table[])
{
	char c;
	if ((c=table[charnum]) != '\0'){
		++charnum;
		return c;
	}
	else {
		charnum=0;
		return c;
	}
}

void ungetchar()
{
	--charnum;
}