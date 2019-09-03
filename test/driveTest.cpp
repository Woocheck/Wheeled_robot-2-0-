#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../dcMotor/DCmotor.h"
#include "../wheelDrive/twoWheelDrive.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class TestingMotor: public Engine
{
    public:
        MOCK_METHOD1( control, void ( int demandedSpeed ));
};

TEST( DriveTest, CallDcMotor )
{
    TestingMotor left(_);
    TestingMotor right(_);

    TwoWheelDrive drive( std::make_shared<Engine>( left ), std::make_shared<Engine>( right ));

    EXPECT_CALL( left, control( testing::Ge( 0 ) )).Times(1);
    EXPECT_CALL( right, control( testing::Ge( 0 ) )).Times(1);

    

}

int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
