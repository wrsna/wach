#include <asf.h>
#include"lcd.h"
#include"bord.h"
// ali je že uključen v tasks ja #include<rtos.h>//jedro sistem definiri nastavitve in sproži
#include<rtos_task.h>//sprogramiran sistem

#ifdef __cplusplus
extern "C" {
#endif


//global variables


int main (void){
    /* sets the processor clock according to conf_clock.h definitions */
    sysclk_init();

    /* disable wathcdog */
    WDT->WDT_MR = WDT_MR_WDDIS;

    /********************* HW init     ***************************/
    ioport_init();
    delay_init();
    lcd_init();
    bord_init();

    NVIC_EnableIRQ(SysTick_IRQn);
    /**RTOS**/
    if(rtos_init(25000) != 0){
        while(1);
    }//napaka rezina predolga za števec števec se bo obrnu napaka da operacija uzame preveč čase je drugje
    rtos_enable();


    /********************* Main loop     ***************************/
    while(1){


    }
}




#ifdef __cplusplus
}
#endif
