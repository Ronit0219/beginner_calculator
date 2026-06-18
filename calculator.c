#include <stdio.h>
#include<stdlib.h>

void get_input(float *, float *); //function for user input
int get_choice(); // function for user choice

int main() {
    float a, b;
    int choice;
    printf("----Calculator Menu-----\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Exit\n");
    while(1){ //infinite loop for program 
    choice = get_choice();
    
    switch(choice){
        case 1:
            get_input(&a, &b); //& is used for call by reference
            printf("%.2f\n",a + b);
            break;
        case 2:
            get_input(&a, &b);
            printf("%.2f\n",a - b);
            break;
    
        case 3:
            get_input(&a, &b);
            printf("%.2f\n",a * b);
            break;
    
        case 4:
            get_input(&a, &b);
            if(b == 0){ // zero division handling
                printf("Division by zero not possible\n");
            }
            else{
                printf("%.2f\n",a / b);
            } 
            break; 
        case 5:
            printf("exiting from the calculator\n");
            exit(0); //program termination
        default:
            printf("INvalid choice!\n");

    }
}
    return 0;
}
void get_input(float *a, float *b){// function for user input
    char input[50];// input variable in which user input is stored
    char dummy; // dummy variable to catch trailing alphabets from user input
    while(1){//infinite loop for user input till correct input is fed
        printf("Enter first value: ");
        if(fgets(input, sizeof(input), stdin) == NULL) //fgets function is used to get user input into user variable
            exit(1); //program termination when error occurs(when nothing is fed by the user)
        else{
            if(sscanf(input, "%f %1s", a, &dummy) == 1)//dividing the input fed by user into float and character to perform operations on numeric variable
                break;
            else
                printf("Invalid input ! Enter a valid input\n");
        }
    }

    while(1) //infinite loop for user input till correct input is fed
    {
        printf("Enter second value: ");
        if(fgets(input, sizeof(input), stdin) == NULL) //fgets function is used to get user input into user variable
            exit(1); //program termination when error occurs(when nothing is fed by the user)
        else{
            if(sscanf(input, "%f %1s", b, &dummy) == 1) //dividing the input fed by user into float and character to perform operations on numeric variable
               break;
            else
                printf("Invalid input ! Enter a valid input\n");
    }
}

}

int get_choice(){ //function for user choice
    int choice;
    char input[50];  // input variable in which user input is stored
    char dummy;   // dummy variable to catch trailing alphabets from user input
    while(1){  //infinite loop for user input till correct input is fed
        printf("Enter your choice from the menu\n");
        if(fgets(input, sizeof(input), stdin) == NULL)   //fgets function is used to get user input into user variable
            exit(1);   //program termination when error occurs(when nothing is fed by the user)
        else{
            if(sscanf(input, "%d %1s", &choice, &dummy) == 1 && choice >=1 && choice <=5)  //dividing the input fed by user into float and character to perform operations on numeric variable and boundation for choice is also applied
                return choice;
            else
                printf("Invalid choice ! Enter a number from 1 to 5\n");
    }
    
    }
}