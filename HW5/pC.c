#include <stdio.h>

int main(){
    // n represents the number of cars
    // dMax represents the farest time of leaving car
    int n, dMax = 0; 

    scanf("%d", &n);

    // array car[n][2] meanings the start time and end time of each car
    int car[n][2];

    for (int i = 0; i < n ; i++){
        scanf("%d %d", &car[i][0], &car[i][1]);
        if (car[i][1] > dMax){
            dMax = car[i][1];
            // found dMax, the leaving time of last car
        }
    }
    
    // array dCar is change of number of cars at time
    int dCar[dMax], dCarTemp;
    // everytime
    for (int j = 0; j < dMax ; j++){
        dCarTemp = 0;
        // everycar
        for (int i = 0; i < n ; i++){
            if(car[i][0] == j){
                // if start time == j, d+1
                dCarTemp++;
            }
            if(car[i][1] == j){
                // if end time == j, d-1
                dCarTemp--;
            }
        }
        dCar[j] = dCarTemp;
    }

    // debug: print dCar
    // for (int i = 0; i < dMax ; i++){
    //     printf("%3d  ", i);
    // }
    // printf("\n");
    // for (int i = 0; i < dMax ; i++){
    //     printf("[%2d] ", dCar[i]);
    // }
    // printf("\n");

    // found dCar.
    int max = 0;
    dCarTemp = 0;
    for(int i = 0; i < dMax ; i++){
        dCarTemp += dCar[i];
        // printf("%3d  ", dCarTemp);
        if(dCarTemp > max){
            max = dCarTemp;
        }
    }
    
    printf("%d", max);
    return 0;
}