#include <stdio.h>

int main(){
    int grade, credit, gpa = 0, gpaT = 0, gpaC = 0;
    printf("Welcome to GPA calculator. ");
    while (1) {
        printf("Please enter score. To terminate, enter with -1.\n");
        scanf("%d", &grade);
        if(grade == -1){
            printf("You have successfully end the process.\n");
            break;
        }
        while (grade > 100 || grade < 0){
            printf("You typed wrong. All range of grade is 0 to 100. Please try again:\n");
            scanf("%d", &grade);
        }
        printf("Now, please enter the credit of this grade.\n");
        scanf("%d", &credit);
        gpaT += grade * credit;
        gpaC += credit;
    }

    gpa = gpaT / gpaC;

    printf("Your GPA is %d of 100.\n",gpa);

    if (gpa >= 90){
        printf("Your GPA grade is A.\n");
    }else if(gpa >= 80){
        printf("Your GPA grade is B.\n");
    }else if (gpa >= 70){
        printf("Your GPA grade is C.\n");
    }else if (gpa >= 60){
        printf("Your GPA grade is D.\n");
    }else{
        printf("Your GPA grade is F.\n");
    }
}