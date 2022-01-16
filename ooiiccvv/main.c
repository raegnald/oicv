#include <stdio.h>


void get_amounts(unsigned int t, unsigned int *o, unsigned int *i, unsigned int *c, unsigned int *v) {
  for (int n = 0; n < t; n++)
    scanf("%u %u %u %u", &o[n], &i[n], &c[n], &v[n]);
}


void show_while_true_decr(char str, unsigned int *arr, unsigned int n) {
  while (arr[n] > 0) {
    printf("%c", str);
    arr[n]--;
  }
}

void show_letters(unsigned int t, unsigned int *o, unsigned int *i, unsigned int *c, unsigned int *v) {
  for (int n = 0; n < t; n++) {
    show_while_true_decr('O', o, n);
    show_while_true_decr('I', i, n);
    show_while_true_decr('C', c, n);
    show_while_true_decr('V', v, n);
    printf("\n");
  }
}

int main() {
  unsigned int t;
  scanf("%d", &t);
  
  unsigned int o[t], i[t], c[t], v[t];
  get_amounts(t, o, i, c, v);

  show_letters(t, o, i, c, v);

  return 0;
}

// 9:22
// 9:32  -> 10 min
// 9:43  -> 11 min  + -> 22 min