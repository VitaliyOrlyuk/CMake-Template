#include <stdio.h>
#include "lib_name.h"

void main() {
  int a = 1, b = 4;
  float result;
  
  result = division(a, b);

  printf("%d / %d = %.2f\n", a, b, result);
}
