#include <stdio.h>
#define LINEMAX 1000

int getline(char line[], int lim);
void printline(char line[], int len);

int main(){
  int len;
  char line[LINEMAX];
  while ((len = getline(line, LINEMAX)) != 0){
    if (len > 80)
      printline(line,len);
  }
  return 0;
}

int getline(char line[], int lim){
  int i, c;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && line[i] != '\n'; ++i)
    line[i] = c;
  if (c == '\n'){
    line[i] = c;
    ++i;
  }
  line[i] = '\n';
  return i;
}

void printline(char line[], int len){
  for (int i = 0; i < len; ++i)
    putchar(line[i]);
}
