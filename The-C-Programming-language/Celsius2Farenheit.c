#include <stdio.h>
 /*prints Fahrenheit-Celsius table*/
float ftoc(float f);
int main()
{
  printf("printing fahrenheit to celsius conversion table:\n");
  float f;
  for(f = 0; f <= 300; f = f + 20){
    printf("%3.0f%6.1f\n", f, ftoc(f));
  }
  return 0;
}

float ftoc(float f){
  return (5.0/9.0) * (f - 32.0);
}
