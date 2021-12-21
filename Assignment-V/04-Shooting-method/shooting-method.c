
// WAP to integrate using Heun;s Method


/*
#include<stdio.h>
#define f1(x,y,z) (z)
#define f2(x,y,z) 6*(z)


float func(float x,float y){
	// return 2*x*x*x -3*x*y;
	// return x*y;
	return x*x + y*y;
	// return 1/(1+x);
	// return log10(x);
	// return 1/(1 + pow(x,2));
	// return exp(-pow(x,2));
}


// float func_1(float x,float y,float z) {
// 	return z;
// }

// float func_2(float x,float y,float z) {
// 	return 6*x;
// // return 3*x+4*y;
// }

float heunsMethod(float h,float x,float y,float val) {
	float m1, m2, result;

	printf("\n");
	while (x <= val) {

		printf("y(%.3f) = %.3f\n",x,y);
		if (x == val)
			return y;
		// printf("when x = %.3f then y = %.3f\n",x,y);
		m1 = func(x, y);
		m2 = func(x + h, y + m1 * h);
		x = x + h;
		// printf("x = %f m1 = %f m2 = %f\n", x, m1, m2);
		y = y + (h / 2) * (m1 + m2);
	}
}

float M1func1(float x,float y,float z) {
	return z;
}

float M2func2(float x,float y,float z) {
	return 6*x;
}


int main() {
	float x0,y0,x1,y1,z0,xp;
	float h;
	float val,result;


	printf("Enter the initial value of x and y: ");
	scanf("%f %f", &x0,&y0);
	printf("Enter the final value of x and y: ");
	scanf("%f %f", &x1,&y1);

	// printf("Enter the")
	printf("Guess the value of z: ");
	scanf("%f", &z0);

	printf("Enter the value of h: ");
	scanf("%f", &h);



	printf("Enter the value of x for which y is to be calculated: ");
	scanf("%f", &val);
	
	printf("Enter the value of h : ");
	scanf("%f", &h);

	result = heunsMethod(h,a,b, val);
	printf("\nHence, the final answer is y(%.3f) = %.3f\n", val, result);


}


*/
/*

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f1(float x,float y,float z) {
    return(z);
}
float f2(float x,float y,float z)
{
    // return(x+y);
	return 2 * y + 72 * x - 8 * x * x * x;
}
float shoot(float x0,float y0,float z0,float xn,float h,int p)
{
    float x,y,z,k1,k2,k3,k4,l1,l2,l3,l4,k,l,x1,y1,z1;
    x=x0;
    y=y0;
    z=z0;
    do
    {
        k1=h*f1(x,y,z);
        l1=h*f2(x,y,z);
        k2=h*f1(x+h/2.0,y+k1/2.0,z+l1/2.0);
        l2=h*f2(x+h/2.0,y+k1/2.0,z+l1/2.0);
        k3=h*f1(x+h/2.0,y+k2/2.0,z+l2/2.0);
        l3=h*f2(x+h/2.0,y+k2/2.0,z+l2/2.0);
        k4=h*f1(x+h,y+k3,z+l3);
        l4=h*f2(x+h,y+k3,z+l3);
        l=1/6.0*(l1+2*l2+2*l3+l4);
        k=1/6.0*(k1+2*k2+2*k3+k4);
        y1=y+k;
        x1=x+h;
        z1=z+l;
        x=x1;
        y=y1;
        z=z1;
        if(p==1) {
            printf("\n%f\t%f",x,y);
        }
    }while(x<xn);
    return(y);
}
 int main()
{
    float x0,y0,h,xn,yn,z0,m1,m2,m3,b,b1,b2,b3,e;
    int p=0;
    printf("\n  Enter x0,y0,xn,yn,h:");
    scanf("%f%f%f%f%f",&x0,&y0,&xn,&yn,&h);
    printf("\n  Enter the trial M1:");
    scanf("%f",&m1);
    b=yn;
    z0=m1;
    b1=shoot(x0,y0,z0,xn,h,p=1);
    printf("\nB1 is %f",b1);
    if(fabs(b1-b)<0.00005) {
        printf("\n  The value of x and respective z are:\n");
        e=shoot(x0,y0,z0,xn,h,p=1);
        return(0);
    }
    else
    {
    printf("\nEnter the value of M2:");
    scanf("%f",&m2);
    z0=m2;
    b2=shoot(x0,y0,z0,xn,h,p=1);
    printf("\nB2 is %f",b2);
    }
    if(fabs(b2-b)<0.00005) {
         printf("\n  The value of x and respective z are\n");
         e= shoot(x0,y0,z0,xn,h,p=1);
         return(0);
    }
    else
    {
        printf("\nM2=%f\tM1=%f",m2,m1);
        m3=m2+(((m2-m1)*(b-b2))/(1.0*(b2-b1)));
        if(b1-b2==0)
        exit(0);

        printf("\nExact value of M =%f",m3);
        z0=m3;
        b3=shoot(x0,y0,z0,xn,h,p=0);
    }
    if(fabs(b3-b)<0.000005) {
        printf("\nThere is solution :\n");
        e=shoot(x0,y0,z0,xn,h,p=1);
        exit(0);
    }
       do
       {
           m1=m2;
           m2=m3;
           b1=b2;
           b2=b3;
           m3=m2+(((m2-m1)*(b-b2))/(1.0*(b2-b1)));
           z0=m3;
           b3=shoot(x0,y0,z0,xn,h,p=0);

       }while(fabs(b3-b)<0.0005);
       z0=m3;
       e=shoot(x0,y0,z0,xn,h,p=1);
     }



     */



