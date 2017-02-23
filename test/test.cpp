#include <gtest/gtest.h>
#include "../include/PIDController.h"

//Test Compute Method with non-zero positive values
TEST(PIDControllerTest, testPIDControllerComputeNonZeroPositive)
{
	PIDController p = PIDController(1,2,.4,5,.3,2);

  /* These original DGellman tests were modified by MJenkins after
   * consultation with DGellman.  Inequality direction accidentally
   * specified backwards in original tests.
   * Change made by MJenkins 2017-02-22
   *
   *  EXPECT_GT(0, p.compute(12.0, .4));
   *  EXPECT_GT(0, p.compute(.45, 10));
   *  EXPECT_GT(0, p.compute(.43, 1));
   *  EXPECT_GT(0, p.compute(.45, .12));
   */
  EXPECT_LT(0, p.compute(12.0, .4));
  EXPECT_LT(0, p.compute(.45, 10));
  EXPECT_LT(0, p.compute(.43, 1));
  EXPECT_LT(0, p.compute(.45, .12));
}

//Test Compute Method with negative values.
TEST(PIDControllerTest, testPIDControllerComputeNegativeValues)
{
	PIDController p = PIDController(1,2,.4,5,-3,-2);

  /* These original DGellman tests were modified by MJenkins after
   * consultation with DGellman.  Inequality direction accidentally
   * specified backwards in original tests.
   * Change made by MJenkins 2017-02-22
   *
   *  EXPECT_GT(0, p.compute(12.0, .4));
   *  EXPECT_GT(0, p.compute(.45, -10));
   *  EXPECT_GT(0, p.compute(.43, 1));
   *  EXPECT_GE(0, p.compute(.45, .12));
   */
  EXPECT_LT(0, p.compute(12.0, .4));
  EXPECT_LT(0, p.compute(.45, -10));
  EXPECT_LT(0, p.compute(.43, 1));
  EXPECT_LE(0, p.compute(.45, .12));
}

//Test Compute Method with zero values.
TEST(PIDControllerTest, testPIDControllerComputeZeroValues)
{
	PIDController p = PIDController(1,2,.4,0,0,0);

    EXPECT_LE(0, p.compute(12.0, .4));
    EXPECT_LE(0, p.compute(.45, -10));
    EXPECT_LE(0, p.compute(.43, 1));
    EXPECT_LT(0, p.compute(.45, .12));
}

//Test Compute Method with Ki zero value.
TEST(PIDControllerTest, testPIDControllerComputeKiZero)
{
	PIDController p = PIDController(1,2,.4,2,3,0);

    EXPECT_LE(0, p.compute(12.0, .4));
    EXPECT_LE(0, p.compute(.45, -10));
    EXPECT_LE(0, p.compute(.43, 1));
    EXPECT_LE(0, p.compute(.45, .12));
}
//Test Compute Method with Kd zero value.
TEST(PIDControllerTest, testPIDControllerComputeKdZero)
{
	PIDController p = PIDController(1,2,.4,2,0,2);

    EXPECT_LE(0, p.compute(12.0, .4));
    EXPECT_LE(0, p.compute(.45, -10));
    EXPECT_LE(0, p.compute(.43, 1));
    EXPECT_LT(0, p.compute(.45, .12));
}
//Test Compute Method with Kp zero value.
TEST(PIDControllerTest, testPIDControllerComputeKpZero)
{
	PIDController p = PIDController(1,2,.4,0,1,2);

    EXPECT_LE(0, p.compute(12.0, .4));
    EXPECT_LE(0, p.compute(.45, -10));
    EXPECT_LE(0, p.compute(.43, 1));
    EXPECT_LE(0, p.compute(.45, .12));
}

//Test Initialization Method.
TEST(PIDControllerTest, testPIDControllerInitialize)
{
	PIDController p = PIDController(1,2,.4,3,.3,2);

	EXPECT_DOUBLE_EQ(.4, p.getMin());
	EXPECT_DOUBLE_EQ(2, p.getMax());
	EXPECT_DOUBLE_EQ(0, p.getIntegral());
	EXPECT_DOUBLE_EQ(2, p.getKi());
	EXPECT_DOUBLE_EQ(.3, p.getKd());
	EXPECT_DOUBLE_EQ(3, p.getKp());
	EXPECT_DOUBLE_EQ(1, p.getDt());
	EXPECT_DOUBLE_EQ(0, p.getPre_Error());
}
