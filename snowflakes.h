#ifndef SNOW_FLAKES
#define SNOW_FLAKES

#include <stdio.h>
#include <math.h>

#define FONT_WIDTH_PX       8
#define FONT_HEIGHT_PX      17
#define SIZE                500

#define RATIO               (FONT_HEIGHT_PX/FONT_WIDTH_PX)

#define PI                  3.1415926

#define WIDTH_CHAR_COUNT    (SIZE/(FONT_WIDTH_PX*RATIO))
#define HEIGHT_CHAR_COUNT   (SIZE/FONT_HEIGHT_PX)
// #define CHAR_COUNT        ((int)round(((double)FONT_HEIGHT_PX/(double)(FONT_WIDTH_PX*RATIO))))

typedef struct {
  int x;
  int y;
} ORIGIN;

void CreateColumns(ORIGIN srcPoint, int length, int angle, char ptrn);
void CreateNeedles(int distance, int length, int angle, char ptrn);

#endif