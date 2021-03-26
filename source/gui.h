/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gui.h
 * Author: NEON
 *
 * Created on September 5, 2018, 8:22 PM
 */

#ifndef GUI_H
#define GUI_H

#ifdef __cplusplus
extern "C" {
#endif

void* guiThreadRun(void* param);
bool guiInit();
void guiCleanup();

#ifdef __cplusplus
}
#endif

#endif /* GUI_H */

