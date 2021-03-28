#ifndef AUDIOLIBRARY_H
#define AUDIOLIBRARY_H

#include <map>
#include <string>
#include <utility>
#include "AudioTrack.h"

using namespace std;

typedef pair<unsigned int, bool> audioLibraryReturnPair;

class AudioLibrary
{
private:
    unsigned int nextKey = 0;
public:
    map<unsigned int, AudioTrack> tracks;
    
    audioLibraryReturnPair addTrack(const string& filepath);
};

#endif /* AUDIOLIBRARY_H */

