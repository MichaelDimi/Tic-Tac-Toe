#include "game.h"

int game_over(board_t board, int turn) {
  int is_complete = 1;

  char opp = turn ? 'O' : 'X';

  // Vertical Lines
  for (int i = 0; i < 3; i++) {
    is_complete = 1;
    for (int j = 0; j < 3; j++) {
      if (board[3 * j + i] == opp || board[3 * j + i] == ' ') {
        is_complete = 0;
      }
    }
    if (is_complete) {
      return 1;
    }
  }

  // Horizontal Lines
  for (int i = 0; i < 3; i++) {
    is_complete = 1;
    for (int j = 0; j < 3; j++) {
      if (board[3 * i + j] == opp || board[3 * i + j] == ' ') {
        is_complete = 0;
      }
    }
    if (is_complete) {
      return 1;
    }
  }

  // Diagonal Line (TL - BR)
  is_complete = 1;
  for (int i = 0; i < 3; i++) {
    if (board[3 * i + i] == opp || board[3 * i + i] == ' ') {
      is_complete = 0;
    }
  }
  if (is_complete) {
    return 1;
  }

  // Diagonal Line (TR - BL);
  is_complete = 1;
  for (int i = 1; i <= 3; i++) {
    if (board[2 * i] == opp || board[2 * i] == ' ') {
      is_complete = 0;
    }
  }
  if (is_complete) {
    return 1;
  }

  return 0;
}

