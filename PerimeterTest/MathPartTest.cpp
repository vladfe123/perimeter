#include "gtest/gtest.h"
#include "MathPart.h"

TEST(MathPartTest, TestDistancesCalculation) 
{
	EXPECT_TRUE(false);
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
