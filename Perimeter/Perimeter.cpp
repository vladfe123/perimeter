/**
* @file Perimeter.cpp
* @author Федоренко В.О., гр. 515-і, вариант 8
* @date 10 Июня 2021
* @brief Навчальна практика
* Расчёт периметра многоугольника
*/
#include <math.h>
#include <iostream>
#include "MathPart.h"

int clear_stdin() {
	while (getchar() != '\n');
	return 1;
}
void printPerimeter(double *coordsX, double *coordsY, double perimeter, int am)
{	
	printf("Coordinates entered:\n");
	for (int i = 0; i < am; i++)
	{
		printf("(%lf, %lf)\n", coordsX[i], coordsY[i]);
	}
	printf("Perimeter of the polygon is: %lf\n", perimeter);
}

bool promptForValues(double *coordsX, double *coordsY, int am)
{
	char c;
	for (int count = 0; count < am; count++)
	{

		printf("Input x coordinate\n");
		if (scanf_s("%lf%c", &coordsX[count], &c) != 2 || c !='\n' && clear_stdin())
		{
			printf("Enter Number!\n");
			return false;
		}
		printf("Input y coordinate\n");
		if (scanf_s("%lf%c", &coordsY[count], &c) != 2 || c != '\n' && clear_stdin())
		{
			printf("Enter Number!\n");
			return false;
		}
		
	}
}

int main()
{
	double* coordsX = 0;
	double* coordsY = 0;
	int am = 0;
	double perimeter = 0;
	bool isNumber;
	printf("Input Number of Points ");
	scanf_s("%i", &am);
	if (am > 0) 
	{
		coordsX = (double*)malloc(am * sizeof(double));
		coordsY = (double*)malloc(am * sizeof(double));
	
		isNumber = promptForValues(coordsX, coordsY, am);
		if (isNumber == false) 
		{
			return -1;
		}
		else 
		{
			perimeter = calculatePerimeter(coordsX, coordsY, am);

			printPerimeter(coordsX, coordsY, perimeter, am);
			free(coordsX);
			free(coordsY);
		}
		
	}
	else
	{
		printf("Number of Points can't be negative");
	}
	return 0;
}

