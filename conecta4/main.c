#include <stdio.h>
#include <stdlib.h>

// Game states
#define PLAYING 0
#define WON_X 1
#define WON_O 2
#define DRAW 3

// A cell in the board
#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2


void initialize_board_with_size(int *board, int size) {
  for (int i = 0; i < size * size; i++)
    board[i] = EMPTY;
}


void print_board(int *board, int size) {
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
      // printf(" |%d:%d;%2d:", i, j, j * size + i);
      switch (board[i * size + j]) {
      case PLAYER_X:
        printf("X ");
        break;
      case PLAYER_O:
        printf("O ");
        break;
      default:
        printf("· ");
        break;
      }
    }
    printf("\n");
  }
  printf("\n");
}

void print_winner(int *board, int size, int *state) {
  print_board(board, size);
  switch (*state) {
  case WON_X:
    printf("¡X ha ganado!\n");
    break;
  case WON_O:
    printf("¡O ha ganado!\n");
    break;
  case DRAW:
    printf("¡Empate!\n");
    break;
  }
}


void get_board_size(int *size) {
  printf("Tamaño del tablero (mínimo 4): ");
  scanf("%d", size);
  while (*size < 4) {
    printf("\nTamaño inválido.\n");
    printf("Tamaño del tablero (mínimo 4): ");
    scanf("%d", size);
  }
}

int check_if_overflows(int *board, int size, int column) {
  return column < 0 || column > size; // || board[column] != EMPTY;
}

int get_player_move(int *board, int size, int turn) {
  int column;
  char player = turn == PLAYER_X ? 'X' : 'O';

  printf("Turno de %c. Columna: ", player);
  scanf("%d", &column);

  while (check_if_overflows(board, size, column)) {
    printf("\nMovimiento inválido.\n");
    printf("Turno de %c. Columna: ", player);
    scanf("%d", &column);
  }
  return --column;
}


int check_winner(int *board, int size, int player) {

  // four in a row
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if (board[i * size + j] == player)
        count++;
      else
        count = 0;
      if (count == 4)
        return player;
    }
  }

  // four in a column
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if (board[j * size + i] == player)
        count++;
      else
        count = 0;
      if (count == 4)
        return player;
    }
  }

  // four in a diagonal
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (board[i * size + i] == player)
      count++;
    else
      count = 0;
    if (count == 4)
      return player;
  }

  // comprobar si quedan casillas libres
  for (int i = 0; i < size * size; i++) {
    if (board[i] == EMPTY)
      return PLAYING;
  }

  return DRAW;
}


int slide_move_to_bottom(int *board, int size, int move, int turn) {
  int i = size - 1;
  while (i >= 0 && board[move * size + i] != EMPTY) {
    if (i == 0) {
      printf("\nColumna llena.\n");
      return -1;
    }
    i--;
  }
  board[move * size + i] = turn;
  return 1;
}


void game_loop(int *board, int size, int *state, int turn) {
  int move, full = 0;
  while (*state == PLAYING) {
    if (!full)
      print_board(board, size);
    full = 0;

    move = get_player_move(board, size, turn);
    
    // slide the move through the board
    full = slide_move_to_bottom(board, size, move, turn) == -1 ? 1 : 0;

    if (!full) {
      *state = check_winner(board, size, turn);
      turn = (turn == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
  }
}


int main() {
  int state = PLAYING;

  printf("Conecta 4\n");

  int size;
  get_board_size(&size);

  int board[size * size];
  initialize_board_with_size(board, size);

  game_loop(board, size, &state, PLAYER_X);
  print_winner(board, size, &state);

  return 0;
}