#include "calc.h"
#define MAXVAL 100

static int sp = 0;
static double val [MAXVAL];

void push(double f){
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, cant push %g\n", f);
}

double pop(void){
  if (sp > 0)
    return val[--sp];
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}

void swaptop(void){
  double top, second;
  if (sp <= 2)
    printf("error: stack shorter than 2.\n");
  else{
    printf("Top of the stack: %g",val[sp]);
    top = val[sp];
    val[sp] = val[sp-1];
    val[sp-1] = top;
  }
}

void clearstack(void){
  sp = 0;
}
