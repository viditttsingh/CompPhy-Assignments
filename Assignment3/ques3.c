//Importing libraries
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_complex.h>

//Defining universal parameters
#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])
#define N 200
#define xi -50
#define xf 50

//Defining the sinc function
double sinc(double x) 
{
    if (x == 0.0)
    {
        return 1.0;
    } 
    else 
    {
        return sin(x)/x;
    }
}

//Main Function
int main() 
{
    double del = (double)(xf-xi)/(N - 1);                             //Defining delta(x)
    double dft[2*N];                                                  //Initializing dft-array

    //Using gsl to compute fourier transform
    gsl_fft_complex_wavetable * wavetable;
    gsl_fft_complex_workspace * workspace;
    for (int i=0; i < N; i++) 
    {
        double x = xi + (i*del);
        REAL(dft,i) = sinc(x);
        IMAG(dft,i) = 0.0;
    }
    wavetable = gsl_fft_complex_wavetable_alloc(N);
    workspace = gsl_fft_complex_workspace_alloc(N);
    gsl_fft_complex_forward(dft, 1, N, wavetable, workspace);

    //Writing dft-data to a text file
    FILE*fp = fopen("ques3.csv","w");
    for (int i = 0; i < N; i++) 
    {
        fprintf(fp, "%g, %g\n", REAL(dft,i), IMAG(dft,i));
    }
    gsl_fft_complex_wavetable_free (wavetable);
    gsl_fft_complex_workspace_free (workspace);
    fclose(fp);
    return 0;
}