#include "gtest/gtest.h"

TEST(AssertionTests, expectEqTest) {
	int a = 0;
	EXPECT_EQ(a, 0);
}

TEST(AssertionTests, assertEqTest) {
	int a = 2;
	ASSERT_EQ(a, 2);
	ASSERT_LT(a, 5);
	ASSERT_GT(a, 1);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

