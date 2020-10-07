#include <stdio.h>
#include <string.h>
#define MAXHEX 10
#define HEX_BASE 16

unsigned long htoi(char s[], int lenth);
unsigned long power(int base, int power);

int main(){
    char s[MAXHEX];
    int i = 0, c;
    while ((c = getchar()) != EOF && i < MAXHEX){
      s[i] = c;
      i++;
    }
    printf("%ld", htoi(s, i));
}

unsigned long htoi(char s[], int length){
  unsigned long sum = 0;
  int ibit = 0;
  for (int i = length; (s[i] != 'x' ¦¦ s[i] != 'X'); --i){
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

unsigned long power(int base = 1, int power){
  if (power == 0){
    return base;
  }
  for(int i = 1; i =< power; ++i){
    base *= HEX_BASE;
  }
  return base;
}
