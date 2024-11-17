#include <stdio.h>

int main(){

    #define REQ 3.14159

    // float ans[1000];
    double pi = 0;

    for(int i = 1 ; 1 ; i++){

        // printf("4/%d\n",(i*2-1)*((i%2==1)?1:-1));

        pi += ( 4.0 / ( (i*2-1) * ((i%2==1)?1:-1) ) );
        // ans[i-1] = pi;
        printf("(%d): %.16lf\n", i , pi);

        if((pi - REQ) < 0.00001 && (pi - REQ) > 0) {
            printf("break at %d", i);
            break;
        }
    }

    return 0;
}