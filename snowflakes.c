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

  CreateColumns(origin, 400, 30, '0');
  CreateColumns(origin, 400, 90, '0');
  CreateColumns(origin, 400, 150, '0');
  CreateColumns(origin, 400, 210, '0');
  CreateColumns(origin, 400, 270, '0');
  CreateColumns(origin, 400, 330, '0');
  
  CreateNeedles(50, 50, 35, '#');
  CreateNeedles(90, 80, 45, 'x');
  CreateNeedles(150, 120, 55, ':');

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
  for(int L=0; L<length; L++) {
    desPoint.y = srcPoint.y + round((L * sin(angle*PI/180)) / FONT_HEIGHT_PX);
    desPoint.x = srcPoint.x + round((L * cos(angle*PI/180)) / (FONT_WIDTH_PX*RATIO));
    snowFlake[desPoint.y][desPoint.x][0] = ptrn;
    snowFlake[desPoint.y][desPoint.x][1] = ptrn;
  }
}

void CreateNeedles(int distance, int length, int angle, char ptrn) {
  ORIGIN desPoint;
  for(int i=0; i<6; i++) {
    desPoint.y = origin.y + round((distance * sin(hexagon[i]*PI/180)) / FONT_HEIGHT_PX);
    desPoint.x = origin.x + round((distance * cos(hexagon[i]*PI/180)) / (FONT_WIDTH_PX*RATIO));
    CreateColumns(desPoint, length, angle+hexagon[i], ptrn);
    CreateColumns(desPoint, length, -angle+hexagon[i], ptrn);
  }
}