#include <stdio.h>

int step(int input){
    int calculate;
    calculate = input;
    while (input > 1){
        input--;
        calculate *= input; 
    }
    return calculate;
}

int main(){
    int n, k, ans;
    scanf("%d %d",&n,&k);
    ans = ((step(n))/(step(k)*(step(n-k))));
    printf("%d\n",ans);
    return 0;
}