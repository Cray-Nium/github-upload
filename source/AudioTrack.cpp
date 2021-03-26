/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AudioTrack.h"
#include "PlaylistEntry.h"


AudioTrack::AudioTrack(string filepath, bool advancesAutomatically)
{
    this->filepath = filepath;
    this->advancesAutomatically = advancesAutomatically;
}