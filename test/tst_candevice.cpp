#include <gtest/gtest.h>
#include "../src/candevice.hpp"

// Demonstrate some basic assertions.
TEST(CanDeviceTest, ConstructorTest)
{
  // execute script to create virtual can
  // TODO
  EXPECT_NO_THROW(CanDevice("vcan0"));
  EXPECT_ANY_THROW(CanDevice("non-existant"));
  EXPECT_ANY_THROW(CanDevice("invalid name"));
  EXPECT_ANY_THROW(CanDevice(""));

  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

