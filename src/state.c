#include "state.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snake_utils.h"

/* Helper function definitions */
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch);
static bool is_tail(char c);
static bool is_head(char c);
static bool is_snake(char c);
static char body_to_tail(char c);
static char head_to_body(char c);
static unsigned int get_next_row(unsigned int cur_row, char c);
static unsigned int get_next_col(unsigned int cur_col, char c);
static void find_head(game_state_t* state, unsigned int snum);
static char next_square(game_state_t* state, unsigned int snum);
static void update_tail(game_state_t* state, unsigned int snum);
static void update_head(game_state_t* state, unsigned int snum);

/* Task 1 */
game_state_t* create_default_state() {
  // TODO: Implement this function.
 game_state_t* state = malloc(sizeof(game_state_t));
 state->num_rows = 18;
 unsigned int num_cols = 20;
 char* initial_board = {
        "####################\n"
        "#                  #\n"
        "# d>D    *         #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "#                  #\n"
        "####################\n"
    };
 state->board = malloc(state->num_rows * sizeof(char*));
 for (unsigned int i = 0; i <  state->num_rows; i++) {
    state->board[i] = malloc((num_cols + 1) * sizeof(char));
    state->board[i][num_cols + 1] = '\0';
    strncpy(state->board[i], &initial_board[(num_cols + 1) * i], num_cols + 1);

    }
    state->num_snakes = 1;
    state->snakes = malloc(sizeof(snake_t));
    state->snakes[0].live = true;
    state->snakes[0].tail_row = 2;
    state->snakes[0].tail_col = 2;
    state->snakes[0].head_row = 2;
    state->snakes[0].head_col = 4;
    return state;
}

/* Task 2 */
void free_state(game_state_t* state) {
  // TODO: Implement this function.
    for (unsigned int i = 0; i < state->num_rows + 1; i++) {
    free(state->board[i]);
  }
  free(state->snakes);
  free(state->board);
  free(state);
  return;
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) {
  // TODO: Implement this function.
  if (state == NULL || state->board == NULL) {
    return;
  }
  for (unsigned int i = 0; i < state->num_rows; i++) {
      fprintf(fp, "%s", state->board[i]);
}
}

/*
  Saves the current state into filename. Does not modify the state object.
  (already implemented for you).
*/
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */

/*
  Helper function to get a character from the board
  (already implemented for you).
*/
char get_board_at(game_state_t* state, unsigned int row, unsigned int col) {
  return state->board[row][col];
}

/*
  Helper function to set a character on the board
  (already implemented for you).
*/
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch) {
  state->board[row][col] = ch;
}

/*
  Returns true if c is part of the snake's tail.
  The snake consists of these characters: "wasd"
  Returns false otherwise.
*/
static bool is_tail(char c) {
  // TODO: Implement this function.
  if (c == 'w' || c == 'a' || c == 's' || c == 'd') {
      return true;
  }
    return false;
}

/*
  Returns true if c is part of the snake's head.
  The snake consists of these characters: "WASDx"
  Returns false otherwise.
*/
static bool is_head(char c) {
  // TODO: Implement this function.
  if (c == 'W' || c == 'A' || c == 'S' || c == 'D' || c == 'x') {
      return true;
  }
  return false;
}

/*
  Returns true if c is part of the snake.
  The snake consists of these characters: "wasd^<v>WASDx"
*/
static bool is_snake(char c) {
  // TODO: Implement this function.
  if (is_tail(c) || is_head(c) || c == '^' || c == '<' || c == 'v' || c == '>') {
      return true;
  }
  return false;
}

/*
  Converts a character in the snake's body ("^<v>")
  to the matching character representing the snake's
  tail ("wasd").
*/
static char body_to_tail(char c) {
  // TODO: Implement this function.
  if (c == '^'){
      return 'w';
  }
  else if (c == '<'){
      return 'a';
  }
  else if (c == 'v'){
      return 's';
  }
  else if (c == '>'){
      return 'd';
  }
  fprintf(stderr, "undefined");
  abort();
}

