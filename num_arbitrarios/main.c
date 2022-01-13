#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_DIGITS 1000

typedef struct {
  int8_t digits[MAX_DIGITS];
  int length;
} bignum[MAX_DIGITS];


void get_bignum(bignum n, char *prompt) {
  char c[MAX_DIGITS];
  printf(prompt);
  scanf("%s", c);
  int i = strlen(c);
  n->length = i;
  for (int j = 0; j < i; j++) {
    n->digits[j] = c[i - j - 1] - '0';
  }
}


void show_full_bignum(bignum n) {
  for (int i = n->length; i > 0; i--)
    printf("%d", n->digits[i-1]);
  printf("\n");
}

void show_bignum_abbr(bignum n) {
  for (int i = n->length - 1; i >= n->length - 5; i--)
    printf("%d", n->digits[i]);
  printf("...");
  for (int i = 5; i > 0; i--)
    printf("%d", n->digits[i-1]);
  printf("\n");
}


void sum_bignums_to(bignum sum, bignum a, bignum b) {
  int carry = 0;
  int i = 0;
  while (i < a->length || i < b->length) {
    int a_digit = 0;
    int b_digit = 0;
    if (i < a->length)
      a_digit = a->digits[i];
    if (i < b->length)
      b_digit = b->digits[i];
    int sum_digit = a_digit + b_digit + carry;
    carry = sum_digit / 10;
    sum->digits[i] = sum_digit % 10;
    i++;
  }
  sum->length = i;
}


int main() {
  bignum a, b, sum;

  get_bignum(a, "Primer gran número: ");
  get_bignum(b, "Segundo gran número: ");

  show_bignum_abbr(a);
  show_bignum_abbr(b);

  sum_bignums_to(sum, a, b);
  show_full_bignum(sum);

  return 0;
}