// solving ODE using Euler and RK4 methods
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// defining the function to be solved
double f(double t,double y)
{
    return (y - (t*t) + 1);  
}
// defining the exact solution
double g(double t)
{
    return (((t+1)*(t+1)) - ((0.5)*exp(t)));
}

int main()
{
    FILE*fp=NULL;
    fp=fopen("output.txt","w");

    double t,y,error,err,h=0.2,tf=2; //tf is t end value
    // initial conditions
    t=0.0;
    y=0.5;
    fprintf(fp,"0.00\t0.500000\t0.500000\t0.000000\n");
    // Using Euler Method
    do{
        y=y+h*f(t,y);
        t=t+h;
        error = fabs(y - g(t));
        fprintf(fp,"%.2f\t%lf\t%lf\t%lf\n",t,y,g(t), error);                     //Printing in the following order: t     Euler solution      Exact Solution
    } while(t<1.9);
}