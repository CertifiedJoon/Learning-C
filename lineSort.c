//pointers to pointer.
#include <stdio.h>
#define MAXLINES 50
#define MAXLEN 1000

static char *lineptr[MAXLINES];

int getline(char *, int);
int readlines (char * lineptr[], int nlines);
void writelines (char* lineptr[], int nlines);
void qsort (char* v[], int, int);
int strcmp (char*, char*);

int main(){
  int nlines;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
    qsort(lineptr,0,nlines-1);
    printf("d");
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input exceeded %d lines", MAXLINES);
    return 1;
  }
}


void qsort(char* v[], int left, int right){
  int i, last;
  void swap (char* v[], int i, int j);
  if (left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left + 1; i <= right; i++){
    if (strcmp(v[i], v[left]) < 0)
      swap(v, i , ++last);
  }
  swap(v, left, last);
  qsort(v, last + 1, right);
  qsort(v, left, last - 1);
}

void swap(char *v[], int i, int j){
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
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

void writelines(char *lineptr[], int nlines){
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

int strcmp(char *s, char *t){
  for (;*s == *t; s++, t++){
    if (*s == '\0')
      return 0;
  }
  return *s - *t;
}

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
