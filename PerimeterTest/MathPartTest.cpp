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
TEST(MathPartTest, TestSideCalculation) 
{
	double perimeter = 0;

	double coordsX[] = {0, 0, 4};
	double coordsY[] = {0, 2, 0};
	int am = sizeof(coordsX)/sizeof(double);

	perimeter = calculatePerimeter(coordsX, coordsY, am);

	EXPECT_NEAR(10.47, perimeter, 0.01);
}
TEST(MathPartTest, TestOctagonCalculation)
{
	double perimeter = 0;

	double coordsX[] = { 3, 5, 8, 12, 5, 9, 2, 3 };
	double coordsY[] = { 6, 7, 9, 4, 8, 6, 5, 1 };
	int am = sizeof(coordsX) / sizeof(double);

	perimeter = calculatePerimeter(coordsX, coordsY, am);

	EXPECT_NEAR(40.97, perimeter, 0.01);
}
TEST(MathPartTest, TestOneElementPerimenterCalculation)
{
	double perimeter = 0;

	double coordsX[] = { 3 };
	double coordsY[] = { 6 };
	int am = sizeof(coordsX) / sizeof(double);

	perimeter = calculatePerimeter(coordsX, coordsY, am);

	EXPECT_NEAR(0, perimeter, 0.01);
}
TEST(MathPartTest, TestOneSidePerimenterCalculation)
{
	double perimeter = 0;

	double coordsX[] = { 3,5 };
	double coordsY[] = { 6,8 };
	int am = sizeof(coordsX) / sizeof(double);

	perimeter = calculatePerimeter(coordsX, coordsY, am);

	EXPECT_NEAR(5.65, perimeter, 0.01);
}
