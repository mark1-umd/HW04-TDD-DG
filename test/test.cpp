#include <gtest/gtest.h>
#include "PIDController.h"


TEST(PIDControllerTest, testPIDControllerCompute)
{
	PIDController p = PIDController(1,2,.4,5,.3,2);

    EXPECT_EQ(1, p.compute(12.0, .4));
    EXPECT_GT(0, p.compute(.45, 10));
    EXPECT_LT(1, p.compute(.45, .12))
}
