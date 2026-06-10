#ifndef RTE_H
#define RTE_H
 
#include "../washer_Hdlr/washer_Hdlr.h"
#include "../wiper_Hdlr/wiper_Hdlr.h"
 

 
extern void Rte_Write_Washer(washer_mode *wiperMode);
extern void Rte_Write_Intermittent(wiper_mode *wiperMode);
extern void Rte_Write_Low(wiper_mode *wiperMode);
extern void Rte_Write_High(wiper_mode *wiperMode);
 
#endif // RTE_H