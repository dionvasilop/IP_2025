/* File: calc.c */
#include <stdio.h>
int main() {
    
    int number1;
    int number2;
    
    printf("Please enter the first number: ");
    fflush(stdout);
    scanf("%d", &number1);
    printf("Please enter the second number: ");
    fflush(stdout);
    scanf("%d", &number2);
    printf("The sum of the two numbers is: %d \n", (number1+number2));

return 0; 

}