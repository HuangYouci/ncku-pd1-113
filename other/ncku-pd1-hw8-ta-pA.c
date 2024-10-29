#include <stdio.h>
int main(){
    int arraysize;
    scanf("%d",&arraysize);
    int array[arraysize];
    for(int i = 0; i < arraysize ; i++){
        scanf("%d",&array[i]);
    }

    int max=array[0], min=array[0];
    for(int i = 0; i< arraysize ; i++){
        if(array[i] > max){
            max = array[i];
        }
        if(array[i] < min){
            min = array[i];
        }
    }
    printf("%d %d", min, max);
    return 0;
}