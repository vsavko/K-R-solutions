#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 100

struct tree{char *word; int count; struct tree *left; struct tree *right;};
char *getword();
struct tree *rootcreate();
struct tree *addtree(struct tree *, char *);
void treeprint(struct tree *,struct tree *tmp_table[]);
int wordcount=0;
int compare(const void *, const void *);
	
void main()
{
	int i;
	char *p;
	struct tree *root;
	
	root = NULL;

	while ((p = getword()) != NULL)
		if (isalpha(*p))
			root=addtree(root,p);	

	struct tree *tmp_table[wordcount];
	treeprint(root, tmp_table);	
	
	qsort(tmp_table, wordcount, sizeof(struct tree *), compare);
	
	printf("\n");	
	
	for (i=0;i<wordcount;++i)
		printf("%d %s\n",tmp_table[i]->count,tmp_table[i]->word);

}

int compare(const void *x, const void *y){
	
	struct tree *xx = *(struct tree **) x;
	struct tree *yy = *(struct tree **) y;
	return (xx->count - yy->count);	
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

struct tree *addtree(struct tree *r, char *w)
{
	int cond;
	
	if (r == NULL){
		r = rootcreate();
		r -> word = w;
		r -> count = 1;
		r -> left = NULL;
		r -> right = NULL;
	}
	else if((cond=strcmp(w,r->word))==0)
		++r->count;
	else if(cond<0) //слово меньше левого корня поддерева
		r -> left = addtree(r -> left,w);
	else
		r -> right = addtree(r -> right,w);
	
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