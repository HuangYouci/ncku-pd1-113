#include <stdio.h>

void integerToTwo(int num){
    for(int i=31 ; i >= 0 ; i--){
        printf("%d", (num >> i) & 1);
    }
}

void floatToTwo(float num){
    unsigned int bits = *((unsigned int*)&num);

    for (int i = 31; i >= 0; i--) {
        int bit = (bits >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main(){
    int test, iinput;
    float finput;
    scanf("%d", &test);
    if (test == 1){
        // integerToTwo
        scanf("%d", &iinput);
        integerToTwo(iinput);
    } else {
        // floatToTwo
        scanf("%f", &finput);
        floatToTwo(finput);
    }
    return 0;
}
