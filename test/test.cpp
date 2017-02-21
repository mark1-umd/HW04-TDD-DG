#include <gtest/gtest.h>
#include "../include/PIDController.h"

//Test Compute Method with non-zero positive values
TEST(PIDControllerTest, testPIDControllerCompute)
{
	PIDController p = PIDController(1,2,.4,5,.3,2);

    EXPECT_DOUBLE_EQ(1, p.compute(12.0, .4));
    EXPECT_DOUBLE_GT(0, p.compute(.45, 10));
    EXPECT_DOUBLE_GT(0, p.compute(.43, 1));
    EXPECT_DOUBLE_LT(1, p.compute(.45, .12));
}

//Test Compute Method with negative values.
TEST(PIDControllerTest, testPIDControllerCompute)
{
	PIDController p = PIDController(1,2,.4,5,-3,-2);

    EXPECT_DOUBLE_EQ(1, p.compute(12.0, .4));
    EXPECT_DOUBLE_GT(0, p.compute(.45, -10));
    EXPECT_DOUBLE_GT(0, p.compute(.43, 1));
    EXPECT_DOUBLE_LT(1, p.compute(.45, .12));
}

//Test Compute Method with zero values.
TEST(PIDControllerTest, testPIDControllerCompute)
{
	PIDController p = PIDController(1,2,.4,0,0,0);

    EXPECT_DOUBLE_EQ(1, p.compute(12.0, .4));
    EXPECT_DOUBLE_GT(0, p.compute(.45, -10));
    EXPECT_DOUBLE_GT(0, p.compute(.43, 1));
    EXPECT_DOUBLE_LT(1, p.compute(.45, .12));
}

//Test Compute Method with Ki zero value.
TEST(PIDControllerTest, testPIDControllerCompute)
{
	PIDController p = PIDController(1,2,.4,2,3,0);

    EXPECT_DOUBLE_EQ(1, p.compute(12.0, .4));
    EXPECT_DOUBLE_GT(0, p.compute(.45, -10));
    EXPECT_DOUBLE_GT(0, p.compute(.43, 1));
    EXPECT_DOUBLE_LT(1, p.compute(.45, .12));
}
//Test Compute Method with Kd zero value.
TEST(PIDControllerTest, testPIDControllerCompute)
{
	PIDController p = PIDController(1,2,.4,2,0,2);

    EXPECT_DOUBLE_EQ(1, p.compute(12.0, .4));
    EXPECT_DOUBLE_GT(0, p.compute(.45, -10));
    EXPECT_DOUBLE_GT(0, p.compute(.43, 1));
    EXPECT_DOUBLE_LT(1, p.compute(.45, .12));
}
//Test Compute Method with Kp zero value.
TEST(PIDControllerTest, testPIDControllerInitialize)
{
	PIDController p = PIDController(1,2,.4,0,.3,2);

	EXPECT_DOUBLE_GT(0, p.getMin());
	EXPECT_DOUBLE_GT(0, p.getMax());
	EXPECT_DOUBLE_GT(0, p.getIntegral());
	EXPECT_DOUBLE_GT(0, p.getKi());
	EXPECT_DOUBLE_GT(0, p.getKd());
	EXPECT_DOUBLE_GT(0, p.getKp());
	EXPECT_DOUBLE_GT(0, p.getDt());
	EXPECT_DOUBLE_GT(0, p.getPre_Error());
}
