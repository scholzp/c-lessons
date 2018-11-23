#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

#define fps_cap 20;

int main(void){
  printf("\n");
  clock_t start_time, end_time, lap_time;
  unsigned long target_framerate = (unsigned long) CLOCKS_PER_SEC / fps_cap;
  char c;
  int pos_a, pos_b, pos_ball;
  int height = 23;
  int num_line_top = height / 2;
  int num_line_bot = height / 2;
  pos_a = pos_b = pos_ball = num_line_bot - 1;
  printf("Num lines: %d; half: %d", height, num_line_top);
  start_time = clock();
  char p1;
  initscr();
  while(1){
    if((clock() - start_time) % target_framerate == 0){
      clear();
      timeout(10);
      int p1 = getch();

      if(p1 == 'w'){
        ++num_line_bot;
        ++num_line_top;
      }else if(p1 == 's'){
        --num_line_bot;
        --num_line_top;
      }
      for(int i = 0; i < num_line_top-1; ++i)
      printf("\n");
      printf("|          %3d            |\n", p1);
    }
  }
  endwin();

  return 0;
}
