#include<rtos_task.h>

#ifdef __cplusplus
extern "C" {
#endif

rtos_task_t task_lcd = {
    .last_tick = 0,
    .name = "LCD",
    .driver = lcd_driver

};


rtos_task_t task_ura = {
    .last_tick = 0,
    .name = "URA",
    .driver = ura_driver
};


rtos_task_t task_calc = {
    .last_tick = 0,
    .name = "CALC",
    .driver = calc_driver
};


rtos_task_t task_tipke = {
    .last_tick = 0,
    .name = "TIPKE",
    .driver = buttons_driver
};

/*********************************************************************/

















uint32_t clk = 0;
void ura_driver(void){

    clk++;

    if(clk > DAN){
        clk = clk-DAN;
    }
}


void calc_driver(void){
    int sec, min, ure, n;

    sec = clk/10;
    min = sec/60;
    ure = min/60;

    sec = sec%60;
    min = min%60;

    n = sprintf(lcd_string,"ura: %2d:%2d:%2d",ure,min,sec);
    lcd_string[n] = ' ';
}


void buttons_driver(void){
    int butons = 0;
    bool  hold = 0;

    butons = get_button_press();

    if(butons & Mask_T1){
        clk = clk + URA;
    }
    if(butons & Mask_T2){
        clk = clk + MIN;
    }
    if(butons & Mask_T4){
        clk = 0;
    }

    hold = get_button_state() ^ 0xF;

    if(hold && clk>0){
        clk--;
    }
}






/******************************************************************************************************************************************************************/

rtos_task_t *task_list[] = {&task_ura, &task_tipke, &task_calc, &task_lcd, 0/*null__pointer*/}; //array od tega tipa sprem samo da so naslovi -> konstantna velikost








#ifdef __cplusplus
}
#endif
