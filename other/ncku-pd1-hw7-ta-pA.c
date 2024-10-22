#include <stdio.h>

// 列印陣列
void checkPrintArray(int check[8]){
    for(int i=0 ; i<8 ; i++){
        printf("%d",check[i]);
    }
    printf("\n");
}

// 檢查兩陣列是否相等
int checkArraySame(int a[8], int b[8]){
    int same = 1;
    for(int i=0; i<8 ; i++){
        if(a[i] != b[i]){
            same = 0;
        }
    }
    return same;
}

// 調整陣列（二進位）
void checkArrayCorrect(int *ipointer){
    // printf("進入 checkArrayCorrect !\n");
    for(int i = 0; i<7 ; i++){
        // printf("現在開始檢查 calculate[%d] = %d\n",7-i,ipointer[7-i]);
        if(ipointer[7-i] > 1){
            // printf("calculate[%d] > 1，他會變 0。\n",7-i);
            ipointer[7-i] = 0;
            ipointer[(7-i)-1]++;
        }
    }
}

// 將二進位陣列化為數字
int makebittonum(int input[8]){
    int calculate[8] = {0,0,0,0,0,0,0,0};
    int calculating = 0;

    while(!checkArraySame(input,calculate)){
        calculating++;
        calculate[7]++;
        checkArrayCorrect(calculate);
    }

    // 現在 calculating 是 unsigned. two's complement 是相反的
    // 從 0~127 正，128 ~ 256 負    

    if (calculating > 127){
        // 128 = -128 (-256)
        // 129 = -127 (-256)
        // 255 = -1 (-256)
        calculating -= 256;
    }
    
    return calculating;
}

int makenumtobit(int num){
    int output[8] = {0,0,0,0,0,0,0,0};
    if (num < 0){
        num += 256;
    }
    while(num != 0){
        output[7]++;
        checkArrayCorrect(output);
        num--;
    }
    checkPrintArray(output);
    return 0;
}

int main(){

    int a[8], b[8], c, ans;
    for(int i=0; i<8 ; i++){
        scanf("%1d",&a[i]);
    }
    for(int i=0; i<8 ; i++){
        scanf("%1d",&b[i]);
    }
    scanf("%d",&c);
    
    // Look for what question required
    if(c==1){
        //加法
        ans = makebittonum(a) + makebittonum(b);
    }else{
        //減法
        ans = makebittonum(a) - makebittonum(b);
    }

    // Overflow?
    if(ans > 127 || ans < -128){
        printf("overflow\n");
    }else{
        // 現在得到 ans，把他弄回二進位
        makenumtobit(ans);
    }
    
    return 0;
}