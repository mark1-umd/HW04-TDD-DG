#include <gtest/gtest.h>
#include "../include/PIDController.h"


TEST(PIDControllerTest, testPIDControllerCompute)
{
	PIDController p = PIDController(1,2,.4,5,.3,2);

    EXPECT_EQ(1, p.compute(12.0, .4));
    EXPECT_GT(0, p.compute(.45, -10));
    EXPECT_GT(0, p.compute(.43, 1));
    EXPECT_LT(1, p.compute(.45, .12));
}

TEST(PIDControllerTest, testPIDControllerInitialize)
{
	PIDController p = PIDController(1,2,.4,-2,.3,2);

	EXPECT_GT(0, p.getMin());
	EXPECT_GT(0, p.getMax());
	EXPECT_GT(0, p.getIntegral());
	EXPECT_GT(0, p.getKi());
	EXPECT_GT(0, p.getKd());
	EXPECT_GT(0, p.getKp());
	EXPECT_GT(0, p.getDt());
	EXPECT_GT(0, p.getPre_Error());
}
