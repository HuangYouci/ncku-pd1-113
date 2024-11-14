#include <stdio.h>

int main(){
    int n, m; // n 是稻田長度、m 是跳躍次數
    scanf("%d %d\n", &n, &m);


    // 輸入稻田
    char field[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%c", &field[i]);
    }

    // 輸入跳躍

    char jumpTemp1;
    int jump[m], jumpTemp2;

    for(int i = 0 ; i < m ; i++){
        scanf("\n%c %d", &jumpTemp1, &jumpTemp2);
        // printf("輸入第 %d 次 : %d %d\n", (i+1) , jumpTemp1, jumpTemp2);
        if(jumpTemp1 == 'L') jump[i] = -jumpTemp2;
        if(jumpTemp1 == 'R') jump[i] = jumpTemp2;
    }

    // 列印稻田
    // printf("\n=== FIELD ===\n");
    // for(int i = 0 ; i < n ; i++){
    //     printf("%c", field[i]);
    // }

    // 列印跳躍次數
    // printf("\n=== JUMP ===\n");
    // for(int i = 0 ; i < m ; i++){
    //     printf("[%d] ", jump[i]);
    // }
    // printf("\n\n");

    // 開始跳躍
    int whereIsV = 0; // V 的位置
    for (int i = 0 ; i < m ; i++){
        // 資訊
        // 現在是第 i 次跳躍 共 m 次
        // printf("\n現在是第 %d / %d 次跳躍\n", i+1, m);
        // 現在要進行跳躍範圍
        // printf("現在要跳 %d 格\n", jump[i]);

        // 找到「V」在哪並移動他
        for(int j = 0 ; j < n ; j++){
            if(field[j] == 'V'){
                whereIsV = j;
                field[j] = '.';
                // 找到了，V 在 j 處。把 V 處變成「.」
                // printf("V 現在在 %d 處，whereIsV %d。\n", j, whereIsV);
            }
        }
        // 把 V 移動
        whereIsV += jump[i];
        // 判斷若 whereIsV 小於 0 或是大於等於 n：out of range
        if(whereIsV < 0 || whereIsV >= n){
            printf("Out of range\n");
            whereIsV -= (jump[i]);
            // printf("因為超出範圍。whereIsV 不變，仍為 %d。\n", whereIsV);
            continue;
        }
        
        field[whereIsV] = 'V';
        // printf("V 移動 %d 格，到了 %d。\n", jump[i], whereIsV);

        // 列印稻田
        // printf("現在的稻田是\n");
        for(int j = 0 ; j < n ; j++){
            printf("%c", field[j]);
        }
        printf("\n");
    }

    return 0;
}