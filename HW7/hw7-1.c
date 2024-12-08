#include <stdio.h>

int GameStart(){
    int input;
    printf("Welcome to the game A = B, please select the level\n");
    scanf("%d",&input);
    getchar();
    return (input == 1 || input == 2)? input : -1;
}