#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Defining function for exponential pdf with mean 0.5
double expdf(double x)
{
	return (2*exp(-2*x));
}

//Main function
void main()
{
	int npoints=10000;                                    //Number of random numbers              
	double u[npoints];                                    //Array for uniform deviates between [0,1]
	double x[npoints];                                    //Array for random numbers distributed according to 'expdf'

	//Entering numbers in 'u' array
	for(int i=0; i<npoints; i++)
	{
		u[i] = (double)rand()/(double)RAND_MAX;
	}

	//Generating numbers according to 'expdf' using Transformation Method
	for(int j=0; j<npoints; j++)
	{
		x[j] = -log(u[j])/2;
	}

	//Writing data to a text file
	FILE*fp=NULL;
	fp=fopen("ques4.txt","w");
	for(int k=0; k<npoints; k++)
	{
		fprintf(fp,"%f\t%f\n",u[k],x[k]);
	}
}