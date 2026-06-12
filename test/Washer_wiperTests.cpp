#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Washer_wiperTests_mock.hpp"
#include "Washer_wiperTests.hpp"

extern "C"
{
    #include "../Washer_wiperCtrl/washer_wiperCtrl.h"
    #include "../Washer_Hdlr/Washer_Hdlr.h"
    #include "../Wiper_Hdlr/Wiper_Hdlr.h"
}

using ::testing::Return;
using ::testing::StrictMock;

// -----------------------------------------------------------------------------
// Global Variables
// -----------------------------------------------------------------------------

MockComLayer* mock_com = nullptr;

wiper_mode value = WIPER_OFF;

// -----------------------------------------------------------------------------
// Mocked C Functions
// -----------------------------------------------------------------------------

extern "C"

{

int Com_ReadVehicleMode()
{
    if (mock_com != nullptr)
    {
        return mock_com->Com_ReadVehicleMode();
    }

    return OFF;
}

int Com_ReadwiperRequest()
{
    if (mock_com != nullptr)
    {
        return mock_com->Com_ReadwiperRequest();
    }

    return WIPER_OFF_REQUESTED;
}

int Com_ReadwasherRequest()
{
    if (mock_com != nullptr)
    {
        return mock_com->Com_ReadwasherRequest();
    }

    return WASHER_OFF_REQUESTED;
}

void Rte_Write_Washer(wiper_mode* ptr)
{
    value = *ptr;
}

void Rte_Write_Intermittent(wiper_mode* ptr)
{
    value = *ptr;
}

void Rte_Write_Low(wiper_mode* ptr)
{
    value = *ptr;
}

void Rte_Write_High(wiper_mode* ptr)
{
    value = *ptr;
}

}

// -----------------------------------------------------------------------------
// Test Fixture
// -----------------------------------------------------------------------------

class WasherWiperTest : public testing::Test
{
protected:

    StrictMock<MockComLayer> mock;

    void SetUp() override
    {
        mock_com = &mock;

        value = WIPER_OFF;

        washer_wiper_InitFunction();
    }

    void TearDown() override
    {
        mock_com = nullptr;
    }
};

// -----------------------------------------------------------------------------
// Test Cases
// -----------------------------------------------------------------------------

TEST_F(WasherWiperTest, WiperOffMode)
{
    EXPECT_CALL(mock, Com_ReadVehicleMode())
        .WillOnce(Return(ACC));

    EXPECT_CALL(mock, Com_ReadwiperRequest())
        .WillOnce(Return(WIPER_OFF_REQUESTED));

    EXPECT_CALL(mock, Com_ReadwasherRequest())
        .WillOnce(Return(WASHER_OFF_REQUESTED));

    washer_wiper_MainFunction();

    EXPECT_EQ(value, WIPER_OFF);
}

// -----------------------------------------------------------------------------

TEST_F(WasherWiperTest, IntermittentMode)
{
    EXPECT_CALL(mock, Com_ReadVehicleMode())
        .WillOnce(Return(ACC));

    EXPECT_CALL(mock, Com_ReadwiperRequest())
        .WillOnce(Return(INTERMITTENT_WIPER_REQUESTED));

    EXPECT_CALL(mock, Com_ReadwasherRequest())
        .WillOnce(Return(WASHER_OFF_REQUESTED));

    washer_wiper_MainFunction();

    EXPECT_EQ(value, INTERMITTENT_WIPER);
}

// -----------------------------------------------------------------------------

TEST_F(WasherWiperTest, LowWiperMode)
{
    EXPECT_CALL(mock, Com_ReadVehicleMode())
        .WillOnce(Return(ACC));

    EXPECT_CALL(mock, Com_ReadwiperRequest())
        .WillOnce(Return(LOW_WIPER_REQUESTED));

    EXPECT_CALL(mock, Com_ReadwasherRequest())
        .WillOnce(Return(WASHER_OFF_REQUESTED));

    washer_wiper_MainFunction();

    EXPECT_EQ(value, LOW_WIPER);
}

// -----------------------------------------------------------------------------

TEST_F(WasherWiperTest, HighWiperMode)
{
    EXPECT_CALL(mock, Com_ReadVehicleMode())
        .WillOnce(Return(ACC));

    EXPECT_CALL(mock, Com_ReadwiperRequest())
        .WillOnce(Return(HIGH_WIPER_REQUESTED));

    EXPECT_CALL(mock, Com_ReadwasherRequest())
        .WillOnce(Return(WASHER_OFF_REQUESTED));

    washer_wiper_MainFunction();

    EXPECT_EQ(value, HIGH_WIPER);
}

// -----------------------------------------------------------------------------

TEST_F(WasherWiperTest, VehicleModeOff)
{
    EXPECT_CALL(mock, Com_ReadVehicleMode())
        .WillOnce(Return(OFF));

    EXPECT_CALL(mock, Com_ReadwiperRequest())
        .WillOnce(Return(WIPER_OFF_REQUESTED));

    EXPECT_CALL(mock, Com_ReadwasherRequest())
        .WillOnce(Return(WASHER_OFF_REQUESTED));

    washer_wiper_MainFunction();

    EXPECT_EQ(value, WIPER_OFF);
}

// -----------------------------------------------------------------------------

TEST_F(WasherWiperTest, WasherOnRequest)
{
    EXPECT_CALL(mock, Com_ReadVehicleMode())
        .WillOnce(Return(ACC));

    EXPECT_CALL(mock, Com_ReadwiperRequest())
        .WillOnce(Return(LOW_WIPER_REQUESTED));

    EXPECT_CALL(mock, Com_ReadwasherRequest())
        .WillOnce(Return(WASHER_ON_REQUESTED));

    washer_wiper_MainFunction();

    EXPECT_EQ(value, LOW_WIPER);
}

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
