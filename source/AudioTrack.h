#ifndef AUDIOTRACK_H
#define AUDIOTRACK_H

#include <string>

using namespace std;

class AudioTrack
{
private:
public:
    AudioTrack(string filepath = NULL);
    string filepath;
};

#endif /* AUDIOTRACK_H */

