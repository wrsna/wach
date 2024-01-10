


#ifndef BORD_H_INCLUDE
#define BORD_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#define D1 PIO_PD7
#define D2 PIO_PC29
#define D3 PIO_PC21
#define D4 PIO_PC22

#define T1 PIO_PC23
#define T2 PIO_PC24
#define T3 PIO_PC25
#define T4 PIO_PC26

#define Mask_T1  1<<0
#define Mask_T2  1<<1
#define Mask_T3  1<<2
#define Mask_T4  1<<3



#define POT PIO_PA16
#define POT_ADC ADC_CHANNEL_7

#include<asf.h>


void bord_init(void);
int get_button_press(void);
int get_button_state(void);

void adc_setup(void);
uint32_t adc_read(void);

void timer_init(void);



#endif  //BORD_H_INCLUDE

#ifdef __cplusplus
}
#endif
