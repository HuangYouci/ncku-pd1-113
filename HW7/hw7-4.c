#include <stdio.h>
#include <string.h>


char* getAnswer1(char testcase[51]){
    int len = strlen(testcase);
    int aCounter = 0;
    for(int i = 0 ; i < len ; i++){
        // a5a5aaa5a
        // -aaaaa
        if((testcase[i] == 'a') && (testcase[i+1] == 'a')){
            testcase[i] = ' ';
            aCounter = 1;
        }
        if(aCounter == 1 && (testcase[i+1] != 'a')){
            testcase[i] = ' ';
            aCounter = 0;
        }
        if(aCounter == 1 && (testcase[i] == 'a') && (testcase[i+1] == '\0')){
            testcase[i] = ' ';
            aCounter = 0;
        }
    }
    for(int j = 0 ; j < len ; j++){
        for(int i = 0 ; i < len ; i++){
            if(testcase[i] == ' '){
                char temp = testcase[i];
                testcase[i] = testcase[i+1];
                testcase[i+1] = temp;
            }
        }
    }
    return testcase;
}