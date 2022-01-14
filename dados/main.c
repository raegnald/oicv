#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 6

typedef struct {
  unsigned int first_dices[SIZE];
  unsigned int second_dices[SIZE];
  unsigned int sum[SIZE * SIZE];
} dices;


void get_dices(unsigned int *dices, char *prompt) {
  char line[SIZE*5], *token;
  
  printf("%s: ", prompt);
  fgets(line, SIZE*5, stdin);

  token = strtok(line, " ");
  int i = 0;
  while (token != NULL) {
    dices[i] = atoi(token);
    token = strtok(NULL, " ");
    i++;
  }
}

void get_possibility_matrix(
  unsigned int *matrix,
  unsigned int *d1,
  unsigned int *d2) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      matrix[i * SIZE + j] = d1[i] + d2[j];
    }
  }
}

void sort_sum(unsigned int *arr) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (arr[i * SIZE + j] > arr[j * SIZE + i]) {
        unsigned int tmp = arr[i * SIZE + j];
        arr[i * SIZE + j] = arr[j * SIZE + i];
        arr[j * SIZE + i] = tmp;
      }
    }
  }
}

void check_fairness(unsigned int *sum1, unsigned int *sum2) {
  for (int i = 0; i < SIZE * SIZE; i++) {
    if (sum1[i] != sum2[i]) {
      printf("Juego injusto\n");
      return;
    }
  }
  printf("Juego justo\n");
}


int main() {
  dices marta, pablo;

  printf("Marta\n");
  get_dices(marta.first_dices, "Primeros dados");
  get_dices(marta.second_dices, "Segundos dados");

  printf("Pablo\n");
  get_dices(pablo.first_dices, "Primeros dados");
  get_dices(pablo.second_dices, "Segundos dados");

  get_possibility_matrix(marta.sum, marta.first_dices, marta.second_dices);
  get_possibility_matrix(pablo.sum, pablo.first_dices, pablo.second_dices);

  sort_sum(marta.sum);
  sort_sum(pablo.sum);

  check_fairness(marta.sum, pablo.sum);

  return 0;
}