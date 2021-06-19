#include<stdio.h>
#include<math.h>

void choiceMenu(int *choice){

    printf("Which question??:\n\
    [1] 2 * x^3 - 5\n\
    [2] cos(x) + 5 * x * x - 3 * x - 5\n\
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
    return -sin(x) + 5 * x - 3;
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
        return &sineFunction;
    else if (choice == 3)
        return &cosineFunction;
    else if(choice==4)
        return &logarithmicEqn;
    else
        return &expoEqn;

}

float (* functionDerivative(int choice))(float)
{
    
    if (choice  == 1)
        return &polynomialEqnDerivative;
    else if(choice == 2)
        return &sineFunctionDerivative;
    else if (choice == 3)
        return &cosineFunctionDerivative;
    else if(choice==4)
        return &logarithmicEqnDerivative;
    else
        return &expoEqnDerivative;

}

int main(){

    int choice;

    choiceMenu(&choice);

    float (*funcVlaue)(float) = function(choice);
    float (*derivativeValue)(float) = functionDerivative(choice);

    float Xold = 0, Xnew;
    float X;
    float Xn; // Xn is assumed to be X(n+1)
    float e;

    printf("\nNewton Raphson Method\n");
    printf("=======================\n\n");

    int n;
    printf("How many iterations? ");
    scanf("%d", &n);

    printf("Enter the Initial value of x: ");
    scanf("%f", &X);

    printf("\n ________________________________________________________________________________________\n");
    printf("    Iteration |     Xn    |     f(Xu)    |     df(x)    |       X(n+1)      |     error   ");
    printf("\n _____________|___________|______________|______________|___________________|____________\n");

    // real calculation and the iteration begins here

    for (int i = 1; i <= n; i++)
    {

        float fx = (*funcVlaue)(X);
        float dfx = (*derivativeValue)(X);
        
        Xn = X - fx / dfx;
        Xnew = Xn;
        e = error(Xnew, Xold);

        printf("       %d      |   %.4f   |     %.4f   |  %.4f     |      %.4f       |    %.4f   \n", i, X, fx, dfx, Xn, e);
        printf(" _____________|____________|______________|_____________|___________________|_____________\n");
        X = Xn;
        Xold = Xn;

        if (e < 0.05)
        {
            break;
        }
    }

    printf("\n\n[-] Thus, the root is  %.4f and the error is %.4f.\n\n", Xn,e);

}
