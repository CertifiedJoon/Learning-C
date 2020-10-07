#include <stdio.h>
#include <string.h>
#define MAXHEX 10
#define HEX_BASE 16
#define MAXSIZE 10000
#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[]);
void reverse(char s[]);
void preverse(char *);
void itob(int n, char s[], int base);
unsigned long htoi(char s[], int lenth);
size_t pstrlen(char *);
void pswap(char *, char *);
unsigned long power(int);


int main(){
  /*char string[MAXSIZE];
  itob(-256, string, 2);*/
  int i = -1234;
  char *s;
  pitoa(i, s);
  printf("%s", s);
}

void reverse(char s[]){
  int i, j, c;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
    c = s[i], s[i] = s[j], s[j] = c;
  }
}

void preverse(char *s){
  size_t size = strlen(s);
  char *right = s + size - 1;
  while(s <= right){
    pswap(s,right);
    s++;
    right--;
  }
}

void pswap(char *a, char *b){
  char temp = *a;
  *a = *b;
  *b= temp;
}

void itoa(int n, char s[]){ //int to string
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

void pitoa(int n, char *s){
  int sign = 1;
  char *p = s;
  if (n < 0){
    sign = -1;
    n = abs(n);
  }
  do{
    *s++ = n % 10 + '0';
  } while((n /= 10) != 0);
  if (sign < 0){
    *s++ = '-';
    *s = '\0';
  }
  preverse(p);
}

void itob(int n, char s[], int base){ // converts int to a any base number system
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

unsigned long htoi(char s[], int length){ // converts hexa decimal to int
  unsigned long sum = 0;
  int ibit = 0;
  for (int i = length; (s[i] != 'x' || s[i] != 'X'); --i){
    if (s[i] <= '9' && s[i] >= '0')
      sum += (s[i] - '0') * power(ibit);
    else if (s[i] <= 'F' && s[i] >= 'A')
      sum += (s[i] - 'A' + 10) * power(ibit);
    else if (s[i] <= 'f' && s[i] >= 'a')
      sum += (s[i] - 'a' + 10) * power(ibit);
    ibit++;
  }
  return sum;
}

unsigned long power(int pow){
  int base = 1;
  if (pow == 0){
    return base;
  }
  for(int i = 0; i < pow; ++i){
    base *= HEX_BASE;
  }
  return base;
}
