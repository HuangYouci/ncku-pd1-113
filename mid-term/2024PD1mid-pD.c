#include <stdio.h>

int main(){
    int n;

    // 輸入專注表格
    scanf("%d", &n);
    int attention[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &attention[i][j]);
        }
    }

    // // 預設輸入
    // n = 3;
    // int attention[3][3] = {1,1,1,1,1,5,1,1,1};

    // 枚舉
    // 有 n! 種排法
    // 先從人1開始

    // int temp[n][n];
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         temp[i][j] = attention[i][j];
    //     }
    // }

    // printf("=== ATTENTION ARRAY ===\n");
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         printf("[%d] ", attention[i][j]);
    //     }
    //     printf("\n");
    // }

    // 一階做法

    if( n == 1 ) printf("1\n");

    // 二階做法

    if ( n == 2 ){
        // [1] [5]
        // [3] [2]
        if(attention[0][0] + attention[1][1] >= attention[0][1] + attention[1][0]){
            printf("1 2");
        }else{
            printf("2 1");
        }
    }

    // 三階做法
    // 組合: 1,2,3; 1,3,2; 2,1,3; 2,3,1; 3,1,2; 3,2,1

    if ( n == 3 ){
        int maxiswhich = 1;
        int max = attention[0][0] + attention[1][1] + attention[2][2]; //1,2,3

        if(attention[0][0] + attention[1][2] + attention[2][1] > max){
            // 1 3 2
            maxiswhich = 2;
            max = attention[0][0] + attention[1][2] + attention[2][1];
        }

        if(attention[0][1] + attention[1][0] + attention[2][2] > max){
            // 2 1 3
            maxiswhich = 3;
            max = attention[0][1] + attention[1][0] + attention[2][2];
        }

        if(attention[0][1] + attention[1][2] + attention[2][0] > max){
            // 2 3 1
            maxiswhich = 4;
            max = attention[0][1] + attention[1][2] + attention[2][0];
        }

        if(attention[0][2] + attention[1][0] + attention[2][1] > max){
            // 3 1 2
            maxiswhich = 5;
            max = attention[0][2] + attention[1][0] + attention[2][1];
        }

        if(attention[0][2] + attention[1][1] + attention[2][0] > max){
            // 3 2 1
            maxiswhich = 6;
            max = attention[0][2] + attention[1][1] + attention[2][0];
        }

        switch(maxiswhich) {
            case 1:
                printf("1 2 3\n");
                break;
            case 2:
                printf("1 3 2\n");
                break;
            case 3:
                printf("2 1 3\n");
                break;
            case 4:
                printf("2 3 1\n");
                break;
            case 5:
                printf("3 1 2\n");
                break;
            case 6:
                printf("3 2 1\n");
                break;
        }
    }

    return 0;
}