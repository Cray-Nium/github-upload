/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PlaylistEntry.h"


PlaylistEntry::PlaylistEntry(const unsigned int& audioTrackKey, const bool& advancesAutomatically)
{
    this->audioTrackKey = audioTrackKey;
    this->advancesAutomatically = advancesAutomatically;
}