#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f1(float x,float y,float z) {
    return(z);
}
float f2(float x,float y,float z) {
    return(x+y);
}
float shoot(float x0,float y0,float z0,float xn,float h,int p) {
    float x,y,z,k1,k2,k3,k4,l1,l2,l3,l4,k,l,x1,y1,z1;
    x=x0;
    y=y0;
    z=z0;
    do {
        k1=h*f1(x,y,z);
        l1=h*f2(x,y,z);
        k2=h*f1(x+h/2.0,y+k1/2.0,z+l1/2.0);
        l2=h*f2(x+h/2.0,y+k1/2.0,z+l1/2.0);
        k3=h*f1(x+h/2.0,y+k2/2.0,z+l2/2.0);
        l3=h*f2(x+h/2.0,y+k2/2.0,z+l2/2.0);
        k4=h*f1(x+h,y+k3,z+l3);
        l4=h*f2(x+h,y+k3,z+l3);
        l=1/6.0*(l1+2*l2+2*l3+l4);
        k=1/6.0*(k1+2*k2+2*k3+k4);
        y1=y+k;
        x1=x+h;
        z1=z+l;
        x=x1;
        y=y1;
        z=z1;
        if(p==1) {
            printf("\n%f\t%f",x,y);
        }
    }while(x< xn);
    return(y);
}
int main() {
    float x0,y0,h,xn,yn,z0,m1,m2,m3,b,b1,b2,b3,e;
    int p=0;
    printf("\n  Enter x0,y0,xn,yn,h:");
    scanf("%f%f%f%f%f",&x0,&y0,&xn,&yn,&h);
    printf("\n  Enter the trial M1:");
    scanf("%f",&m1);
    b=yn;
    z0=m1;
    b1=shoot(x0,y0,z0,xn,h,p=1);
    printf("\nB1 is %f",b1);
    if(fabs(b1-b)< 0.00005) {
        printf("\n  The value of x and respective z are:\n");
        e=shoot(x0,y0,z0,xn,h,p=1);
        return(0);
    }
    else {
        printf("\nEnter the value of M2:");
        scanf("%f",&m2);
        z0=m2;
        b2=shoot(x0,y0,z0,xn,h,p=1);
        printf("\nB2 is %f",b2);
    }
    if(fabs(b2-b)< 0.00005) {
         printf("\n  The value of x and respective z are\n");
         e= shoot(x0,y0,z0,xn,h,p=1);
         return(0);
    } else {
        printf("\nM2=%f\tM1=%f",m2,m1);
        m3=m2+(((m2-m1)*(b-b2))/(1.0*(b2-b1)));
        if(b1-b2==0)
        exit(0);
 
        printf("\nExact value of M =%f",m3);
        z0=m3;
        b3=shoot(x0,y0,z0,xn,h,p=0);
    }
    if(fabs(b3-b)< 0.000005) {
        printf("\nThere is solution :\n");
        e=shoot(x0,y0,z0,xn,h,p=1);
        exit(0);
    }
    do
    {
        m1=m2;
        m2=m3;
        b1=b2;
        b2=b3;
        m3=m2+(((m2-m1)*(b-b2))/(1.0*(b2-b1)));
        z0=m3;
        b3=shoot(x0,y0,z0,xn,h,p=0);
 
    }while(fabs(b3-b)< 0.0005);
    z0=m3;
    e=shoot(x0,y0,z0,xn,h,p=1);
}
