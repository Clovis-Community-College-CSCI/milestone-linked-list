// Use driver.cc to test out your code. If you didn't know,
// gtest suite is on the server.
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

/*TEST(Example, GoodTests) {
    EXPECT_EQ(Example, What_you_are_expecting);
}
*/
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
