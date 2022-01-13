#include <stdio.h>

typedef struct {
  unsigned int quantity, value;
  char *name;
} coin;


int main() {
  coin coins[] = {
    {0, 200, "dos euros"},
    {0, 100, "un euro"},
    {0,  50, "cincuenta céntimos"},
    {0,  20, "veinte céntimos"},
    {0,  10, "diez céntimos"},
    {0,   5, "cinco céntimos"},
    {0,   2, "dos céntimos"},
    {0,   1, "un céntimo"}
  };
  int coins_length = sizeof(coins) / sizeof(coin),
      coins_needed = 0;
  int pennies;

  printf("Indique la cantidad de céntimos: ");
  scanf("%d", &pennies);

  while (pennies != 0) {
    for (int i = 0; i < coins_length; i++) {
      if (pennies >= coins[i].value) {
        pennies -= coins[i].value;
        coins[i].quantity++;
        coins_needed++;
        break;
      }
    }
  }

  printf("Monedas necesarias: %d\n", coins_needed);

  for (int i = 0; i < coins_length; i++) {
    if (coins[i].quantity != 0)
      printf("  - %d de %s\n", coins[i].quantity, coins[i].name);
  }

  return 0;
}