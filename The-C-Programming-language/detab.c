#include <stdio.h>
#define TABSIZE 8
int main(){
  int c, nexttab;
  nexttab = TABSIZE;
  while ((c = getchar()) != EOF){
    if (nexttab == 0)
      nexttab = TABSIZE;
    if (c == '\t'){
      putchar(nexttab + '0');
      nexttab = TABSIZE;
    }
    else if (c == '\n'){
      putchar(c);
      nexttab = TABSIZE;
    }
    else{
      putchar(c);
      nexttab = nexttab - 1;
    }
  }
  return 0;
}
