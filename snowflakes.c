#include "snowflakes.h"

char snowFlake[HEIGHT_CHAR_COUNT][WIDTH_CHAR_COUNT][RATIO] = {0};
ORIGIN origin = {WIDTH_CHAR_COUNT/2, HEIGHT_CHAR_COUNT/2};

const int hexagon[6] = {30, 90, 150, 210, 270, 330};

int main() {
  for(int h=0; h<HEIGHT_CHAR_COUNT; h++) {
    for(int w=0; w<WIDTH_CHAR_COUNT; w++) {
      for(int c=0; c<2; c++) {
        snowFlake[h][w][c] = ' ';
      }
    }
  } 

  CreateColumns(origin, 200, 30, '.');
  CreateColumns(origin, 200, 90, '.');
  CreateColumns(origin, 200, 150, '.');
  CreateColumns(origin, 200, 210, '.');
  CreateColumns(origin, 200, 270, '.');
  CreateColumns(origin, 200, 330, '.');
  
  CreateNeedles(50, 30, 35, '#');
  CreateNeedles(90, 50, 45, ':');
  CreateNeedles(150, 45, 55, '*');

  for(int h=0; h<HEIGHT_CHAR_COUNT; h++) {
    for(int w=0; w<WIDTH_CHAR_COUNT; w++) {
      for(int c=0; c<2; c++) {
        printf("%c", snowFlake[h][w][c]);
      }
    }
    printf("\n");
  }

  // while(1) {}

  return 0;
}


void CreateColumns(ORIGIN srcPoint, int length, int angle, char ptrn) {
  ORIGIN desPoint;
  int tmp;
  for(int L=0; L<length; L++) {
    tmp = srcPoint.y + round((L * sin(angle*PI/180)) / FONT_HEIGHT_PX);
    if(tmp >= 0 && tmp <= HEIGHT_CHAR_COUNT) {
      desPoint.y = tmp;
    } else {
      desPoint.y = 0;
    }
    tmp = srcPoint.x + round((L * cos(angle*PI/180)) / (FONT_WIDTH_PX*RATIO));
    if(tmp >= 0 && tmp <= WIDTH_CHAR_COUNT) {
      desPoint.x = tmp;
    } else {
      desPoint.x = 0;
    }
    snowFlake[desPoint.y][desPoint.x][0] = ptrn;
    snowFlake[desPoint.y][desPoint.x][1] = ptrn;
  }
}

void CreateNeedles(int distance, int length, int angle, char ptrn) {
  ORIGIN desPoint;
  int tmp;
  for(int i=0; i<6; i++) {
    tmp = origin.y + round((distance * sin(hexagon[i]*PI/180)) / FONT_HEIGHT_PX);
    if(tmp >= 0 && tmp <= HEIGHT_CHAR_COUNT) {
      desPoint.y = tmp;
    } else {
      desPoint.y = 0;
    }
    tmp = origin.x + round((distance * cos(hexagon[i]*PI/180)) / (FONT_WIDTH_PX*RATIO));
    if(tmp >= 0 && tmp <= WIDTH_CHAR_COUNT) {
      desPoint.x = tmp;
    } else {
      desPoint.x = 0;
    }
    CreateColumns(desPoint, length, angle+hexagon[i], ptrn);
    CreateColumns(desPoint, length, -angle+hexagon[i], ptrn);
  }
}