#include <stdio.h>
#include <stdlib.h>

typedef enum {
  EMPTY,
  X,
  O
} Cell;

typedef enum {
  PLAYING,
  X_WON,
  O_WON,
  DRAW
} Game_state;

#define GRID_SIZE 3

typedef struct {
  Cell grid[GRID_SIZE * GRID_SIZE];
  Game_state state;
} Game;


void game_loop(Game *game, int size);


void initialize_game(Game *game, int size) {
  game->state = PLAYING;
  for (int i = 0; i < size * size; i++)
    game->grid[i] = EMPTY;
}


void print_grid(Game *game, int size) {
  for (int i = 0; i < size * size; i++) {
    switch (game->grid[i]) {
      case EMPTY:
        printf("· ");
        break;
      case X:
        printf("X ");
        break;
      case O:
        printf("O ");
        break;
    }
    if ((i + 1) % size == 0)
      printf("\n");
  }
  printf("\n");
}

void print_end_game(Game *game) {
  if (game->state != DRAW)
    printf("¡Ganó el juador %d!\n", game->state);
  else
    printf("¡Empate!\n");
}


void ask_to_run_again(Game *game, int size) {
  char answer;
  printf("¿Desea jugar de nuevo? (s/N): ");
  scanf("%s", &answer);
  if (answer == 's') {
    initialize_game(game, size);
    game_loop(game, size);
  } else
    exit(0);
}


void get_input(Game *game, int size, int player) {
  int row, col;
  printf("Jugador %d\nIntroduce fila y columna: ", player);
  scanf("%d %d", &row, &col);
  --row; --col;
  if (game->grid[row * size + col] != EMPTY) {
    printf("\nMovimiento inválido.\n");
    get_input(game, size, player);
  } else
    game->grid[row * size + col] = player == 1 ? X : O;
}



void check_rows(Game *game, int size, int player) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (game->grid[i * size + j] != player)
        break;
      if (j == size - 1)
        game->state = player == 1 ? X_WON : O_WON;
    }
  }
}

void check_columns(Game *game, int size, int player) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (game->grid[j * size + i] != player)
        break;
      if (j == size - 1)
        game->state = player == 1 ? X_WON : O_WON;
    }
  }
}

void check_135_degree_diagonal(Game *game, int size, int player) {
  for (int i = 0; i < size; i++) {
    if (game->grid[i * size + i] != player)
      break;
    if (i == size - 1)
      game->state = player == 1 ? X_WON : O_WON;
  }
}

void check_45_degree_diagonal(Game *game, int size, int player) {
  for (int i = 0; i < size; i++) {
    if (game->grid[i * size + (size - 1 - i)] != player)
      break;
    if (i == size - 1)
      game->state = player == 1 ? X_WON : O_WON;
  }
}

void check_draw(Game *game, int size) {
  for (int i = 0; i < size * size; i++) {
    if (game->grid[i] == EMPTY)
      return;
  }
  game->state = DRAW;
}

void check_winner(Game *game, int size, int player) {
  check_rows(game, size, player);
  check_columns(game, size, player);

  check_135_degree_diagonal(game, size, player);
  check_45_degree_diagonal(game, size, player);

  check_draw(game, size);
}


void game_loop(Game *game, int size) {
  int player;
  while (game->state == PLAYING) {
    player = (player == X) ? O : X;
    get_input(game, size, player);
    print_grid(game, size);
    check_winner(game, size, player);
  }
  print_end_game(game);
  ask_to_run_again(game, size);
}

int main() {
  Game game;
  initialize_game(&game, GRID_SIZE);

  game_loop(&game, GRID_SIZE);

  return 1; // should never reach this point
}