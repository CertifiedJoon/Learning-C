#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct tnode{
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100
struct tnode *addtree(struct tnode*, char*);
void treeprint(struct tnode *);
int getword(FILE *, char *, int);
int getch(FILE *);
void ungetch(int);

int main()
{
   char ch, file_name[25];
   FILE *fp;
   printf("Enter name of a file you wish to see\n");
   gets(file_name);
   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL){
     perror("Error while opening the file.\n");
     exit(EXIT_FAILURE);
   }
   struct tnode *root;
   char word[MAXWORD];

   root = NULL;
   while(getword(fp, word, MAXWORD) != EOF){
     if(isalpha(word[0]))
        root = addtree(root,word);
   }
   treeprint(root);
   fclose(fp);
   return 0;
}

struct tnode *talloc(void);
char *pstrdup(char *s);

struct tnode *addtree(struct tnode *p, char *w){
  int cond;
  if (p == NULL){
    p = talloc();
    p->word = pstrdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) > 0){
    p->right = addtree(p->right, w);
  } else if (cond < 0) {
    p->left = addtree(p->left, w);
  } else {
    p->count++;
  }
  return p;
}

void treeprint(struct tnode *p){
  if(p != NULL){
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

struct tnode *talloc(void){
  return (struct tnode *) (malloc(sizeof(struct tnode)));
}

char *pstrdup(char *s){
  char *p;
  p = (char*) malloc (strlen(s)+1); // +1 becuz of \0
  if (p!=NULL)
    strcpy(p,s);
  return p;
}

int getword(FILE *fp, char *word, int lim){
  int c, getch(FILE *);
  char *w = word;
  while(isspace(c = getch(fp)))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w  = getch(fp))) {
      ungetch(*w);
      break;
    }
  *w = '\n';
  printf("the word is: %s\n", word);
  return word[0];
}

#define BUFSIZE 1

static char buf[BUFSIZE];  // buffer for ungetch
static int bufp;           /*next free psition in buffer */

int getch(FILE *fp){
  return (bufp > 0) ? buf[--bufp] : fgetc(fp);
}

void ungetch(int c){
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters \n");
  else
    buf[bufp++] = c;
}
