#include<stdio.h>
#include<math.h>
#define PI 3.14159


float error(float Xnew, float Xold){
    float e = (Xnew - Xold)/(Xnew);
    if (e < 0)
    {
        return -e;
    }
    return e;
}

float midValue(float Xu, float Xl){
    return (Xu + Xl) / 2;
}


float Power(float base, float power){
    if(power == 0)
        return 1;
    else
        return base * Power(base, power - 1);
}


float sine(float value){
    return sin(value);
}

float cosine(float value){
    return cos(value);
}

float tangent(float value){
    return tan(value);
}


float Trigonometry(float degreeValue, float (*logic)(float)){                //  Trigonometry function with call back function as parameter
    float radianValue = degreeValue * (PI/180);
    float value =  (*logic)(radianValue);
    return value;
}


float logValue(float x){
    return log(x);
}

float expValue(float x){
    return exp(x);
}

float funcVlaue(float x){
    float result;
    
    //equation 2x^3 - 5 = 0
    result = 2 * Power(x, 3) - 5;                                           
    
    // equation  sin(x) + 5x -3= 0
    //  result = Trigonometry(x, &sine) + 5*x - 3;          // for  degree value of x
    // result = sine(x) + 5*x - 3;                          //  for radian value of  x
    
    // equation  cos(x)+5x^2-3x-5 = 0
    // result = Trigonometry(x, &cosine) + 5 * Power(x, 2) - 3 * x - 5;     // for  degree value of x
    // result = cosine(x) + 5 * Power(x, 2) - 3 * x - 5;                    // for radian value of x
    
    // equation e^-x -5 = 0
    // result = expValue(-x) - 5;                                           
    
    // equation ln(x)+6x-5 = 0
    // result = logValue(x) + 6 * x - 5;                                    

    return result;
}

void intializeValue(float *Xu, float *Xl){

    for (int i = 0; i < 10; i++)
    {
        int eq = funcVlaue(i);
        if (eq > 0){
            *Xu = i;
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        int eq = funcVlaue(i);
        if ( eq < 0){
            *Xl = i;
            break;
        }
    }
}

int main(){

    float Xold = 0, Xnew;
    float Xu, Xl ;                              // Xu for positive and Xl for negative
    intializeValue(&Xu, &Xl);

    /**
     * For Exponential and logarithmic linear equation 
     * we need to intilize the value manually 
     * ***/
    
    // for Exponentaial function
    // Xu = -2;
    // Xl = 0;

    //for  logarithmic function
    // Xu = 1;
    // Xl = 0.8;

    float mid,e;
    int n;

    printf("[-] The equaton is : 2x^3 - 5 = 0\n");
    printf("[-] f(x) = 2x^3 - 5 \n\n");

    // printf("[-] The equaton is : sin(x) + 5x -3 = 0\n");
    // printf("[-] f(x) = sin(x) + 5x -3 \n\n");
    
    // printf("[-] The equaton is : cos(x)+5x^2-3x-5 = 0\n");
    // printf("[-] f(x) = cos(x)+5x^2-3x-5 \n\n");
    
    // printf("[-] The equaton is : e^-x -5 = 0\n");
    // printf("[-] f(x) = e^-x -5 \n\n");
    
    // printf("[-] The equaton is : ln(x)+6x-5 = 0\n");
    // printf("[-] f(x) = ln(x)+6x-5 = 0 \n\n");


    printf("The value of x for which f(x) is positive : %.2f\nThe value of x for which f(x) is negative : %.2f\n\n", Xu, Xl);

    printf("Bisection Method\n\n");

    printf("How many iterations? ");
    scanf("%d", &n);

    printf("\n ___________________________________________________________________________________________________________________________\n");
    printf("    Iteration |     Xu     |     f(Xu)    |     Xl      |       f(Xl)        |      Xm     |    f(Xm)    |     Error       ");
    printf("\n _____________|____________|______________|_____________|____________________|_____________|_____________|__________________\n");
    
    // real calculation and the iteration begins here
    for (int i = 1; i <= n; i++)
    {

        mid = midValue(Xu, Xl);               // finding mid value 
        Xnew = mid;                                 // since Xnew is the current mid value 
        e = error(Xnew, Xold);                // finding error  :  here Xnew = current mid value and Xold = previous mid value
        Xold = mid;                                 // setting mid value to  Xold for the next iteration because Xold = previous mid value
        float Fxm = funcVlaue(mid);
        
        
        printf("       %d      |   %.4f   |     %.4f   |  %.4f     |      %.4f       |    %.4f   |    %.4f   |    %.4f      \n", i, Xu, funcVlaue(Xu), Xl, funcVlaue(Xl), mid ,Fxm, e);
        printf(" _____________|____________|______________|_____________|____________________|_____________|_____________|__________________\n");
        if (Fxm < 0)
        {
            Xl = mid;
        }
        else{
            Xu = mid;
        }

        if (e < 0.005)
        {
            break;
        }    
    }
    printf("\n\n[-] Thus, the root of  2x^3 - 5 = 0 is  %.4f and the error is %.4f.\n\n", mid,e);

    printf("\n\n[-] Thus, the root of  sin(x) + 5x -3 = 0 is  %.4f .\n\n", mid);
        
    printf("\n\n[-] Thus, the root of  cos(x)+5x^2-3x-5 = 0 is  %.4f .\n\n", mid);
        
    printf("\n\n[-] Thus, the root of  e^-x -5 = 0 is  %.4f .\n\n", mid);
        
    printf("\n\n[-] Thus, the root of  ln(x)+6x-5 = 0 is  %.4f .\n\n", mid);
}
