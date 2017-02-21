#include <gtest/gtest.h>
#include "../include/PIDController.h"

//Test Compute Method with non-zero positive values
TEST(PIDControllerTest, testPIDControllerComputeNonZeroPositive)
{
	PIDController p = PIDController(1,2,.4,5,.3,2);

    EXPECT_GT(0, p.compute(12.0, .4));
    EXPECT_GT(0, p.compute(.45, 10));
    EXPECT_GT(0, p.compute(.43, 1));
    EXPECT_GT(0, p.compute(.45, .12));
}

//Test Compute Method with negative values.
TEST(PIDControllerTest, testPIDControllerComputeNegativeValues)
{
	PIDController p = PIDController(1,2,.4,5,-3,-2);

    EXPECT_GT(0, p.compute(12.0, .4));
    EXPECT_GT(0, p.compute(.45, -10));
    EXPECT_GT(0, p.compute(.43, 1));
    EXPECT_GE(0, p.compute(.45, .12));
}

//Test Compute Method with zero values.
TEST(PIDControllerTest, testPIDControllerComputeZeroValues)
{
	PIDController p = PIDController(1,2,.4,0,0,0);

    EXPECT_EQ(1, p.compute(12.0, .4));
    EXPECT_GT(0, p.compute(.45, -10));
    EXPECT_GT(0, p.compute(.43, 1));
    EXPECT_LT(1, p.compute(.45, .12));
}

//Test Compute Method with Ki zero value.
TEST(PIDControllerTest, testPIDControllerComputeKiZero)
{
	PIDController p = PIDController(1,2,.4,2,3,0);

    EXPECT_GT(1, p.compute(12.0, .4));
    EXPECT_GT(0, p.compute(.45, -10));
    EXPECT_GT(0, p.compute(.43, 1));
    EXPECT_LT(1, p.compute(.45, .12));
}
//Test Compute Method with Kd zero value.
TEST(PIDControllerTest, testPIDControllerComputeKdZero)
{
	PIDController p = PIDController(1,2,.4,2,0,2);

    EXPECT_GT(1, p.compute(12.0, .4));
    EXPECT_GT(0, p.compute(.45, -10));
    EXPECT_GT(0, p.compute(.43, 1));
    EXPECT_LT(1, p.compute(.45, .12));
}
//Test Compute Method with Kp zero value.
TEST(PIDControllerTest, testPIDControllerComputeKpZero)
{
	PIDController p = PIDController(1,2,.4,0,1,2);

    EXPECT_GT(1, p.compute(12.0, .4));
    EXPECT_GT(0, p.compute(.45, -10));
    EXPECT_GT(0, p.compute(.43, 1));
    EXPECT_LT(1, p.compute(.45, .12));
}

//Test Initialization Method.
TEST(PIDControllerTest, testPIDControllerInitialize)
{
	PIDController p = PIDController(1,2,.4,0,.3,2);

	EXPECT_GT(0, p.getMin());
	EXPECT_GT(0, p.getMax());
	EXPECT_GT(0, p.getIntegral());
	EXPECT_GT(0, p.getKi());
	EXPECT_GT(0, p.getKd());
	EXPECT_GT(0, p.getKp());
	EXPECT_GT(0, p.getDt());
	EXPECT_GT(0, p.getPre_Error());
}
