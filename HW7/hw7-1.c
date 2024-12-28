#include <stdio.h>
#include <string.h>

int GameStart(){
    printf("Welcome to the game A = B, please select the level\n");
    char input[100] = "";
    scanf("%s",input);
    getchar();
    int result = 0;
    for(int i=0;i<100;i++){
        result += input[i];
    }
    if(result == 49) return 1;
    else if(result == 50) return 2;
    else return -1;
}