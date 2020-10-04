#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.c"
#define MAXWORD 100
int getword(FILE *, char *, int);
int getch(FILE *);
void ungetch(int);

int main()
{
  char ch, file_name[25];
  FILE *fp;
  printf("Enter name of a file you wish to preprocess\n");
  gets(file_name);
  fp = fopen(file_name, "r"); // read mode

  if (fp == NULL){
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }
  struct tnode *root;
  char word[MAXWORD], c, name, defn;
  root = NULL;
  while(getchar(c) != '\0'){
    putchar(c);
    if (c == '#' && if (getword(fp, word, MAXWORD) == "define")){
      getword(fp, name, MAXWORD)
      getword(fp, defn, MAXWORD)
      install(name,defn);
    }
    else
  }
  treeprint(root);
  fclose(fp);
  return 0;
}

char *pstrdup(char *s);

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
  for ( ; --lim > 0; w++){
    if (!isalnum(*w  = getch(fp))) {
      ungetch(*w);
      break;
    }
  }
  *w = '\n';
  return word[0];
}

#define BUFSIZE 10

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
