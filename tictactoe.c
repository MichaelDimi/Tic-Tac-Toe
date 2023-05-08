#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ncurses.h>

#include "game.h"

void print_board(board_t board) {
  system("clear");

  printf("   1   2   3\n");
  printf("1  %c | %c | %c \n", board[0], board[1], board[2]);
  printf("  -----------\n");
  printf("2  %c | %c | %c \n", board[3], board[4], board[5]);
  printf("  -----------\n");
  printf("3  %c | %c | %c \n", board[6], board[7], board[8]);
}

void swap_turn(int *turn_ptr) {
  *turn_ptr = !(*turn_ptr);
}

void place_move(board_t *board, move_t move, int turn) {
  (*board)[3 * (move.row - 1) + (move.col - 1)] = turn ? 'X' : 'O';
}

move_t query_move(board_t board) {
  move_t move;

  // Loop until a valid move is found
  do {
    move.row = 0;
    move.col = 0;
    int status = 0;

    // Get Row
    while (status != 1) {
      printf("Row: ");
      status = scanf("%d", &move.row);
      if (status != 1) {
        printf("Error: Must be a number\n");
        while (getchar() != '\n');
      } else if (move.row < 1 || move.row > 3) {
        printf("Error: Out of range\n");
        while (getchar() != '\n');
        status = 0;
      }
    }

    // Get Column
    status = 0;
    while (status != 1) {
      printf("Column: ");
      status = scanf("%d", &move.col);
      if (status != 1) {
        printf("Error: Must be a number\n");
        while (getchar() != '\n');
      } else if (move.col < 1 || move.col > 3) {
        printf("Error: Out of range\n");
        while (getchar() != '\n');
        status = 0;
      }

    }
  } while (board[3 * (move.row - 1) + (move.col - 1)] != ' ');

  return move;
}

int main() {
  board_t board = START_BOARD;

  int turn = 0; // 0 is O, 1 is X

  // Game Loop
  while (1) {
    int is_cat = 1;
  
    print_board(board);

    printf("%c's turn\n", turn ? 'X' : 'O');
    move_t move = query_move(board);
    place_move(&board, move, turn);
    
    // Print board after piece placement
    print_board(board);

    // Evaluate Game Over
    if (game_over(board, turn)) {
      printf("%c Wins!\n", turn ? 'X' : 'O');
      break;
    }
    
    // Evaluate Cat's Game
    for (int i = 0; i < 9; i++) {
      if (board[i] == ' ') {
        is_cat = 0;
      }
    }
    if (is_cat) {
      printf("Cat's Game!\n");
      break;
    }

    // Swap Turns
    turn = !turn;
  }
}
