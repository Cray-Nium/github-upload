/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   audioPlayback.h
 * Author: NEON
 *
 * Created on August 9, 2018, 7:03 PM
 */

#ifndef AUDIOPLAYBACK_H
#define AUDIOPLAYBACK_H

#ifdef __cplusplus
extern "C" {
#endif

#define VOLUME_INCREMENT   0.1
    
void* audioThreadRun(void* param);
bool audioPlaybackInit();
void audioPlaybackCleanup();

double getTrackLength();
double getTrackTime();

#ifdef __cplusplus
}
#endif

#endif /* AUDIOPLAYBACK_H */

