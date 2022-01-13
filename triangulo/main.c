#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    // spaces
    for (int j = 0; j < n - i - 1; j++)
      printf(" ");

    // stars and o's
    for (int j = 0; j < i*2 + 1; j++) {
      if (j % 2 == 0)
        printf("*");
      else
        printf("o");
    }

    printf("\n");
  }

  return 0;
}