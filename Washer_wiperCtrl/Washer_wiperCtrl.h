// // #ifndef WASHER_WIPERCTRL_H
// // #define WASHER_WIPERCTRL_H
 
// // enum STATUS
// // {
// //     OK,
// //     NOK
// // };
 
// // enum VehicleMode
// // {
// //     OFF,
// //     ACC,
// //     ON,
// //     START
// // };
 
// // enum wiperRequest
// // {
// //     WIPER_OFF_REQUESTED,
// //     INTERMITTENT_WIPER_REQUESTED,
// //     LOW_WIPER_REQUESTED,
// //     HIGH_WIPER_REQUESTED
// // };
 
// // enum WasherRequest
// // {
// //     WASHER_OFF_REQUESTED,
// //     WASHER_ON_REQUESTED
// // };
 
// // enum washer_Cmd
// // {
// //     DEACTIVATE_WASHER,
// //     ACTIVATE_WASHER
// // };
// // enum wiper_Cmd
// // {
// //     DEACTIVATE,
// //     ACTIVATE_INTERMITTENT_WIPER,
// //     ACTIVATE_LOW_WIPER,
// //     ACTIVATE_HIGH_WIPER
// // };
 
// // enum wiperStatus
// // {
// //     NOT_ACTIVATED,
// //     ACTIVATED,
// //     INTERMITTENT_WIPER_ACTIVATED,
// //     LOW_WIPER_ACTIVATED,
// //     HIGH_WIPER_ACTIVATED,
// //     ALL_ACTIVATED,
// //     ERROR
// // };
 
 
// // extern void washer_wiper_MainFuntion(void);
// // extern void washer_wiper_InitFunction(void);
// // extern int washer_wiper_controlwipers(void);
// // extern int washer_wiper_controlwasher(void);
 
// // extern int washerrequest,wiperrequest;
// // extern int vehicleMode;
// // extern int washerrequest_old,wiperrequest_old,vehicleMode_old;
 
// // extern int washer_Cmd, wiper_Cmd;
 
// // #endif //WASHER_WIPER_Hctrl.h
 

// #ifndef WASHER_WIPERCTRL_H
// #define WASHER_WIPERCTRL_H

// // -----------------------------------------------------------------------------
// // Status Enum
// // -----------------------------------------------------------------------------

// enum STATUS
// {
//     OK,
//     NOK
// };

// // -----------------------------------------------------------------------------
// // Vehicle Modes
// // -----------------------------------------------------------------------------

// enum VehicleMode
// {
//     OFF,
//     ACC,
//     ON,
//     START
// };

// // -----------------------------------------------------------------------------
// // Wiper Requests
// // -----------------------------------------------------------------------------

// enum wiperRequest
// {
//     WIPER_OFF_REQUESTED,
//     INTERMITTENT_WIPER_REQUESTED,
//     LOW_WIPER_REQUESTED,
//     HIGH_WIPER_REQUESTED
// };

// // -----------------------------------------------------------------------------
// // Washer Requests
// // -----------------------------------------------------------------------------

// enum WasherRequest
// {
//     WASHER_OFF_REQUESTED,
//     WASHER_ON_REQUESTED
// };

// // -----------------------------------------------------------------------------
// // Washer Commands
// // -----------------------------------------------------------------------------

// enum washer_Cmd
// {
//     DEACTIVATE_WASHER,
//     ACTIVATE_WASHER
// };

// // -----------------------------------------------------------------------------
// // Wiper Commands
// // -----------------------------------------------------------------------------

// enum wiper_Cmd
// {
//     DEACTIVATE,
//     ACTIVATE_INTERMITTENT_WIPER,
//     ACTIVATE_LOW_WIPER,
//     ACTIVATE_HIGH_WIPER
// };

// // -----------------------------------------------------------------------------
// // Wiper Status
// // -----------------------------------------------------------------------------

// enum wiperStatus
// {
//     NOT_ACTIVATED,
//     ACTIVATED,
//     INTERMITTENT_WIPER_ACTIVATED,
//     LOW_WIPER_ACTIVATED,
//     HIGH_WIPER_ACTIVATED,
//     ALL_ACTIVATED,
//     ERROR
// };

// // -----------------------------------------------------------------------------
// // Function Declarations
// // -----------------------------------------------------------------------------

// extern void washer_wiper_MainFunction(void);

// extern void washer_wiper_InitFunction(void);

// extern int washer_wiper_controlwipers(void);

// extern int washer_wiper_controlwasher(void);

// // -----------------------------------------------------------------------------
// // Global Variables
// // -----------------------------------------------------------------------------

// extern int washerrequest;

// extern int wiperrequest;

// extern int vehicleMode;

// extern int washerrequest_old;

// extern int wiperrequest_old;

// extern int vehicleMode_old;

// extern int washer_Cmd;

// extern int wiper_Cmd;

// #endif // WASHER_WIPERCTRL_H

// #ifndef WASHER_HDLR_H
// #define WASHER_HDLR_H

// typedef enum
// {
//     WASHER_OFF,
//     WASHER_ON

// } washer_mode;

// // -----------------------------------------------------------------------------
// // Global Variable
// // -----------------------------------------------------------------------------

// extern washer_mode current_washer_mode;

// // -----------------------------------------------------------------------------
// // Function Declarations
// // -----------------------------------------------------------------------------

// extern void washer_Hdlr_MainFunction(void);

// extern int washer_Hdlr_ReadCmd(void);

// extern void washer_Hdlr_InitFun(void);

// #endif




#ifndef WASHER_WIPERCTRL_H
#define WASHER_WIPERCTRL_H

// --------------------------------------------------
// STATUS
// --------------------------------------------------

typedef enum
{
    OK,
    NOK

} STATUS;

// --------------------------------------------------
// VEHICLE MODE
// --------------------------------------------------

typedef enum
{
    OFF,
    ACC,
    ON,
    START

} VehicleMode;

// --------------------------------------------------
// WIPER REQUEST
// --------------------------------------------------

typedef enum
{
    WIPER_OFF_REQUESTED,
    INTERMITTENT_WIPER_REQUESTED,
    LOW_WIPER_REQUESTED,
    HIGH_WIPER_REQUESTED

} wiperRequest;

// --------------------------------------------------
// WASHER REQUEST
// --------------------------------------------------

typedef enum
{
    WASHER_OFF_REQUESTED,
    WASHER_ON_REQUESTED

} WasherRequest;

// --------------------------------------------------
// WASHER COMMAND
// --------------------------------------------------

typedef enum
{
    DEACTIVATE_WASHER,
    ACTIVATE_WASHER

} washer_cmd;

// --------------------------------------------------
// WIPER COMMAND
// --------------------------------------------------

typedef enum
{
    DEACTIVATE,
    ACTIVATE_INTERMITTENT_WIPER,
    ACTIVATE_LOW_WIPER,
    ACTIVATE_HIGH_WIPER

} wiper_cmd;

// --------------------------------------------------
// GLOBAL VARIABLES
// --------------------------------------------------

extern int washerrequest;
extern int wiperrequest;

extern int vehicleMode;

extern int washerrequest_old;
extern int wiperrequest_old;
extern int vehicleMode_old;

extern int washer_Cmd;
extern int wiper_Cmd;

// --------------------------------------------------
// FUNCTION DECLARATIONS
// --------------------------------------------------

void washer_wiper_MainFunction(void);

void washer_wiper_InitFunction(void);

int washer_wiper_controlwipers(void);

int washer_wiper_controlwasher(void);

#endif