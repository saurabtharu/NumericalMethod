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
    float e = (Xold - Xnew)/(Xnew);
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
float polynomialEqn(float x){
    return 2 * Power(x, 3) - 5;
}
float polynomialEqnDerivative(float x){
    return 6 * Power(x, 2);
}
//===============================| sin(x) + 5 * x - 3 |============================================
float sineFunction(float x){
    return sin(x) + 5 * x - 3;
}

float sineFunctionDerivative(float x){
    return cos(x) + 5;
}

//===============================| cos(x) + 5 * x * x - 3 * x - 5 |=================================


float cosineFunction(float x){
    return cos(x) + 5 * Power(x, 2) - 3 * x - 5;
}

float cosineFunctionDerivative(float x){
    return -sin(x) + 10 * x - 3;
}

//===============================| ln(x) + 6 * x - 5 |===============================================

float logarithmicEqn(float x)
{
    return log(x) + 6 * x - 5;             

}

float logarithmicEqnDerivative(float x){
    return 1 / x + 6;
}

//===============================| e^-x -5 |=========================================================
float expoEqn(float x){
    return exp(-x) - 5;                     
}

float expoEqnDerivative(float x){
    return -exp(-x);
}

//==================================================================================================

float  (* function(int choice))(float)
{
    
    if (choice  == 1)
        return &polynomialEqn;
    else if(choice == 2)
        return &cosineFunction;
    else if (choice == 3)
        return &sineFunction;
    else if(choice==4)
        return &logarithmicEqn;
    else
        return &expoEqn;

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
        printf("Wrong input!!!\n");
        exit(0);
    }
}

int main(){

    int choice;

    choiceMenu(&choice);

    float (*funcVlaue)(float) = function(choice);

    float Xold = 0, Xnew;
    float XnMinus1, Xn, XnPlus1;
    float e;

    printf("\nSecant Method\n");
    printf("=======================\n\n");

    // int n;
    // printf("How many iterations? ");
    // scanf("%d", &n);

    printEqn(choice);
    
    printf("Enter the Initial value of Xn: ");
    scanf("%f", &XnMinus1);

    printf("Enter the Initial value of Xn+1: ");
    scanf("%f", &Xn);

    printf("\n ______________________________________________________________________________________________________\n");
    printf("    Iteration   |     Xn-1  |     f(Xn-1)   |      Xn       |   f(Xn)      |   Xn+1      |     error   ");
    printf("\n _______________|___________|_______________|_______________|______________|_____________|_____________\n");

    // real calculation and the iteration begins here

    for (int i = 1; i <= 20; i++)
    {

        float fXnMinus1 = (*funcVlaue)(XnMinus1);
        float fXn = (*funcVlaue)(Xn);

        XnPlus1 = Xn - (Xn - XnMinus1) * fXn / (fXn - fXnMinus1);

        float fXnPlus1 = (*funcVlaue)(XnPlus1);

        Xold = Xn;
        Xnew = XnPlus1;
        e = error(Xnew, Xold);

        printf("        %d       |  %.4f   |    %.4f    |   %.4f      |   %.4f    |   %.4f    |   %.4f   \n", i, XnMinus1, fXnMinus1, Xn, fXn, XnPlus1, e);
        printf(" _______________|___________|_______________|_______________|______________|_____________|_____________\n");
        
        XnMinus1 = Xn;
        Xn = XnPlus1;

        if (e < 0.05)
        {
            break;
        }
    }

    printf("\n\n[-] Thus, the root is  %.4f and the error is %.4f.\n\n", XnPlus1,e);

}
