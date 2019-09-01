
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <wiringPi.h>
#include "../lineDetector/detector.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class MockWiringPi: public testing::Test
{
    MOCK_METHOD1( digitalRead , int ( int pin ));
};

TEST( LineDetector, PositionReading )
{

}

int main(int argc, char** argv) 
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
