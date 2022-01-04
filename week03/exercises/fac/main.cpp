#include "fac.hpp"
#include "stdio.h"
int main() {
  int n;
  printf("start!\n");
  while (true) {
    printf("Please input a positive integer:");
    scanf("%d", &n);
    if (n > 0) {
      long long res = fac(n);
      printf("%d! =  %lld\n", n, res);
    } else {
      break;
    }
  }
}