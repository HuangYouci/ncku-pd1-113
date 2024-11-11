#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n ; i++){
        scanf("%d", &a[i]);
    }

    int q;
    scanf("%d", &q);

    int l, r, total, answerarray[q];
    for(int i = 0; i < q ; i++){
        total = 0;
        scanf("%d %d", &l, &r);
        for(int j = l; j <= r; j++){
            total += a[j-1];
        }
        answerarray[i] = total;
    }

    for(int i = 0; i < q; i++){
        printf("%d\n", answerarray[i]);
    }

    return 0;
}