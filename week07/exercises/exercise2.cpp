#include <math.h>
#include <stdio.h>
int vabs(int *p, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += abs(p[i]);
  }
  return sum;
}

float vabs(float *p, int n) {
  float sum = 0;
  for (int i = 0; i < n; i++) {
    sum += abs(p[i]);
  }
  return sum;
}

double vabs(double *p, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += abs(p[i]);
  }
  return sum;
}

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  printf("%d\n", vabs(a, 5));
  float b[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
  printf("%f\n", vabs(b, 5));
  double c[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  printf("%f\n", vabs(c, 5));
}