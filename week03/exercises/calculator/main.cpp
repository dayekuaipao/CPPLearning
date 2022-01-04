#include "stdio.h"
int main() {
  bool isContinued = true;
  while (isContinued) {
    printf("Please select an operation:\n+\n-\n*\n/\n%%\n");
    char op;
    int a, b;
    scanf("%c", &op);
    printf("Please input two integers:\n");
    scanf("%d %d", &a, &b);
    long long result;
    switch (op) {
    case '+': {
      result = a + b;
      break;
    }
    case '-': {
      result = a - b;
      break;
    }
    case '*': {
      result = a * b;
      break;
    }
    case '/': {
      while (b == 0) {
        printf("The divisor cannot be zero, please input the divisor again\n");
        scanf("%d", &b);
      }
      result = a / b;
      break;
    }
    case '%': {
      while (b == 0) {
        printf("The divisor cannot be zero, please input the divisor again\n");
        scanf("%d", &b);
      }
      result = a % b;
      break;
    }
    default: {
      printf("Invalid operator\n");
      continue;
    }
    }
    printf("%d %c %d = %lld\n", a, op, b, result);
    printf("Do you want to continue?(Y/N)");
    bool invalid = true;
    while (invalid) {
      char c;
      getchar();
      scanf("%c", &c);
      switch (c) {
      case 'Y':
      case 'y': {
        invalid = false;
        break;
      }
      case 'N':
      case 'n': {
        isContinued = false;
        invalid = false;
        printf("The operation is over.\n");
        break;
      }
      default: {
        invalid = true;
        printf("Invalid answer.Please input again.\n");
        continue;
      }
      }
    }
  }
}