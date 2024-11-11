#include <stdio.h>

int formula(int x, int y, int z){
    int spec;
    if ((z-y)<0){
        spec = -(z-y);
    }else{
        spec = (z-y);
    }
    return (((x+z)^(y-z))-(x&z&(y&2024)|(spec)));
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int max = formula(a,b,c);

    // 6 ways -1
    // oh oh way how how way
    if ( formula(a,c,b) > max ){
        max = formula(a,c,b);
    }

    if ( formula(b,a,c) > max ){
        max = formula(b,a,c);
    }

    if ( formula(b,c,a) > max ){
        max = formula(b,c,a);
    }

    if ( formula(c,a,b) > max ){
        max = formula(c,a,b);
    }

    if ( formula(c,b,a) > max ){
        max = formula(c,b,a);
    }

    printf("%d", max);

    return 0;
}