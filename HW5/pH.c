#include <stdio.h>

int height[2000][2000];

int main() {
    int n, m;

    // 輸入 n*m 高度
    scanf("%d %d", &n, &m);

    // 輸入每一個
    // 順便判斷每一個 n 族的最大值
    int nMax, nM[n], mM[m];

    for(int i = 0; i < n ; i++) nM[i] = 0;
    for(int i = 0; i < m ; i++) mM[i] = 0;
    

    for(int i = 0; i < n ; i++){
        nMax = 0;
        for(int j = 0; j < m ; j++){
            // 輸入
            scanf("%d", &height[i][j]);

            // 判斷該 n 族的每一個 m 族之最大：nMax
            if (height[i][j] > nMax) nMax = height[i][j];

            // j 是 m 族。分別判斷該元素是否為所屬 m 族之最大
            if (height[i][j] > mM[j]) mM[j] = height[i][j];
        }
        nM[i] = nMax;
        // nMax 是那個 n 族的最大 m
    }

    // 有了 nM 和 mM 了
    unsigned long long add = 0;
    int canbeadd = 0;
    for(int i = 0; i < n ; i++){
        for ( int j = 0 ; j < m ; j++){
            // 個別判斷每一格
            canbeadd = nM[i];
            if(mM[j] < nM[i]) canbeadd = mM[j];
            add += (canbeadd - height[i][j]);
        }
    }

    printf("%llu", add);

    return 0;
}
