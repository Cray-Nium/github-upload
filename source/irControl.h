/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   irControl.h
 * Author: NEON
 *
 * Created on August 8, 2018, 11:05 PM
 */

#ifndef IRCONTROL_H
#define IRCONTROL_H

#include "globals.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BUTTON             0x50  // P
#define FLICK_UP           0x5E  // ^
#define FLICK_DOWN         0x76  // v
#define FLICK_LEFT         0x3C  // <
#define FLICK_RIGHT        0x3E  // >
#define PUSH               0x78  // x
#define PULL               0x6F  // o
#define CLOCKWISE          0x43  // C
#define COUNTER_CLOCKWISE  0x41  // A
#define TAP_TOP            0x54  // T
#define TAP_LEFT           0x4C  // L
#define TAP_BOTTOM         0x42  // B
#define TAP_RIGHT          0x52  // R

void* irThreadRun(void* param);
bool irControlInit();
void irControlCleanup();

uint8_t getIrCode();


#ifdef __cplusplus
}
#endif

#endif /* IRCONTROL_H */

