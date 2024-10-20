#include <stdio.h>

int mixsumnumber(int input){
    int temp = 0;
    while(input>10){
        temp += input%10;
        input /= 10;
    }
    temp += input;
    return temp;
}

int main(){
    int input;
    scanf("%d", &input);
    while(input > 10){
        input = mixsumnumber(input);
    }
    printf("%d",input);
    return 0;
}