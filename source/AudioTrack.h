#ifndef AUDIOTRACK_H
#define AUDIOTRACK_H

#include <string>
#include "PlaylistEntry.h"

using namespace std;

class AudioTrack : public PlaylistEntry
{
private:
public:
    AudioTrack(string filepath = NULL, bool advancesAutomatically = true);
    string filepath;
};

#endif /* AUDIOTRACK_H */

