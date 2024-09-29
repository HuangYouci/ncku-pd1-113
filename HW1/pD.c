#include <stdio.h>

int main(){
    int a, b;
    char c;
    scanf("%d%c%d",&a,&c,&b);
    printf("%d\n",((a+b)*(c=='+')+(a-b)*(c=='-')+(a*b)*(c=='*')));
    return 0;
}
