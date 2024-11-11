#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int height[n][m];

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            scanf("%d", &height[i][j]);
        }
    }

    // ATTO: print
    // printf("\n-=*= Beautiful Sky =*=-\n");
    // for (int i = 0 ; i < n ; i++){
    //     for (int j = 0 ; j < m ; j++){
    //         printf("[%d] ", height[i][j]);
    //     }
    //     printf("\n");
    // }

    int temp;

    // 北南天際線（列）
    int nsSkyline[n];
    for(int i = 0; i < m ; i++){
        temp = 0;
        for(int j = 0; j < n ; j++){
            if (height[i][j] > temp) temp = height[i][j];
        }
        nsSkyline[i] = temp;
    }

    // 東西天際線（列）
    int ewSkyline[n];
    for(int i = 0; i < n ; i++){
        temp = 0;
        for(int j = 0; j < m ; j++){
            if (height[j][i] > temp) temp = height[j][i];
        }
        ewSkyline[i] = temp;
    }
    
    // ATTO: CHECK
    // printf("\nnsSkyline:\n");
    // for(int i = 0; i < m; i++){
    //     printf("%d,", nsSkyline[i]);
    // }
    // printf("\newSkyline:\n");
    // for(int i = 0; i < m; i++){
    //     printf("%d,", ewSkyline[i]);
    // }
    // printf("\n");

    // ADD TIME
    int add = 0, canbeadd = 0;
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < m ; j++){
            canbeadd = 0;
            // 逐格判斷（假設是第一格）
            // 他不能超過所屬NS（列）天際線 ==
            // 他不能超過所屬EW（行）天際線 ||
            // 所以他能加到所屬 NS 和 EW 的最小
            // 他所屬於 i (NS)行 j (EW)列
            if (nsSkyline[i] < ewSkyline[j]){
                canbeadd = nsSkyline[i];
            }else{
                canbeadd = ewSkyline[j];
            }
            // 現在 canbeadd 是他能加到的最大值了
            // 所以他能變多的單位是 canbeadd - 自己
            add += (canbeadd - height[i][j]);
        }
    }

    printf("%d", add);

    return 0;

    // finished HW5 by huangyouci at 2024.11.08 01:49
}