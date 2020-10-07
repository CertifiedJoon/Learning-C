#include <stdio.h>
#define ALLOCSIZE 1000
#define WORDSIZE 100

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

void strcpy(char*, char*, int);
void strcat(char*, char*, int);
int strend(char*, char*);

int main(){
  char a[WORDSIZE] = "hello";
  char b[WORDSIZE] = " world";
  strcat(a, b, 3);

  int i = 0;
  while(a[i] != '\0'){
    putchar(a[i]);
    i++;
  }
  printf("%d", strend(a,b));
}

void strcpy(char *a, char *b, int n){
  while(*a++ = *b++ && n-- > 0)
    ;
}

void strcat(char *a, char *b, int n){
  while(*a)
    a++;
  while((*a++ = *b++) && n-- > 0)
    ;
}

int strend(char *a, char *b){
  while(*a)
    a++;
  a -= a - b + 1;
  while(*a == *b){
    a++, b++;
  }
  return *b ? 0 : 1;
}

int strcmp(char *s, char *t){
  for (;*s == *t; s++, t++){
    if (*s == '\0')
      return 0;
  }
  return *s - *t;
}
