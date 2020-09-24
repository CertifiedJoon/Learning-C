#include <stdio.h>
#define STRINGMAX 20

void itoa (int, char[]);

int main(){
  char s[STRINGMAX];
  int n = -1223;
  int i = 0;
  itoa(n, s);
  while (s[i] != '\0'){
    putchar(s[i]);
    ++i;
  }
  putchar('\n');
}

void itoa(int n, char s[]){
  if (n < 0){
    s[0] = '-';
    n = -n;
    s[1] = '\0';
  }
  if (n / 10)
    itoa(n / 10, s);
  int i;
  for(i = 0; s[i] != '\0'; ++i)
    ;
  s[i] = n % 10 + '0';
  s[i+1] = '\0';
}
