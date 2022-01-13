#include <stdio.h>

typedef struct {
  int start_pos;
  int jump_size;
} kangaroo;


void get_kangaroo_info(kangaroo *k, char *header) {
  printf("%s\n", header);
  printf("Posicion inicial: ");
  scanf("%d", &k->start_pos);
  printf("Longitud del salto: ");
  scanf("%d", &k->jump_size);
}


// Greatest common divisor
// Aka. Máximo común divisor
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}


void determine_if_kangaroos_meet(kangaroo *k1, kangaroo *k2) {
  int gcd_jump_size = gcd(k1->jump_size, k2->jump_size);
  int k1_pos = k1->start_pos,
      k2_pos = k2->start_pos;

  int i = (k1_pos < k2_pos) ? k1_pos : k2_pos;
  while (k1_pos != k2_pos && i < sizeof(int)) {
    i++;
    k1_pos += k1->jump_size;
    k2_pos += k2->jump_size;
    if (k1_pos >= k2_pos && k1_pos % gcd_jump_size == 0) {
        printf("Se verán al mismo tiempo en la posición %d\n", k1_pos);
        return;
    }
  }
  printf("Nunca se verán al mismo tiempo\n");
}


int main() {
  kangaroo k1, k2;

  get_kangaroo_info(&k1, "Canguro 1");
  get_kangaroo_info(&k2, "Canguro 2");

  determine_if_kangaroos_meet(&k1, &k2);

  return 0;
}