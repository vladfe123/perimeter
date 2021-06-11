#include "gtest/gtest.h"
#include "MathPart.h"

TEST(MathPartTest, TestDistancesCalculation) 
{
	double side[] = { 0, 0 };
	double coordsX[] = { 0, 0};
	double coordsY[] = { 0, 2};
	int am = sizeof(coordsX) / sizeof(double);
	calculateSides(coordsX,coordsY,side,am);
	EXPECT_NEAR(2, side[1], 0.01);
}

TEST(MathPartTest, TestPerimeterCalculation) 
{
	double perimeter = 0;

	double coordsX[] = {0, 0, 4};
	double coordsY[] = {0, 2, 0};
	int am = sizeof(coordsX)/sizeof(double);

	perimeter = calculatePerimeter(coordsX, coordsY, am);

	EXPECT_NEAR(10.47, perimeter, 0.01);
}
