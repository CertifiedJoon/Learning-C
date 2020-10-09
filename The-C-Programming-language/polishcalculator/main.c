#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

static double recent_result; //external variable's defualt value is 0

int main(){
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF){
    switch(type){
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("Error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0)
        push((int)pop() % (int)op2);
      else
        printf("error: zero modulo");
      break;
    case '\n':
      op2 = pop();
      printf("result:\t%.8g\n", op2);
      addvar(op2);
      break;
    case 'w':
      swaptop();
      printf("swapping the top 2 elements of stack...\n");
      break;
    case 'd':
      clearstack();
      printf("clearing stack...\n");
      break;
    case 's':
      push(sin(pop()));
      break;
    case 'e':
      push(exp(pop()));
      break;
    case 'p':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case 'r':
      push(recent_result);
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

void addvar(double f){
  recent_result = f;
}
/*
void ungets(char s[], int length){
  for(int i = length - 1; i >= 0; --i){
    ungetch(s[i]);
  }
}
*/
