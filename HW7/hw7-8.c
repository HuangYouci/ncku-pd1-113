#include <stdio.h>
#include <string.h>
#include "hw7-1.h"
#include "hw7-2.h"
#include "hw7-3.h"
#include "hw7-4.h"
#include "hw7-5.h"
#include "hw7-6.h"
#include "hw7-7.h"
char all_testcase[59049][11];
char string1[51][21], string2[51][21];
char command[51][21];
int main() {
    int choose;
    while(1) {
        choose = GameStart(); 
        if( choose == -1 ) {
            printf("Please input 1 or 2 !\n");
        }
        else {
            printf("ok, you select the level %d\n", choose);
            break;
        }
    }

    printf("Please input all the commands\n");
    int command_cnt = 0;
    while(1) {
        strcpy(command[command_cnt],getUserInput());
        if( strcmp(command[command_cnt++], "exit") == 0 ) {
            command_cnt--;
            break;
        }
    }

    for(int i=0;i<command_cnt;i++) {
        ParsingData(command[i], string1[i], string2[i]);
    }

    int target_len, total = 1;
    printf("Please input the length of testcase\n");
    scanf("%d", &target_len);
    GeneratingTest(target_len, all_testcase);
    for(int i=0;i<target_len;i++) total *= 3;
    for(int i=0;i<total;i++) {
        printf("===============================Testcase %d===============================\n", i+1);
        printf("Input Data: %s\n", all_testcase[i]);
        char output[51] = {};
        strcpy(output, ProcessingCommand(string1, string2, all_testcase[i], command_cnt, 0));
        char answer[51] = {};
        if( choose == 1 ) {
            strcpy(answer, getAnswer1(all_testcase[i])); // level 1
        }
        else {
            strcpy(answer, getAnswer2(all_testcase[i])); // level 2
        }

        printf("Player Result: %s\n", output);
        printf("Answer: %s\n", answer);
        if( strcmp(output, answer) == 0 ) printf("Result: Accepted\n");
        else printf("Result: Wrong Answer\n");
    }

    return 0;
}