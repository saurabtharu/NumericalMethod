#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void choiceMenu(int *choice){

    printf("Which question??:\n\
    [1] 2 * x^3 - 5\n\
    [2] cos(x) + 5 * x^2 - 3 * x - 5\n\
    [3] sin(x) + 5 * x - 3\n\
    [4] ln(x) + 6 * x - 5\n\
    [5] e^-x - 5\n");

    printf("Enter your choice: ");
    scanf("%d", choice);
}

float error(float Xnew, float Xold){
    float e = (Xnew - Xold)/(Xnew);
    if (e < 0)
    {
        return -e;
    }
    return e;
}

float Power(float base, float power){
    if(power == 0)
        return 1;
    else
        return base * Power(base, power - 1);
}

//==============================| 2 * x^3 - 5 |==================================================
float func1(float x){
    return 2 * Power(x, 3) - 5;
}
float func1Derivative(float x){
    return 6 * Power(x, 2);
}

//===============================| cos(x) + 5 * x * x - 3 * x - 5 |=================================


float func2(float x){
    return cos(x) + 5 * Power(x, 2) - 3 * x - 5;
}

float func2Derivative(float x){
    return -sin(x) + 10 * x - 3;
}

//===============================| sin(x) + 5 * x - 3 |============================================
float func3(float x){
    return sin(x) + 5 * x - 3;
}

float func3Derivative(float x){
    return cos(x) + 5;
}

//===============================| ln(x) + 6 * x - 5 |===============================================

float func4(float x)
{
    return log(x) + 6 * x - 5;             

}

float func4Derivative(float x){
    return 1 / x + 6;
}

//===============================| e^-x -5 |=========================================================
float func5(float x){
    return exp(-x) - 5;                     
}

float func5Derivative(float x){
    return -exp(-x);
}

//==================================================================================================

float  (* function(int choice))(float)
{
    
    if (choice  == 1)
        return &func1;
    else if(choice == 2)
        return &func2;
    else if (choice == 3)
        return &func3;
    else if(choice==4)
        return &func4;
    else
        return &func5;

}

float (* functionDerivative(int choice))(float)
{
    
    if (choice  == 1)
        return &func1Derivative;
    else if(choice == 2)
        return &func2Derivative;
    else if (choice == 3)
        return &func3Derivative;
    else if(choice==4)
        return &func4Derivative;
    else if(choice == 5)
        return &func5Derivative;
    else{
        printf("Wrong input!!!\n");
        exit(0);
    }
}

void printEqn(int choice){

    if (choice  == 1)
        printf("The Equation is: 2 * x^3 - 5\n\n");

    else if(choice == 2)
        printf("The Equation is: cos(x) + 5 * x^2 - 3 * x - 5\n\n");

    else if (choice == 3)
        printf("The Equation is: sin(x) + 5 * x - 3\n\n");

    else if(choice==4)
        printf("The Equation is: ln(x) + 6 * x - 5\n\n");

    else if(choice == 5)
        printf("The Equation is: e^-x - 5\n\n");

    else{
        printf("Wrong input!!!\n\n");
        exit(0);
    }
}

int main(){

    int choice;

    choiceMenu(&choice);

    float (*funcValue)(float) = function(choice);
    float (*derivativeValue)(float) = functionDerivative(choice);

    float Xold = 0, Xnew;
    float X;
    float Xn; // Xn is assumed to be X(n+1)
    float e;

    printf("\nNewton Raphson Method\n");
    printf("=======================\n\n");

    // int n;
    // printf("How many iterations? ");
    // scanf("%d", &n);

    printEqn(choice);
    
    printf("Enter the Initial value of x: ");
    scanf("%f", &X);

    printf("\n ________________________________________________________________________________________\n");
    printf("    Iteration   |     Xn    |     f(Xu)     |       df(x)   |   X(n+1)      |     error   ");
    printf("\n _______________|___________|_______________|_______________|_______________|____________\n");

    // real calculation and the iteration begins here

    for (int i = 1; i <= 20; i++)
    {

        float fx = (*funcValue)(X);
        float dfx = (*derivativeValue)(X);
        
        Xn = X - fx / dfx;
        Xnew = X;
        Xold = Xn;
        e = error(Xnew, Xold);

        printf("        %d       |  %.4f   |    %.4f    |   %.4f      |     %.4f    |   %.4f   \n", i, X, fx, dfx, Xn, e);
        printf(" _______________|___________|_______________|_______________|_______________|_____________\n");
        X = Xn;
        Xold = Xn;

        if (e < 0.005)
        {
            break;
        }
    }

    printf("\n\n[-] Thus, the root is  %.4f and the error is %.4f.\n\n", Xn,e);

}
