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
    float e = (Xold- Xnew)/(Xnew);
    if (e < 0)
    {
        return -e;
    }
    return e;
}

float midValue(float Xu, float Xl){
    return (Xu + Xl) / 2;
}


//==============================| f(x) = x - e^-x |==================================================
float func1(float x){
    return 2 * pow(x, 3) - 5;
}


//===============================| f(x) = x^4 - 2*x^3 - 13*x^2 + 38*x - 24 |=================================

float func2(float x){
    return cos(x) + 5 * pow(x, 2) - 3 * x - 5;
}

//===============================| f(x) = x^4 - x - 10 |============================================
float func3(float x){
    return sin(x) + 5 * x - 3;
}


//===============================| f(x) = cos(x) - x*e^x |===============================================

float func4(float x)
{
    return log(x) + 6 * x - 5;             
}

//===============================| e^-x -5 |=========================================================
float func5(float x){
    return exp(-x) - 5;                     
}

//==================================================================================================

float  (*function(int choice))(float)
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


void printEqn(int choice){

    if (choice  == 1)
        printf("The Equation is: f(x) = 2 * x^3 - 5\n\n");

    else if(choice == 2)
        printf("The Equation is: f(x) = cos(x) + 5 * x^2 - 3 * x - 5\n\n");

    else if (choice == 3)
        printf("The Equation is: f(x) = sin(x) + 5 * x - 3\n\n");

    else if(choice==4)
        printf("The Equation is: f(x) = ln(x) + 6 * x - 5\n\n");

    else if(choice == 5)
        printf("The Equation is: f(x) = e^-x - 5\n\n");

    else{
        printf("Wrong input!!!\n\n");
        exit(0);
    }
}


// void intializeValue(float *Xu, float *Xl){

//     for (int i = 0; i < 10; i++)
//     {
//         int eq = funcVlaue(i);
//         if (eq > 0){
//             *Xu = i;
//             break;
//         }
//     }

//     for (int i = 0; i < 10; i++)
//     {
//         int eq = funcVlaue(i);
//         if ( eq < 0){
//             *Xl = i;
//             break;
//         }
//     }
// }


int main(){

    int choice;

    choiceMenu(&choice);

    float (*funcValue)(float) = function(choice);
    float Xnew,Xold;
    float Xu, Xl ;                              // Xu for positive and Xl for negative
    float mid,e;

    printf("\nBisection Method\n");
    printf("=======================\n\n");

    printEqn(choice);

    
    printf("Enter the Initial value of Xu: ");
    scanf("%f", &Xu);
    printf("Enter the Initial value of Xl: ");
    scanf("%f", &Xl);

    printf("The value of x for which f(x) is positive : %.2f\nThe value of x for which f(x) is negative : %.2f\n\n", Xu, Xl);

        printf("\n ___________________________________________________________________________________________________________________________\n");
        printf("    Iteration |     Xu     |     f(Xu)    |     Xl      |       f(Xl)        |      Xm     |    f(Xm)    |     Error       ");
        printf("\n _____________|____________|______________|_____________|____________________|_____________|_____________|__________________\n");
    
    // real calculation and the iteration begins here
    for (int i = 1; i <= 20; i++)
    {

        mid = midValue(Xu, Xl);               // finding mid value 
        float Fxm = (*funcValue)(mid);
        Xold = Xl;                                 // setting mid value to  Xold for the next iteration because Xold = previous mid value
        Xnew = mid;                                 // since Xnew is the current mid value 
        e = error(Xnew, Xold);                // finding error  :  here Xnew = current mid value and Xold = previous mid value
        
        
        printf("       %d      |   %.4f   |     %.4f   |  %.4f     |      %.4f       |    %.4f   |    %.4f   |    %.4f      \n", i, Xu, (*funcValue)(Xu), Xl, (*funcValue)(Xl), mid ,Fxm, e);
        printf(" _____________|____________|______________|_____________|____________________|_____________|_____________|__________________\n");
        if (Fxm < 0)
        {
            Xl = mid;
        }
        else{
            Xu = mid;
        }
        if (e < 0.05)
        {
            break;
        }
    }

    printf("\n\n[-] Thus, the root is  %.4f and the error is %.4f.\n\n", mid,e);

}