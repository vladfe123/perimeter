
#include <iostream>
#include "MathPart.h"

/*
* Calculates distances between neighboring coordinates.
* @coordsX - array of coordinates X;
* @coordsY - array of coordinates Y;
* @sideWidths - resulting array with distances, it should be preallocated;
* @am - number of elements;
*/
void calculateSides(double *coordsX, double *coordsY, double *sideWidths, int am)
{
	bool isLast = false;
	double xpow = 0, ypow = 0;
	for (int i = 0; i < am; i++)
	{
		xpow = pow((coordsX[i + 1] - coordsX[i]), 2);
		ypow = pow((coordsY[i + 1] - coordsY[i]), 2);
		isLast = i == (am - 1);
		if (isLast)
		{
			xpow = pow((coordsX[i] - coordsX[0]), 2);
			ypow = pow((coordsY[i] - coordsY[0]), 2);
		}
		else
		{
			xpow = pow((coordsX[i + 1] - coordsX[i]), 2);
			ypow = pow((coordsY[i + 1] - coordsY[i]), 2);
		}
		sideWidths[i] = sqrt(xpow + ypow);
	}
}

/*
* Calculates a sum of array elements.
* @items - array of elements;
* @n - number of elements in the array;
* @returns calculated sum.
*/
double accumulate(double* items, int n)
{
	int i;
	double sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += items[i];
	}
	return sum;
}

/*
* Calculates perimeter of a figure defined as coordinates.
* @coordsX - array of coordinates X;
* @coordsY - array of coordinates Y;
* @am - number of elements;
* @returns calculated perimeter.
*/
double calculatePerimeter(double *coordsX, double *coordsY, int am)
{
	double *sideWidths;
	double perimeter = 0;
	sideWidths = (double*)malloc(am * sizeof(double));

	calculateSides(coordsX, coordsY, sideWidths, am);
	perimeter = accumulate(sideWidths, am);

	free(sideWidths);
	return perimeter;
}