/*
  Converts a character in the snake's head ("WASD")
  to the matching character representing the snake's
  body ("^<v>").
*/
static char head_to_body(char c) {
  // TODO: Implement this function.
  if (c == 'W'){
    return '^';
  }
  else if (c == 'A'){
    return '<';
  }
  else if (c == 'S'){
      return 'v';
  }
  else if (c == 'D'){
    return '>';
  }
  fprintf(stderr, "undefined");
  abort();
}

/*
  Returns cur_row + 1 if c is 'v' or 's' or 'S'.
  Returns cur_row - 1 if c is '^' or 'w' or 'W'.
  Returns cur_row otherwise.
*/
static unsigned int get_next_row(unsigned int cur_row, char c) {
  // TODO: Implement this function.
  if (c == 'v' || c == 's' || c == 'S') {
      return cur_row + 1;
    }
  else if (c == '^' || c == 'w' || c == 'W') {
      return cur_row - 1;
    }
  return cur_row;
}

/*
  Returns cur_col + 1 if c is '>' or 'd' or 'D'.
  Returns cur_col - 1 if c is '<' or 'a' or 'A'.
  Returns cur_col otherwise.
*/
static unsigned int get_next_col(unsigned int cur_col, char c) {
  // TODO: Implement this function.
  if (c == '>' || c == 'd' || c == 'D') {
    return cur_col + 1;
  }
  else if (c == '<' || c == 'a' || c == 'A') {
    return cur_col - 1;
  }
  return cur_col;
}

/*
  Task 4.2

  Helper function for update_state. Return the character in the cell the snake is moving into.

  This function should not modify anything.
*/
static char next_square(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  unsigned int cur_row = state->snakes[snum].head_row;
  unsigned int cur_col = state->snakes[snum].head_col;
  char head = get_board_at(state, cur_row, cur_col);
  unsigned int next_row = get_next_row(cur_row, head);
  unsigned int next_col = get_next_col(cur_col, head);
  return get_board_at(state, next_row, next_col);
}

/*
  Task 4.3

  Helper function for update_state. Update the head...

  ...on the board: add a character where the snake is moving

  ...in the snake struct: update the row and col of the head

  Note that this function ignores food, walls, and snake bodies when moving the head.
*/
static void update_head(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  unsigned int cur_row = state->snakes[snum].head_row;
  unsigned int cur_col = state->snakes[snum].head_col;
  char head = get_board_at(state, cur_row, cur_col);
  unsigned int next_row = get_next_row(cur_row, head);
  unsigned int next_col = get_next_col(cur_col, head);
  state->snakes[snum].head_row = next_row;
  state->snakes[snum].head_col = next_col;
  set_board_at(state, next_row, next_col, head);
  set_board_at(state, cur_row, cur_col, head_to_body(head));
  return;
}

/*
  Task 4.4

  Helper function for update_state. Update the tail...

  ...on the board: blank out the current tail, and change the new
  tail from a body character (^<v>) into a tail character (wasd)

  ...in the snake struct: update the row and col of the tail
*/
static void update_tail(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  unsigned int cur_row = state->snakes[snum].tail_row;
  unsigned int cur_col = state->snakes[snum].tail_col;
  char tail = get_board_at(state, cur_row, cur_col);
  unsigned int next_row = get_next_row(cur_row, tail);
  unsigned int next_col = get_next_col(cur_col, tail);
  state->snakes[snum].tail_row = next_row;
  state->snakes[snum].tail_col = next_col;
  char body = get_board_at(state, next_row, next_col);
  set_board_at(state, next_row, next_col, body_to_tail(body));
  set_board_at(state, cur_row, cur_col, ' ');
  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  // TODO: Implement this function.
  for (unsigned int snum = 0; snum < state->num_snakes; snum++){
    char next_square_char = next_square(state, snum);
    if (is_snake(next_square_char) || next_square_char == '#') {
        state->snakes[snum].live = false;
        set_board_at(state, state->snakes[snum].head_row, state->snakes[snum].head_col, 'x');
    }
    else if (next_square_char == '*') {
        update_head(state, snum);
        add_food(state);
    }
    if (next_square_char == ' ') {
        update_head(state, snum);
        update_tail(state, snum);
    }
    }
    return;
}

