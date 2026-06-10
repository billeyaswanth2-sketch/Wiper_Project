// #include "washer_wiperCtrl.h"
// #include "../washer_wiperCtrl/washer_wiperCtrl.h"
// #include "../Com/Com.h"
// #include "../Wiper_Hdlr/Wiper_Hdlr.h"
// #include "../Washer_Hdlr/Washer_Hdlr.h"
 
// // #include "../Variant/Variant.h"
 
// int washerrequest,wiperrequest;
// int vehicleMode;
// int washerrequest_old,wiperrequest_old,vehicleMode_old;
 
// int washer_Cmd, wiper_Cmd;
 
// static int washer_wiper_ReadInputs(void);
 
// static int washer_wiper_ReadInputs(void)
// {
//     int ret = OK;
 
//     vehicleMode = Com_ReadVehicleMode();
//     if(vehicleMode < OFF  || vehicleMode >START)
//     {
//         vehicleMode = vehicleMode_old;
//     }
 
//     wiperrequest = Com_ReadwiperRequest();
//     // if(wiperrequest < WIPER_OFF_REQUESTED || wiperrequest > INTERMITTENT_WIPER_REQUESTED)
//     // {
//     //     wiperrequest = wiperrequest_old;
//     // }
//     // else if(wiperrequest < WIPER_OFF_REQUESTED || wiperrequest > LOW_WIPER_REQUESTED)
//     // {
//     //     wiperrequest = wiperrequest_old;
//     // }
//    if(wiperrequest < WIPER_OFF_REQUESTED || wiperrequest > HIGH_WIPER_REQUESTED)
//     {
//         wiperrequest = wiperrequest_old;
//     }
 
//     washerrequest = com_ReadwasherRequest();
 
//     if(washerrequest < WASHER_OFF_REQUESTED || washerrequest > WASHER_ON_REQUESTED)
//     {
//         washerrequest = washerrequest_old;
//     }
//     return ret;
// }
 
 
// int washer_wiper_controlwashers(void)
// {
//     if (vehicleMode == ACC || vehicleMode == ON || vehicleMode == OFF || vehicleMode == START)
//     {
//         if(washerrequest == WASHER_ON_REQUESTED)
//         {
//             washer_Cmd = ACTIVATE_WASHER;
//         }
//         else
//         {
//             washer_Cmd = DEACTIVATE_WASHER;
 
//         }
//     }
//     return 0;
// }
 
// int washer_wiper_controlwipers(void)
// {
//     if (vehicleMode == ACC || vehicleMode == ON || vehicleMode == OFF || vehicleMode == START)
//     {
//         if(wiperrequest == INTERMITTENT_WIPER_REQUESTED)
//         {
//             wiper_Cmd = ACTIVATE_INTERMITTENT_WIPER;
//         }
//         else if(wiperrequest == LOW_WIPER_REQUESTED)
//         {
//             wiper_Cmd = ACTIVATE_LOW_WIPER;
//         }
//         else if(wiperrequest == HIGH_WIPER_REQUESTED)
//         {
//             wiper_Cmd = ACTIVATE_HIGH_WIPER;
//         }
//         else
//         {
//             wiper_Cmd = DEACTIVATE;
//         }
//     }
//     else
//     {
//         wiper_Cmd = DEACTIVATE;
//     }
//     return 0;
// }
 
// void washer_wiper_InitFunction(void)
// {
//     washerrequest = WASHER_OFF_REQUESTED;
//     wiperrequest = WIPER_OFF_REQUESTED;
//     washerrequest_old = WASHER_OFF_REQUESTED;
//     wiperrequest_old = WIPER_OFF_REQUESTED;
//     washer_Cmd = DEACTIVATE;
//     wiper_Cmd = ACTIVATED;
//     wiper_Hdlr_InitFun();
//     washer_Hdlr_Initfun();
// }
 
// void washer_wiper_MainFunction(void)
// {
//     washer_wiper_ReadInputs();
//     washer_wiper_controlwasher();
//     washer_wiper_controlwipers();
//     washer_wiper_MainFunction();
// }

// 


#include "washer_wiperCtrl.h"
#include "../Com/Com.h"
#include "../Wiper_Hdlr/Wiper_Hdlr.h"
#include "../Washer_Hdlr/Washer_Hdlr.h"

