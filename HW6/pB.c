#include <stdio.h>
#include "pB.h"

int C[100][100];

void solve(int n, int m, int (*A)[100], int (*B)[100]){
    int i, j;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int get_value(int i, int j){
    return C[i][j];
}