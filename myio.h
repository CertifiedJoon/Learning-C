#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 100

int getline(char s[], int lim);
int readlines(char *lineptr[], int maxlines);
int getword(char *word, int lim);
int getch(void);
void ungetch(int);

int getline(char s[], int lim){
  int c, i;
  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if(c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int readlines(char *lineptr[], int maxlines){
  int len, nlines;
  char *lines[MAXLEN], *line;

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0){
    if (nlines >= maxlines)
      return -1;
    else{
      line[len-1] = '\0'; // deleting newline
      lineptr[nlines++] = line;
      printf("%s\n", line);
    }
  }
  return nlines;
}

int getword(char *word, int lim){
  int c, getch(void);
  char *w = word;
  while(isspace(c = getch()))
    ;
  if (c = EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w  = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\n';
  return word[0];
}

#define BUFSIZE 1

static char buf[BUFSIZE];  // buffer for ungetch
static int bufp;           /*next free psition in buffer */

int getch(void){
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters \n");
  else
    buf[bufp++] = c;
}
