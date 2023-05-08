#ifndef GAME_H
#define GAME_H

#define START_BOARD {' ', ' ', ' ',\
                     ' ', ' ', ' ',\
                     ' ', ' ', ' '}

typedef char board_t[9];

typedef struct {
  int col;
  int row;
} move_t;

int game_over(board_t, int);

#endif
