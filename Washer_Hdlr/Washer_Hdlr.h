#ifndef WASHER_HDLR_H
#define WASHER_HDLR_H

// -----------------------------------------------------------------------------
// Washer Mode Enum
// -----------------------------------------------------------------------------

typedef enum
{
    WASHER_OFF = 0,
    WASHER_ON

} washer_mode;

// -----------------------------------------------------------------------------
// Global Variable Declaration
// -----------------------------------------------------------------------------

extern washer_mode current_washer_mode;

// -----------------------------------------------------------------------------
// Function Declarations
// -----------------------------------------------------------------------------

void washer_Hdlr_MainFunction(void);

int washer_Hdlr_ReadCmd(void);

void washer_Hdlr_InitFun(void);

#endif // WASHER_HDLR_H