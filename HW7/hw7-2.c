#include <stdio.h>
#include <string.h>

char* getUserInput(){
    static char input[21];
    fgets(input, 21, stdin);
    size_t len = strlen(input);
    input[len - 1] = '\0';
    return input;
}

void printAllInput(char output[51][21], int num){
    for(int i = 0 ; i < num ; i++){
        printf("%s\n",output[i]);
    }
}