/**
 * Pin Definitions for MacroPad Key Matrix, Rotary Encoder & OLED
 *
 * @file pins.h
 */
#ifndef PINS_H
#define PINS_H

/*  Key Matrix Pins  */ 
#define col_1 D9
#define col_2 D10
#define row_1 D1
#define row_2 D0

/*  Rotary Encoder Pins  */
#define input_a D7
#define input_b D8
#define encoder_pin D6 

/*  Deep Sleep Timeout (5 minutes in ms)  */
#define sleep_timeout 300000

#endif
