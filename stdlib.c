#include <stdio.h>
#include <string.h>
#define MAXSIZE 10000
#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[]);
void reverse(char s[]);
void itob(int n, char s[], int base);

int main(){
  char string[MAXSIZE];
  itob(-256, string, 2);
  return 0;
}

void reverse(char s[]){
  int i, j, c;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
    c = s[i], s[i] = s[j], s[j] = c;
  }
}

void itoa(int n, char s[]){
  int i, sign = n;

  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while( (n /= 10) > 0);
  if(sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
  printf("%s", s);
}

void itob(int n, char s[], int base){
  int i, sign;
  sign = n;

  i = 0;
  do{
    s[i++] = abs(n % base) + '0';
  } while ((n /= base) != 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
  printf("%s", s);
}
