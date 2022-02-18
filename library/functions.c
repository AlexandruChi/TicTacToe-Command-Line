#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void printMap(char **game, _Bool start) {
    if (start) {
        printf(MAP, '1', '2', '3', '4', '5', '6', '7', '8', '9');
    } else {
    printf(MAP, game[0][0], game[0][1], game[0][2], game[1][0], game[1][1], game[1][2], game[2][0], game[2][1], game[2][2]);
    }
}

char *getNrString(int characterNumber) {
    char *a, b;
    int i=0;
    a=(char*)malloc(2*sizeof(char));
    if (!a) {
        fprintf(stderr, "\n\nInsuficient memory.\n\n");
        exit(EXIT_FAILURE);
    }
    do {
        b=getchar();
        if (i<characterNumber && b!='\n') {
            a[i]=b;
            a[i+1]='\0';
            a=(char*)realloc(a,(strlen(a)+1)*sizeof(char));
            i++;
        }
    } while (b!='\n');
    return a;
}

_Bool checkWin(char **map, int *a, int *b) {
    int i;
    char player;
    for (i=0; i<3; i++) {
        if (map[i][0]=='X' || map[i][0]=='O') {
            player=map[i][0];
            if (map[i][1]==player && map[i][2]==player) {
                *a=i;
                *b=1;
                return 1;
            }
        }
        if (map[0][i]=='X' || map[0][i]=='O') {
            player=map[0][i];
            if (map[1][i]==player && map[2][i]==player) {
                *a=i;
                *b=2;
                return 1;
            }
        }
    }
    if (map[0][0]=='X' || map[0][0]=='O') {
        player=map[0][0];
        if (map[1][1]==player && map[2][2]==player) {
            *a=0;
            *b=3;
            return 1;
        }
    }
    if (map[2][0]=='X' || map[2][0]=='O') {
        player=map[2][0];
        if (map[1][1]==player && map[0][2]==player) {
            *a=2;
            *b=3;
            return 1;
        }
    }
    return 0;
}

void editMap(char **map, int *a, int *b) {
    int i;
    if (*b==1) {
        for (i=0; i<3; i++) {
            map[*a][i]='-';
        }
    } else if (*b==2) {
        for (i=0; i<3; i++) {
            map[i][*a]='|';
        }
    } else if (*b==3) {
        if (*a==0) {
            map[0][0]='\\';
            map[1][1]='\\';
            map[2][2]='\\';
        } else if (*a==2) {
            map[2][0]='/';
            map[1][1]='/';
            map[0][2]='/';
        }
    }
}
