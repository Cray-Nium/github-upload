/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "irControl.h"
#include <lirc/lirc_client.h>
#include "globals.h"
#include "audioPlayback.h"

using namespace std;

static struct lirc_config* lirc_config;
static char* lirc_code;
static char* lirc_string;
static uint8_t irCode;

//Temp data structures
uint8_t menuLayer = 0;

void processAudioPlaybackInput(uint8_t irCode);
void processMenuInput(uint8_t irCode);


void* irThreadRun(void* param){
    while (true){
        irCode = getIrCode();
        if (menuLayer == 0){
            if (irCode == PUSH){
                menuLayer++;
            }
            else{
                processAudioPlaybackInput(irCode);
            }
        }
        else{
            processMenuInput(irCode);
        }
    }
}

bool irControlInit()
{
    if(lirc_init("mPi3", 1) == -1) return false;
    if(lirc_readconfig("/etc/lirc/mPi3_config.lircrc", &lirc_config, NULL)!=0) return false;
    
    return true;
}

void irControlCleanup()
{
    lirc_freeconfig(lirc_config);
    lirc_deinit();
}

uint8_t getIrCode()
{
    uint8_t retVal = 0x00;
    
    if ( (lirc_nextcode(&lirc_code) == 0) && (lirc_code != NULL) )
    {
        lirc_code2char (lirc_config, lirc_code, &lirc_string);
        if (lirc_string != NULL)
        {
            retVal = *lirc_string;
        }
    }
    
    return retVal;
}


void processAudioPlaybackInput(uint8_t irCode){
    switch (irCode){
        case FLICK_RIGHT:
            audioPlaybackMessages.push(COMMAND_NEXT_TRACK);
            break;
        case FLICK_LEFT:
            if (getTrackTime() > 2.0){
                audioPlaybackMessages.push(COMMAND_RESTART_TRACK);
            }
            else{
                audioPlaybackMessages.push(COMMAND_PREVIOUS_TRACK);
            }
            break;
        case CLOCKWISE:
            audioPlaybackMessages.push(COMMAND_VOLUME_UP);
            break;
        case COUNTER_CLOCKWISE:
            audioPlaybackMessages.push(COMMAND_VOLUME_DOWN);
            break;
        case BUTTON:
            audioPlaybackMessages.push(COMMAND_TOGGLE_PAUSE);
            break;
        default:
            break;
    }
}

void processMenuInput(uint8_t irCode){
    switch (irCode){
        case PULL:
            menuLayer--;
            break;
        default:
            break;
    }
}