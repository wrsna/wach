#ifndef RTOS_TASK_H_INCLUDED
#define RTOS_TASK_H_INCLUDED



#ifdef __cplusplus
extern "C" {
#endif


#include<rtos.h>
#include<lcd.h>
#include<bord.h>

#define DAN 24*60*60*10
#define URA 1*60*60*10
#define MIN 1*60*10






void ura_driver(void);
void calc_driver(void);
void buttons_driver(void);















#endif // RTOS_TASK_H_INCLUDED

#ifdef __cplusplus
}
#endif
