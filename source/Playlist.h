#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include "PlaylistEntry.h"

using namespace std;

class Playlist
{
private:
    
public:
    Playlist();
    vector<PlaylistEntry> entries;
    vector<PlaylistEntry>::iterator playbackIterator;
};

#endif /* PLAYLIST_H */