// -----------------------------------------------------------------------------
// Global Variables
// -----------------------------------------------------------------------------

int washerrequest, wiperrequest;

int vehicleMode;

int washerrequest_old, wiperrequest_old, vehicleMode_old;

int washer_Cmd, wiper_Cmd;

// -----------------------------------------------------------------------------
// Static Function Declaration
// -----------------------------------------------------------------------------

static int washer_wiper_ReadInputs(void);

// -----------------------------------------------------------------------------
// Read Inputs
// -----------------------------------------------------------------------------

static int washer_wiper_ReadInputs(void)
{
    int ret = OK;

    // -------------------------------------------------------------------------
    // Read Vehicle Mode
    // -------------------------------------------------------------------------

    vehicleMode = Com_ReadVehicleMode();

    if (vehicleMode < OFF || vehicleMode > START)
    {
        vehicleMode = vehicleMode_old;
    }
    else
    {
        vehicleMode_old = vehicleMode;
    }

    // -------------------------------------------------------------------------
    // Read Wiper Request
    // -------------------------------------------------------------------------

    wiperrequest = Com_ReadwiperRequest();

    if (wiperrequest < WIPER_OFF_REQUESTED ||
        wiperrequest > HIGH_WIPER_REQUESTED)
    {
        wiperrequest = wiperrequest_old;
    }
    else
    {
        wiperrequest_old = wiperrequest;
    }

    // -------------------------------------------------------------------------
    // Read Washer Request
    // -------------------------------------------------------------------------

    washerrequest = Com_ReadwasherRequest();

    if (washerrequest < WASHER_OFF_REQUESTED ||
        washerrequest > WASHER_ON_REQUESTED)
    {
        washerrequest = washerrequest_old;
    }
    else
    {
        washerrequest_old = washerrequest;
    }

    return ret;
}

// -----------------------------------------------------------------------------
// Washer Control
// -----------------------------------------------------------------------------

int washer_wiper_controlwasher(void)
{
    if ((vehicleMode == ACC) ||
        (vehicleMode == ON)  ||
        (vehicleMode == START))
    {
        if (washerrequest == WASHER_ON_REQUESTED)
        {
            washer_Cmd = ACTIVATE_WASHER;
        }
        else
        {
            washer_Cmd = DEACTIVATE_WASHER;
        }
    }
    else
    {
        washer_Cmd = DEACTIVATE_WASHER;
    }

    return OK;
}

// -----------------------------------------------------------------------------
// Wiper Control
// -----------------------------------------------------------------------------

int washer_wiper_controlwipers(void)
{
    if ((vehicleMode == ACC) ||
        (vehicleMode == ON)  ||
        (vehicleMode == START))
    {
        if (wiperrequest == INTERMITTENT_WIPER_REQUESTED)
        {
            wiper_Cmd = ACTIVATE_INTERMITTENT_WIPER;
        }
        else if (wiperrequest == LOW_WIPER_REQUESTED)
        {
            wiper_Cmd = ACTIVATE_LOW_WIPER;
        }
        else if (wiperrequest == HIGH_WIPER_REQUESTED)
        {
            wiper_Cmd = ACTIVATE_HIGH_WIPER;
        }
        else
        {
            wiper_Cmd = DEACTIVATE;
        }
    }
    else
    {
        wiper_Cmd = DEACTIVATE;
    }

    return OK;
}

// -----------------------------------------------------------------------------
// Initialization Function
// -----------------------------------------------------------------------------

void washer_wiper_InitFunction(void)
{
    washerrequest = WASHER_OFF_REQUESTED;

    wiperrequest = WIPER_OFF_REQUESTED;

    vehicleMode = OFF;

    washerrequest_old = WASHER_OFF_REQUESTED;

    wiperrequest_old = WIPER_OFF_REQUESTED;

    vehicleMode_old = OFF;

    washer_Cmd = DEACTIVATE_WASHER;

    wiper_Cmd = DEACTIVATE;

    wiper_Hdlr_InitFun();

    washer_Hdlr_InitFun();
}

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------

void washer_wiper_MainFunction(void)
{
    washer_wiper_ReadInputs();

    washer_wiper_controlwasher();

    washer_wiper_controlwipers();

    wiper_Hdlr_MainFunction();

    washer_Hdlr_MainFunction();
}