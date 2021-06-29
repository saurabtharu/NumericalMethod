#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void choiceMenu(int *choice){

    printf("Which question??:\n\
    [1] f(x) = x - e^-x\n\
    [2] f(x) = x^4 - 2*x^3 - 13*x^2 + 38*x - 24\n\
    [3] f(x) = x^4 - x - 10 \n\
    [4] f(x) = cos(x) - x*e^x \n");
    // [4] f(x) = cos(x) - x*e^x\n\

    printf("Enter your choice: ");
    scanf("%d", choice);
}

float error(float Xnew, float Xold){
    float e = (Xold- Xnew)/(Xnew);
    if (e < 0)
    {
        return -e;
    }
    return e;
}


//==============================| f(x) = x - e^-x |==================================================
float func1(float x){
    return exp(-x);
}


//===============================| f(x) = x^4 - 2*x^3 - 13*x^2 + 38*x - 24 |=================================

float func2(float x){
	return (-pow(x, 4) + 2 * pow(x, 3) + 13 * pow(x, 2) + 24)/38;
}

//===============================| f(x) = x^4 - x - 10 |============================================
float func3(float x){
    return pow(x+10,1/4.0);
}


//===============================| f(x) = cos(x) - x*e^x |===============================================

float func4(float x)
{
	return cos(x) / exp(x);
}

//===============================| e^-x -5 |=========================================================
// float func5(float x){
//     return exp(-x) - 5;                     
// }

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
    // else
        // return &func5;

}


void printEqn(int choice){

    if (choice  == 1)
        printf("The Equation is: f(x) = x - e^-x\n\
		so,	x = e^-x\n\n");

    else if(choice == 2)
        printf("The Equation is: f(x) = x^4 - 2*x^3 - 13*x^2 + 38*x - 24\n\
		so,	x = (-x^4 + 2*x^3 + 13*x^2 + 24)/38\n\n");

    else if (choice == 3)
        printf("The Equation is: f(x) = x^4 - x - 10\n\
		so,	x = (x + 10)^(1/4)\n\n");

    else if(choice==4)
        printf("The Equation is: f(x) = cos(x) - x*e^x\n\
		so,	x = cos(x)/e^x\n\n");

    // else if(choice == 5)
    //     printf("The Equation is: e^-x - 5\n\n");

    else{
        printf("Wrong input!!!\n\n");
        exit(0);
    }
}

int main(){

    int choice;

    choiceMenu(&choice);

    float (*funcValue)(float) = function(choice);
    float Xn; // Xn is assumed to be X(n+1)
    float e,Xnew,Xold,X;

    printf("\nFixed_Point Iteration\n");
    printf("=======================\n\n");

    printEqn(choice);
    
    printf("Enter the Initial value of x: ");
    scanf("%f", &X);

    printf("\n _______________________________________________________\n");
    printf("    Iteration   |     Xn    |   X(n+1)      |     error   ");
    printf("\n _______________|___________|_______________|____________\n");

    // real calculation and the iteration begins here

    for (int i = 1; i <= 20; i++)
    {

		Xn = (*funcValue)(X);
		Xnew = Xn;
		Xold = X;
        e = error(Xnew, Xold);

        printf("        %d       |  %.4f   |     %.4f    |   %.4f   \n", i, X, Xn, e);
        printf(" _______________|___________|_______________|_____________\n");
        X = Xn;
        Xold = Xn;

        if (e < 0.05)
        {
            break;
        }
    }

    printf("\n\n[-] Thus, the root is  %.4f and the error is %.4f.\n\n", Xn,e);

}