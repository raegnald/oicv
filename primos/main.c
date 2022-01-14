#include <stdio.h>


int is_prime(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

void get_all_lines(int t, int *n, int *k) {
  for (int i = 0; i < t; i++)
    scanf("%d %d", &n[i], &k[i]);
}

void show_prime_list(int i, int n, int k) {
  int j = n + 1,
      x = 0;
  while (x < k) {
    if (is_prime(j)) {
      printf("%d ", j);
      x++;
    }
    j++;
  }
  printf("\n");
}

void process_lines(int t, int *n, int *k) {
  for (int i = 0; i < t; i++) {
    if (k[i] > 0)
      show_prime_list(i, n[i], k[i]);
    if (k[i] == 0)
      is_prime(n[i]) ? printf("SI\n") : printf("NO\n");
  }
}

int main() {
  int t;
  scanf("%d", &t);

  int n[t], k[t];
  
  get_all_lines(t, n, k);
  process_lines(t, n, k);

  return 0;
}