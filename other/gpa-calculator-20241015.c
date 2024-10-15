#include <stdio.h>

int main(){
    // Input all data //
    int input[100][2];
    int current = -1;
    do {
        current++;
        scanf("%d",&input[current/2][current%2]);
        // printf("input[%d][%d] is %d\n",current/2,current%2,input[current/2][current%2]);
    } while (input[current/2][current%2] != -1);
    // printf("Current is %d",current);
    
    // Calculate GPA //
    int gpa;
    for (int count = 0; count < (current/2); count++){
        gpa += input[count][0] * input[count][1];
    }
    gpa /= (current/2);

    // Print all Data //
    printf("Grade | Credit\n");
    for (int count = 0 ; count < (current/2); count++){
        printf("%5d | %5d\n",input[count][0],input[count][1]);
    }

    // Calculate GPA grade
    if (gpa >= 90){
        printf("GPA A");
    } else if (gpa >= 80){
        printf("GPA B");
    } else if (gpa >= 70){
        printf("GPA C");
    } else if (gpa >= 60){
        printf("GPA D");
    } else {
        printf("GPA F");
    }
    return 0;
}
