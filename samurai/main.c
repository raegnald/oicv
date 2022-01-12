#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEAM_SIZE 7
#define TEAM_MAX_POWER 30

#define LINE_LENGTH 100


int sum(int *arr) {
  int sum = 0;
  for (int i = 0; i < TEAM_SIZE; i++)
    sum += arr[i];
  return sum;
}

void get_line(int *arr) {
  char line[LINE_LENGTH],
      *token;
  int i = 0;

  fgets(line, LINE_LENGTH, stdin);

  token = strtok(line, " ");
  while (token != NULL) {
    arr[i] = atoi(token);
    i++;
    token = strtok(NULL, " ");
  }
}

void get_team(int *team) {
  while (1) {    
    printf("Ingrese la potencia de los samuráis: ");
    get_line(team);

    if (sum(team) == TEAM_MAX_POWER)
      break;
    else
      printf("La suma de las potencias debe ser %d\n", TEAM_MAX_POWER);
  }
}



int main() {
  int team1[TEAM_SIZE],
      team2[TEAM_SIZE];

  printf("Equipo 1\n");
  get_team(team1);

  printf("Equipo 2\n");
  get_team(team2);

  int n = rand() % TEAM_SIZE;
  int team1_wins = 0,
      team2_wins = 0;

  printf("Empezamos la batalla con el samurái %d\n", n);

  for (int i = 0; i < TEAM_SIZE; i++) {
    printf("Samuráis %d: ", n + 1);
    if (team1[n] > team2[n]) {
      printf("%d gana a %d\n", team1[n], team2[n]);
      team1_wins++;
    } else if (team1[n] < team2[n]) {
      printf("%d gana a %d\n", team2[n], team1[n]);
      team2_wins++;
    } else {
      printf("%d empata con %d\n", team1[n], team2[n]);
    }

    n = (n + 1) % TEAM_SIZE;
  }

  if (team1_wins > team2_wins)
    printf("El equipo 1 gana, y el equipo 2 tiene %d bajas\n",
      team1_wins - team2_wins + 1);
  else if (team1_wins < team2_wins)
    printf("El equipo 2 gana, y el equipo 1 tiene %d bajas\n",
      team2_wins - team1_wins + 1);
  else
    printf("Empate");


  return 0;
}