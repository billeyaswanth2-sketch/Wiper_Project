#ifndef WIPER_HDLR_H
#define WIPER_HDLR_H
 
typedef enum {
 
    INTERMITTENT_WIPER,
    LOW_WIPER,
    HIGH_WIPER,
    WIPER_OFF
} wiper_mode;
 
extern wiper_mode current_wiper_mode;
extern void wiper_Hdlr_MainFunction(void);
extern int wiper_Hdlr_ReadCmd(void);
extern void wiper_Hdlr_InitFun(void);
 
#endif // WIPER_HDLR_H