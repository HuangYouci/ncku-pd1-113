#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int speed[n];

    for(int i = 0; i < n ; i++){
        scanf("%d",&speed[i]);
    }

    int ramp = 0, rampcontinue = 0;

    for(int i = 0; i < n ; i++){
            if (speed[i] <= 60 && rampcontinue == 0){
                ramp++;
                rampcontinue = 1;
            } else if (speed[i] > 60) {
                rampcontinue = 0;
            }
    }

    printf("%d",ramp);

    return 0;
}