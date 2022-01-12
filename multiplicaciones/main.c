#include <stdio.h>
#include <string.h>

#define DIGITS 3
#define MAX_POSSIBLE_NUM 999

#define TERM_BLUE "\033[0;34m"
#define TERM_GREEN "\033[0;32m"
#define TERM_RESET "\033[0;0m"


int get_num(char *s) {
  int n = 0;
  while (1) {
    printf(s);
    scanf("%d", &n);
    if (n >= 0 && n <= MAX_POSSIBLE_NUM)
      break;
    else
      printf("Introduce un número que esté entre 0 y %d\n",
        MAX_POSSIBLE_NUM);
  }
}

void padding(int n) {
  for (int i = n; i > 0; i--)
    printf(" ");
}


void show_mult_header(int multiplicand, int multiplier) {
  printf(TERM_BLUE);
  
  padding(8);
  printf("  %3d\n", multiplicand);

  padding(8);
  printf("× %3d\n", multiplier);

  printf(TERM_RESET);
}

void show_result(int result) {
  padding(7);
  printf(TERM_GREEN);
  printf("%6d\n\n", result);
  printf(TERM_RESET);
}

void show_partial_mult(int line, int right_padding) {
  padding(10 - right_padding);
  printf("%4d", line);
  printf("\n");
}


void mult_step_by_step(int multiplicand, int multiplier) {
  char digits[DIGITS];
  sprintf(digits, "%d", multiplier);
  int multiplier_length = strlen(digits);

  show_mult_header(multiplicand, multiplier);
  
  if (multiplier > 9) {
    for (int i = multiplier_length - 1; i >= 0; i--) {
      int n = digits[i] - '0';
      int line = multiplicand * n;
      show_partial_mult(line, multiplier_length - i);
    }
  }

  show_result(multiplicand*multiplier);
}


int main() {
  int multiplicando = get_num("Multiplicando: ");
  int multiplicador = get_num("Multiplicador: ");

  mult_step_by_step(multiplicando, multiplicador);

  return 0;
}