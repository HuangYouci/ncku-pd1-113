#include <stdio.h>
#include <string.h>

int wait = 0;

void spilt(char *input, int total, int now, char all_testcase[59049][11]){
    // a
    // [ ][ ][ ] Input
    // [a][ ][ ] Output
    // printf("[ 2] 進入 spilt 且 input 目前為 %s，處理 %d/%d\n", input, now, total);

    input[now] = 'a';
    if(now == total){
            strcpy(all_testcase[wait], input);
            wait++;
        }else{
        spilt(input,total,(now+1), all_testcase);
    }

    input[now] = 'b';
    if(now == total){
            strcpy(all_testcase[wait], input);
            wait++;
        }else{
        spilt(input,total,(now+1), all_testcase);
    }

    input[now] = 'c';
    if(now == total){
            strcpy(all_testcase[wait], input);
            wait++;
        }else{
        spilt(input,total,(now+1), all_testcase);
    }

}

void GeneratingTest(int target_len, char all_testcase[59049][11]){
    char input[target_len];
    // printf("[1] 輸入 target_len: %d\n", target_len);
    spilt(input, (target_len-1), 0, all_testcase);

}