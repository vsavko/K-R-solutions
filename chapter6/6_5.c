#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {/* элемент таблицы */
	struct nlist *next; /* указатель на следующий элемент */
	char *name; /* определенное имя */
	char *defn; /* замещающий текст */
};

#define HASHSIZE 1
static struct nlist *hashtab[HASHSIZE]; /* таблица указателей */

/* hash: получает хэш-код для строки s */
unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: ищет s */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; /* нашли */
	return NULL; /* не нашли */
}

char *StrDup(char *s);
/* install: заносит имя и текст (name, defn) в таблицу */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL) {/* не найден */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = StrDup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else /* уже имеется */
		free((void *) np->defn); /* освобождаем прежний defn */
	if ((np->defn = StrDup(defn)) == NULL)
		return NULL;
	return np;
}

struct nlist **lookup2(char *s)
{
	struct nlist *np;
	struct nlist **ptr;
	for (np = hashtab[hash(s)], ptr=&hashtab[hash(s)]; np != NULL; np = np->next){
		//printf("le %d %d %d \n",np,ptr,&np);
		if (strcmp(s, np->name) == 0)
			return ptr; /* нашли */
		ptr = (struct nlist **) np;	
	}
	return NULL; /* не нашли */
}

void undef(char *name)
{
	struct nlist *np;
	struct nlist **ptr;
	if ((ptr = lookup2(name)) != NULL) {
		np = *ptr;
		*ptr = np->next;
		free ((struct nlist *) np);	
	}
}

char *StrDup(char *s) /* делает дубликат s */
{
	char *p;
	p = (char *) malloc(strlen(s)+1); /* +1 для '\0' */
	if (p != NULL)
	strcpy(p, s);
	return p;
}

void main()
{
	char *p = "yes";
	char *t = "no";
	char *test="fdgdgsfg";
	char *test2="fdgdg45tsfg";
	install(p, t);
	install(test, test2);
	
	struct nlist *ptr;
	ptr=lookup(test);
	printf("%s \n",hashtab[0]->name);
	undef(test);
	ptr=lookup(p);
	printf("%s \n",hashtab[0]->name);
}