#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../library/functions.h"

#if (_WIN16 || _WIN32)
#define clear "cls"
#else
#define clear "clear"
#endif

int main(int argc, const char * argv[]) {
    char **game, player='X', *string;
    int i, j, cells=0, winI, winJ;
    _Bool isRunning=1, ok=0, ok2=0, isPlayerX=1, win=0, start=1;
    game=(char**)malloc(3*sizeof(char*));
    if (!game) {
        fprintf(stderr, "\n\nInsuficient memory.\n\n");
        exit(EXIT_FAILURE);
    }
    for (i=0; i<3; i++) {
        game[i]=(char*)malloc(3*sizeof(char));
        if (!game[i]) {
            fprintf(stderr, "\n\nInsuficient memory.\n\n");
            exit(EXIT_FAILURE);
        }
    }
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            game[i][j]=' ';
        }
    }
    while (isRunning) {
        win=checkWin(game, &winI, &winJ);
        if (win) {
            break;
        }
        if (isPlayerX) {
            player='X';
            isPlayerX=0;
        } else {
            player='O';
            isPlayerX=1;
        }
        do {
            system(clear);
            printMap(game, start);
            printf("\n\n   player: %c", player);
            if (ok) {
                printf("\n\n");
                if (!ok2) {
                    printf("Invalid move");
                } else {
                    printf("Cell it not empty");
                }
            }
            printf("\n\nInsert cell number\n\n> ");
            string=getNrString(2);
            if (strlen(string)==1) {
                ok=0;
                ok2=0;
                i=-1;
                j=-1;
                switch (string[0]) {
                    case '1':
                        i=0;
                        j=0;
                        break;
                    case '2':
                        i=0;
                        j=1;
                        break;
                    case '3':
                        i=0;
                        j=2;
                        break;
                    case '4':
                        i=1;
                        j=0;
                        break;
                    case '5':
                        i=1;
                        j=1;
                        break;
                    case '6':
                        i=1;
                        j=2;
                        break;
                    case '7':
                        i=2;
                        j=0;
                        break;
                    case '8':
                        i=2;
                        j=1;
                        break;
                    case '9':
                        i=2;
                        j=2;
                        break;
                    default:
                        ok=1;
                        break;
                }
                if (!ok) {
                    if (game[i][j]==' ') {
                        game[i][j]=player;
                    } else {
                        ok=1;
                        ok2=1;
                    }
                }
            } else {
                ok2=0;
                ok=1;
            }
            free(string);
            string=0;
        } while (ok);
        cells++;
        if (cells==9) {
            isRunning=0;
        }
        start=0;
    }
    system(clear);
    if (win) {
        printf("\n    %c win\n", player);
    } else {
        printf("\n      draw\n");
    }
    editMap(game, &winI, &winJ);
    printMap(game, start);
    for (i=0; i<3; i++) {
        free(game[i]);
        game[i]=0;
    }
    printf("\n\n");
    free(game);
    game=0;
    printf("Press enter to close ... ");
    string=getNrString(0);
    free(string);
    string=0;
    system(clear);
    return 0;
}