/* Task 5 */
game_state_t* load_board(FILE* fp) {
  // TODO: Implement this function.
  game_state_t* game = malloc(sizeof(game_state_t));
  if (game == NULL) {
    return NULL;
  }
  game->snakes = NULL;
  game->num_snakes = 0;
  int current_char;
  unsigned int cur_row = 0;
  unsigned int cur_col = 0;
  game->board = malloc(sizeof(char*));
  if (game->board == NULL) {
        free(game); 
        return NULL;
    }
  game->board[cur_row] = malloc(2 * sizeof(char));
  if (game->board[cur_row] == NULL) {
        free(game->board); 
        free(game);        
        return NULL;
    }
 
    while ((current_char =  fgetc(fp)) != EOF) {
    
    if (current_char == '\n') {
        cur_row++;
        game->board = realloc(game->board, (cur_row + 1) * sizeof(char*));
        
        game->board[cur_row] = calloc(1, sizeof(char));


        game->board[cur_row - 1][cur_col] = '\n';
      
        
        
        cur_col = 0;
        }
    else {
                cur_col++;
        game->board[cur_row] = realloc(game->board[cur_row], sizeof(char) * (cur_col + 2));
        
game->board[cur_row][cur_col - 1] = (char) current_char;


  }
    }
        if (current_char != EOF) {
    game->board[cur_row][cur_col] = '\0';
    }
    game->num_rows = cur_row;
   
    return game;
}
/*
  Task 6.1

  Helper function for initialize_snakes.
  Given a snake struct with the tail row and col filled in,
  trace through the board to find the head row and col, and
  fill in the head row and col in the struct.
*/
static void find_head(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  if (snum < 0 || snum >= state->num_snakes) {
    return;
  }
  if (!state->snakes[snum].live) {
    return;
  }
  unsigned int cur_row = state->snakes[snum].tail_row;
  unsigned int cur_col = state->snakes[snum].tail_col;
  char current_position = get_board_at(state, cur_row, cur_col);
  while (1) {
    if (!is_head(current_position)) {
        cur_row = get_next_row(cur_row, current_position);
        cur_col = get_next_col(cur_col, current_position);
        current_position = get_board_at(state, cur_row, cur_col);
        if (cur_row >= state->num_rows) {
            return;
        }

    } else {
          state->snakes[snum].head_row = cur_row;
            state->snakes[snum].head_col = cur_col;
        return;
    }
      }
  }

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
    state->num_snakes = 0;   
    state->snakes = malloc(sizeof(snake_t));
    if (state->snakes == NULL) {
        return NULL;
    }
    for (unsigned int i = 0; i < state->num_rows; i++) {
        for (unsigned int j = 0; state->board[i][j] != '\n'; j++) {
            char c = get_board_at(state, i, j);
            if (is_tail(c)) {
                state->num_snakes++;  

                
                state->snakes = realloc(state->snakes, (state->num_snakes) * sizeof(snake_t));

                
                state->snakes[state->num_snakes - 1].tail_row = i;
                state->snakes[state->num_snakes - 1].tail_col = j;

                
                state->snakes[state->num_snakes - 1].live = true; 
                find_head(state, state->num_snakes - 1);
                if (get_board_at(state, state->snakes[state->num_snakes - 1].head_row, state->snakes[state->num_snakes - 1].tail_row) == 'x') {
                    state->snakes[state->num_snakes - 1].live = false;
                }
            }
        }
    }

    return state;
}
