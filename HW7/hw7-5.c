#include <stdio.h>
#include <string.h>

char* getAnswer2(char* testcase){
    int len = strlen(testcase);
    for(int i = 0 ; i < len ; i++){
        for(int j = 0 ; j < (len-1) ; j++){
            if((int)testcase[j] > (int)testcase[j+1]){
                char temp;
                temp = testcase[j];
                testcase[j] = testcase[j+1];
                testcase[j+1] = temp;
            }
        }
    }
    return testcase;
}