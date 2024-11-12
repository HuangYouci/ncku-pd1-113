#include <stdio.h>

int main(){
    int n, q, k;
    scanf("%d %d %d", &n, &q, &k);
    // n = car, q = query, k = lower bound

    // input

    int car[n], hov[n], presum[n+1];
    presum[0] = 0;
    for(int i = 0; i < n ; i++){
        scanf("%d", &car[i]);
        if (car[i] < k){
            hov[i] = 1;
        }else{
            hov[i] = 0;
        }
        presum[i+1] = presum[i] + hov[i];
    }

    int l, r, ansarray[q];
    for(int i = 0; i < q ; i++){
        scanf("%d %d", &l, &r);
        ansarray[i] = (presum[r] - presum[l-1]);
    }

    // querying
    
    for (int i = 0; i < q; i++){
        printf("%d\n", ansarray[i]);
    }

    return 0;
}
