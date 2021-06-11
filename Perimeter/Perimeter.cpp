
#include <math.h>
#include <iostream>
#include "MathPart.h"

void printPerimeter(double *coordsX, double *coordsY, double perimeter, int am)
{	
	printf("Coordinates entered:\n");
	for (int i = 0; i < am; i++)
	{
		printf("(%lf, %lf)\n", coordsX[i], coordsY[i]);
	}
	printf("Perimeter of the polygon is: %lf\n", perimeter);
}

void promptForValues(double *coordsX, double *coordsY, int am)
{
	for (int count = 0; count < am; count++)
	{
		printf("Input x coordinate\n");
		scanf_s("%lf", &coordsX[count]);
		printf("Input y coordinate\n");
		scanf_s("%lf", &coordsY[count]);
	}
}

int main()
{
	double* coordsX = 0;
	double* coordsY = 0;
	int am = 0;
	double perimeter = 0;
	
	printf("Input Number of Points ");
	scanf_s("%i", &am);
	coordsX = (double*)malloc(am * sizeof(double));
	coordsY = (double*)malloc(am * sizeof(double));
	
	promptForValues(coordsX, coordsY, am);

	perimeter = calculatePerimeter(coordsX, coordsY, am);

	printPerimeter(coordsX, coordsY, perimeter, am);
	free(coordsX);
	free(coordsY);

}

