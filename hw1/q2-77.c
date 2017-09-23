#include <stdio.h>

// Part A
//k = 17
int constk_17(int x) {
  return (x << 4) + x;
}

// Part B
// k = -7
int constk_neg7(int x) {
  return x - (x << 3);
}

// Part C
//k = 60
int constk_60(int x) {
  return (x << 6) - (x << 2);
}

// Part D
// k = -112
int constk_neg112(int x) {
  return (x << 4) - (x << 7);
}

int main(void) {
  int c[3];
  c[0] = 7;
  c[1] = 12;
  c[2] = 14;

  int i = 0;
  for (i = 0; i < 3; i++) {
    printf("%d * 17 should be: %d", c[i], (c[i] * 17));
    printf("\n");
    printf("Result: %d", constk_17(c[i]));
    printf("\n");
  }
  printf("\n");
  for (i = 0; i < 3; i++) {
    printf("%d * -7 should be: %d", c[i], (c[i] * -7));
    printf("\n");
    printf("Result: %d", constk_neg7(c[i]));
    printf("\n");
  }
  printf("\n");
  for (i = 0; i < 3; i++) {
    printf("%d * 60 should be: %d", c[i], (c[i] * 60));
    printf("\n");
    printf("Result: %d", constk_60(c[i]));
    printf("\n");
  }
  printf("\n");
  for (i = 0; i < 3; i++) {
    printf("%d * -112 should be: %d", c[i], (c[i] * -112));
    printf("\n");
    printf("Result: %d", constk_neg112(c[i]));
    printf("\n");
  }

  return 0;
}
