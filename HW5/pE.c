#include <stdio.h>

int main(){
    int n, q, k;
    scanf("%d %d %d", &n, &q, &k);
    // n = car, q = query, k = lower bound

    // input

    int car[n];
    for(int i = 0; i < n ; i++){
        scanf("%d", &car[i]);
    }

    int query[q][2];
    for(int i = 0; i < q ; i++){
        scanf("%d %d", &query[i][0], &query[i][1]);
    }

    // querying

    int queryTemp, ansarray[q];

    for(int i = 0; i < q ; i++){
        queryTemp = 0;
        for(int j = query[i][0]; j <= query[i][1] ; j++){
            if (car[j-1] < k){
                queryTemp++;
            }
        }
        ansarray[i] = queryTemp;
    }
    
    for (int i = 0; i < q; i++){
        printf("%d\n", ansarray[i]);
    }

    return 0;
}