#include <stdio.h>

int main(){
    // n represents the number of cars
    // dMax represents the farest time of leaving car
    int n, l, r, dCar[1000000]= {}, dMax = 0, dTemp = 0; 

    scanf("%d", &n);

    for (int i = 0; i < n ; i++){
        scanf("%d %d", &l, &r);
        dCar[l]++;
        dCar[r]--;
    }
    
    // everytime
    for (int i = 0; i < 1000000 ; i++){
        dTemp += dCar[i];
        if (dTemp > dMax) dMax = dTemp;
    }
    
    printf("%d", dMax);
    return 0;
}
