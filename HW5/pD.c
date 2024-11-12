#include <stdio.h>

int main(){
    int n = 0, np = 0;

    scanf("%d", &n);

    long long a[n], b[n+1];
    for(int i = 0; i < n ; i++){
        scanf("%lld", &a[i]);
        b[i+1] = b[i] + a[i];
    }

    int q;
    scanf("%d", &q);

    int l, r, total;
    long long answerarray[q];
    for(int i = 0; i < q ; i++){
        scanf("%lld %lld", &l, &r);
        answerarray[i] = (b[r] - b[l-1]);
    }

    // for(int i = 0 ; i < (n+1) ; i++){
    //     printf("[%d] ", a[i]);
    // }

    // printf("\n");

    // for(int i = 0 ; i < (n+1) ; i++){
    //     printf("[%d] ", b[i]);
    // }

    for(int i = 0; i < q; i++){
        printf("%lld\n", answerarray[i]);
    }

    return 0;
}
