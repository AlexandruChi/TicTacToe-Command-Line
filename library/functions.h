#ifndef functions_h
#define functions_h

#include <stdlib.h>

#define MAP "\n   %c | %c | %c\n  ---*---*---\n   %c | %c | %c\n  ---*---*---\n   %c | %c | %c"

void printMap(char **game, _Bool start);
char *getNrString(int characterNumber);
_Bool checkWin(char **map, int *a, int *b);
void editMap(char **map, int *a, int *b);

#endif
