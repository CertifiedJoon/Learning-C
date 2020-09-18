#include <stdio.h>
 /*prints Fahrenheit-Celsius table*/
int main()
{
  printf("printing fahrenheit to celsius conversion table:\n");
  float f, c;
  int lower = 0;
  int upper = 300;
  int step = 20;
  while(f <= upper){
    c = (5.0/9.0) * (f - 32.0);
    printf("%3.0f%6.1f\n", f, c);
    f = f + step;
  }
}
