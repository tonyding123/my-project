#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
const int ROWS = 3;
const int COLS = 3;




void print_board(const char board[]) {
  for (int a = 0; a < ROWS; a++){
    for (int i = 0; i < COLS; i++){
      if (i == COLS - 1){
        printf(" %c ",board[a * COLS + i]);
      }
      else{ printf(" %c ", board[a * COLS + i]);
      printf("|");
      }
    }
    if (a < ROWS - 1){
    printf("\n--- --- ---\n");
    }
  }
  printf("\n\n\n");
}


bool fill_spot(char board[], const char player, const int row, const int col) {
  assert(row >= 0);
  assert(col >= 0);
  assert(row < ROWS);
  assert(col < COLS);
  if (board[row * COLS + col] == ' '){
    board[row * COLS + col] = player;
    return true;
  }
  else{
    return false;
  }
}


bool read_2ints(int* inp1, int* inp2) {
  if (scanf("%d %d", inp1, inp2) != 2) {
      return false; 
  } return true;
}




char who_won(const char board[]) {
  for (int i = 0; i < ROWS; i++){
    if (board[i * COLS + 0] != ' ' && ((board[i * COLS + 0] == board[i * COLS + 1]) && 
    (board[i * COLS + 1] == board[i * COLS + 2]))){
      return board[i * COLS + 0];
    }
  }
  for (int a = 0; a < COLS; a++){
    if (board[0 * COLS + a] != ' ' && ((board[0 * COLS + a] == board[1 * COLS + a]) && 
    (board[1 * COLS + a] == board[2 * COLS + a]))){
      return board[0 * COLS + a];
    }
  }
  if (board[0 * COLS + 0] != ' ' && ((board[0 * COLS + 0] == board[1 * COLS + 1]) && 
  (board[1 * COLS + 1] == board[2 * COLS + 2]))){
  return board[0 * COLS + 0];
  }
  if (board[0 * COLS + 2] != ' ' && ((board[0 * COLS + 2] == board[1 * COLS + 1]) && 
  (board[1 * COLS + 1] == board[2 * COLS + 0]))){
  return board[0 * COLS + 2];
  }
  return false;
}


bool draw(const char board[]) {
 for (int a = 0; a < COLS * ROWS; a++){
 if (board[a] == ' '){
   return false;
 }
 if (a == COLS * ROWS - 1){
   return who_won(board) == false && board[a] != ' ';
 }
 
}
return 0;
}



char switch_player(char curr_player) {
  if (curr_player == 'X') { return 'O'; }
  else { return 'X'; }
}




int main(void) {
  
  char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  
  printf("GAME START\n");
  print_board(board);
    
  bool keep_playing = true;
  char player = 'X';
    
  printf("It's player %c's turn!\n", player);
  
  while (keep_playing) {
      
    int row = 0;
    int col = 0;

    if (!(read_2ints(&row, &col))) { 
      break;
    }

    if (fill_spot(board, player, row, col)) {
      print_board(board);
        
      char winner = who_won(board);
      if (winner) { 
        printf("PLAYER %c WON!! :D\n", player);
        keep_playing = false;
      } else if (draw(board)) {
        printf("IT'S A TIE!\n");
        keep_playing = false;
      } 
      if (keep_playing) {
        player = switch_player(player);
        printf("It's player %c's turn!\n", player);
      }
    }
  }
    
}