#include <stdio.h>
#include "pC.h"

void f(int n, int *ans){
    if(n == 1 || n == 2 ){
        *ans += 1;
    }else{
        f(n-1, ans);
        f(n-2, ans);
    }
}