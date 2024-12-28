#include <stdio.h>
#include <math.h>

double power(double x, int n){
    // double answer = 1;
    // for(;n>0;n--){
    //     answer *= x;
    // }
    // return answer;
    return pow(x,n);
}

double multiply(double x, int n){
    return x*n;
}

double divide(double x, int n){
    return x/n;
}

double powerpower(double (*f)(double, int), double x, int n, int m){
    // double answer = 1;
    // for(;m>0;m--){
    //     answer *= f(x,n);
    // }
    // return answer;
    return pow(f(x,n),m);
}

double powermultiply(double (*f)(double, int), double x, int n, int m){
    return f(x,n)*m;  
}

double powerdivide(double (*f)(double, int), double x, int n, int m){
    return f(x,n)/m;
}

int transferArgvToInt(char *input){
    int output = 0;
    int cur = 0;
    while(input[cur] != '\0'){
        output *= 10;
        output += ((int)input[cur]-48);
        cur++;
    }
    return output;
}

double transferArgvToDouble(char *input){
    // 先找找看這是不是小數
    int checkcur = 0;
    int check = 0;
    while(input[checkcur] != '\0'){
        if(input[checkcur] == '.') {
            check = 1;
            break;
        }
        checkcur++;
    }
    if(check == 0){
        return transferArgvToInt(input);
    }

    // 假設輸入 15.28
    double output = 0;
    int cur = 0;
    // 先算整數位
    while(input[cur] != '.'){
        output *= 10;
        output += ((int)input[cur]-48);
        cur++;
    }
    // 再算小數位
    // 現在 output 是 15，cur 在 .
    cur++;
    // cur 在小數第一位了，記錄小數第一位是 semiOne
    int semiOne = cur;
    // 往後到最後一位
    while(input[cur] != '\0'){
        cur++;
    }
    // 此時 cur 是 \0，把它往前一位
    cur--;
    // 現在是15.[2][8]
    // 這個迴圈算小數點
    double semi = 0;
    for(;cur>=semiOne;cur--){
        semi += ((int)input[cur]-48);
        // 變成 8 , 變成 2.8
        semi /= 10;
        // 變成 0.8 // 變成 0.28
    }
    output += semi;
    return output;
}

int main(int argc, char *argv[]){
    double x = transferArgvToDouble(argv[1]);
    int n = transferArgvToInt(argv[2]);
    int m = transferArgvToInt(argv[3]);
    printf("%f\n", powerpower(power,x,n,m));
    printf("%f\n", powerpower(multiply,x,n,m));
    printf("%f\n", powerpower(divide,x,n,m));
    printf("%f\n", powermultiply(power,x,n,m));
    printf("%f\n", powermultiply(multiply,x,n,m));
    printf("%f\n", powermultiply(divide,x,n,m));
    printf("%f\n", powerdivide(power,x,n,m));
    printf("%f\n", powerdivide(multiply,x,n,m));
    printf("%f\n", powerdivide(divide,x,n,m));
    return 0;
}