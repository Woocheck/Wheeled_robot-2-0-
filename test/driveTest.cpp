#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../dcMotor/DCmotor.h"
#include "../wheelDrive/twoWheelDrive.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class TestingMotor: public DcMotor
{
    public:
        MOCK_METHOD1( control, void ( int speed ));
}

TEST( DriveTest, CallDcMotor )
{
    TestingMotor left( 11, 22, 11);
    TestingMotor right( 1, 2, 3 );

    TwoWheelDrive drive( std::make_shared<DcMotor>( left ), std::make_shared<DcMotor>( right ));

    EXPECT_CALL( left, comtrol( Ge( 0 ) )).Times(1);
    EXPECT_CALL( right, comtrol( Ge( 0 ) )).Times(1);

    

}

int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
