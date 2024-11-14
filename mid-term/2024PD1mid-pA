#include <stdio.h>

int main(){
    // 輸入
    int input;
    scanf("%d",&input);
    // input = 12321;

    // 計算長度
    int temp, calN = 1;
    temp = input;
    while(temp > 10){
        calN++;
        temp /= 10;
    }

    // 變成陣列
    int calA[calN];
    temp = input;
    for(int i = (calN - 1) ; i >= 0 ; i--){
        calA[i] = (temp % 10);
        temp /= 10;
    }

    // 枚舉 //

    int ansArray[calN]; // 本陣列用於儲存答案，1 是可刪除使其變成回文
    for(int i = 0 ; i < calN ; i++) ansArray[i] = 0;

    int checkL[calN - 1];
    int checkR[calN - 1];
    int output[calN];

    int ansCount = 0;

    // 有 i 個數字，刪掉那個數字是否能形成回文的比較
    for(int i = 0 ; i < calN ; i++){

        // printf("\n 現在忽略第 %d 位 : %d\n", i, calA[i]);

        // 例如數字是 [1][2][3][2][1]
        // 目前的 i ：要忽略左至右第 i 位數字

        // 判斷從左至右
        for(int j = 0 , k = 0 ; j < calN  ; j++){
            if(j != i){
                checkL[k] = calA[j];
                k++;
            }
        }

        // 判斷由右到左
        for( int k = (calN - 1), j = 0 ; k >= 0 ; k--){
            if(k != i){
                checkR[j] = calA[k];
                j++;
            }
        }

        // 輸出兩個陣列測試
        // printf("checkL: ");
        // for(int j = 0 ; j < calN -1 ; j++){
        //     printf("[%d] ", checkL[j]);
        // }
        // printf("\n");
        // printf("checkR: ");
        // for(int j = 0 ; j < calN - 1 ; j++){
        //     printf("[%d] ", checkR[j]);
        // }

        // 當 checkL == checkR 時，形成回文

        temp = 0;
        for(int j = 0 ; j < calN - 1 ; j++){
            if(checkL[j] != checkR[j]) temp = 1;
        }
        if(temp == 0){
            // printf("\n刪除第 %d 位符合回文", i);
            ansCount++;
            ansArray[ansCount-1] = i; // 刪掉由左往右的第 i 位是符合的
        }
    }

    // printf("\n=== ANSARRAY ===\n");
    // for(int i = 0 ; i < ansCount ; i++){
    //     printf("%d ", ansArray[i]);
    // }
    // printf("\n\n === OUTPUT === \n");

    // 現在有了 ansArray，由左往右，要把它變成由右往左的第幾位？
    for(int i = 0 ; i < ansCount ; i++){
        // 假設原本 5 位，他是第 0 位代表他是 5-0 = 5
        // 第4位代表 5-4=1
        ansArray[i] = (calN - ansArray[i]);
    }

    // 列印
    for(int i = (ansCount - 1) ; i >= 0 ; i--){
        printf("%d ", ansArray[i]);
    }
    if (ansCount == 0) printf("Impossible\n");

    return 0;
}
