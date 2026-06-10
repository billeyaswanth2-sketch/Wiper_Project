#include "../washer_wiperCtrl/washer_wiperCtrl.h"
#include "Wiper_Hdlr.h"
#include "../Rte/Rte.h"
 
wiper_mode current_wiper_mode = WIPER_OFF;
 
/* called every 5 ms */
void wiper_Hdlr_MainFunction(void)
{
    if (wiper_Hdlr_ReadCmd())
    {
        current_wiper_mode = WIPER_OFF;
    }
}
 
int wiper_Hdlr_ReadCmd(void)
{
    
    if (wiper_Cmd == ACTIVATE_INTERMITTENT_WIPER)
    {
        current_wiper_mode = INTERMITTENT_WIPER;
        Rte_Write_Intermittent(&current_wiper_mode);
 
        if (wiper_Cmd == ACTIVATE_INTERMITTENT_WIPER)
        {
            Rte_Write_Intermittent(&current_wiper_mode);
        }
 
        return 0;
    }
    if (wiper_Cmd == ACTIVATE_LOW_WIPER)
    {
        current_wiper_mode = LOW_WIPER;
        Rte_Write_Low(&current_wiper_mode);
 
        if (wiper_Cmd == LOW_WIPER)
        {
            Rte_Write_Low(&current_wiper_mode);
        }
 
        return 0;
    }
    if (wiper_Cmd == ACTIVATE_HIGH_WIPER)
    {
        current_wiper_mode = HIGH_WIPER;
        Rte_Write_High(&current_wiper_mode);
 
        if (wiper_Cmd == HIGH_WIPER)
        {
            Rte_Write_High(&current_wiper_mode);
        }
 
        return 0;
    }
    return 1;
}
 
void wiper_Hdlr_InitFun(void)
{
    current_wiper_mode = WIPER_OFF;
}